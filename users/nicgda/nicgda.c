#include "nicgda.h"
#include "raw_hid.h"

// GMMK Pro
//   RGB_MATRIX_ENABLE = yes
//   ENCODER_ENABLE = yes
// Idobao ID80 V2
//   RGBLIGHT_ENABLE = yes  # Underglow
//   BACKLIGHT_ENABLE = yes # Key leds


//////////////////////////////////////
// EEPROM user data, 32 bits only :o(
//
typedef union {
  uint32_t raw;
  struct {
    uint8_t hue :8;
    uint8_t sat :4;
    uint8_t val :4;
  };
} user_config_t;

user_config_t user_config;


/////////////////////////////////////////
// Nic mode: Side leds (and F17/F18 on enable/disable)
//
bool nic_mode = false;
uint8_t nic_hue = 0;
uint8_t nic_sat = 255;
uint8_t nic_val = 255;
bool nic_matrix_was_enabled = false;


#if defined(RGB_MATRIX_ENABLE) | defined(RGBLIGHT_ENABLE)
// RGB Support

void set_nic_mode(bool on) {
    if(on) {
#if defined(RGB_MATRIX_ENABLE)
        if(!nic_mode) {
            nic_matrix_was_enabled = rgb_matrix_is_enabled();
        }
        rgb_matrix_enable();
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv_noeeprom(HSV_OFF);
#elif defined(RGBLIGHT_ENABLE)
        if(!nic_mode) {
            nic_matrix_was_enabled = rgblight_is_enabled();
        }
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // No need to change the colour here, I guess.
#endif
        nic_mode = true;
    } else {
        if(nic_mode) {
            if(!nic_matrix_was_enabled) {
#if defined(RGB_MATRIX_ENABLE)
                rgb_matrix_disable();
#elif defined(RGBLIGHT_ENABLE)
                rgblight_disable();
#endif
            }
        }
        nic_mode = false;
    }
}

void save_nic_mode(void) {
    user_config.hue = nic_hue;
    user_config.sat = nic_sat >> 4;
    user_config.val = nic_val >> 4;
    eeconfig_update_user(user_config.raw);
}

#else
// No RGB
#define set_nic_mode(on) (nic_mode = on)
#define save_nic_mode()

#endif

// QMK: Process key events
// Returns true if the event needs to be process by the default handler.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_NTGL:
            if (record->event.pressed) {
                set_nic_mode(!nic_mode);
                if(nic_mode) {
                    register_code(KC_F17);
                } else {
                    register_code(KC_F18);
                }
            } else {
                if(nic_mode) {
                    unregister_code(KC_F17);
                } else {
                    unregister_code(KC_F18);
                }
            }
            return false;
        case KC_NSAV:
            if (record->event.pressed) {
                save_nic_mode();
            }
            return false;
        case KC_F17:
            if (record->event.pressed) {
                set_nic_mode(true);
            }
            return true;
        case KC_F18:
            if (record->event.pressed) {
                set_nic_mode(false);
            }
            return true;
        default:
            return true; /* Process all other keycodes normally */
    }
}


// QMK: Handle hid command
void raw_hid_receive(uint8_t *data, uint8_t length) {
    if((3 < length) && (0 == memcmp("NIC", data, 3))) {
        switch(data[3]) {
            case HNC_ON:
                set_nic_mode(true);
                break;
            case HNC_OFF:
                set_nic_mode(false);
                break;
            case HNC_SET:
                if(7 <= length) {
                    nic_hue = data[4];
                    nic_sat = data[5];
                    nic_val = data[6];
                }
                break;
            case HNC_GET:
                if(7 <= length) {
                    data[4] = nic_hue;
                    data[5] = nic_sat;
                    data[6] = nic_val;
                }
                break;
            case HNC_SAVE:
                save_nic_mode();
                break;
        }
    }
    raw_hid_send(data, length);
}

#if defined(RGB_MATRIX_ENABLE) | defined(RGBLIGHT_ENABLE)
// QMK: Handle RBG Matrix update
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#if defined(RGB_MATRIX_ENABLE) // Eventually also LED_MATRIX_ENABLE
    uint8_t layer = biton32(layer_state);
    if(layer > 0) {
        //We go through rows and columns because we wan't to see if the key has been assigned on this layer.
        for(uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for(uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if(
                    index >= led_min  // in range
                    && index < led_max
                    && index != NO_LED // with led at that position
                    && (g_led_config.flags[index] & LED_FLAG_KEYLIGHT)  // for a key led
                    && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS  // with specific key on layer
                ) {
                    if(1 == layer) {
                        rgb_matrix_set_color(index, RGB_BLUE);
                    } else {
                        rgb_matrix_set_color(index, RGB_GREEN);
                    }
                }
            }
        }
    }
#endif // RGB_MATRIX_ENABLE

    if(nic_mode) {
        // Set side leds.
        HSV hsv = {nic_hue, nic_sat, nic_val};
        RGB rgb = hsv_to_rgb(hsv);
#if defined(RGB_MATRIX_ENABLE)
        for (uint8_t index = led_min; index < led_max; index++) {
            if (g_led_config.flags[index] & LED_FLAG_UNDERGLOW) {
                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
            }
        }
#elif defined(RGBLIGHT_ENABLE)
        rgblight_setrgb(rgb.r, rgb.g, rgb.b);
#endif
    }
    return false;
}
#endif // RGB support



// QMK: Post init customization
void keyboard_post_init_user(void) {
#if defined(RGB_MATRIX_ENABLE)
    // Needed for the GMMK Pro, to have the leds off.
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(HSV_OFF);
#endif

    user_config.raw = eeconfig_read_user();
    nic_hue = user_config.hue;
    nic_sat = user_config.sat << 4;
    if(nic_sat) {
        nic_sat |= 0xF;
    }
    nic_val = user_config.val << 4;
    if(nic_val) {
        nic_val |= 0xF;
    }
}


#ifdef ENCODER_ENABLE
//
void encoder_action_hsv_change(bool clockwise, uint8_t hue, uint8_t sat, uint8_t val) {
     if (clockwise) {
        nic_hue += hue;
        if(((nic_sat + sat) & 0xFF) > nic_sat) nic_sat += sat;
        if(((nic_val + val) & 0xFF) > nic_val) nic_val += val;
     } else {
        nic_hue -= hue;
        if(((nic_sat - sat) & 0xFF) < nic_sat) nic_sat -= sat;
        if(((nic_val - val) & 0xFF) < nic_val) nic_val -= val;
     }
 }


/*
 * Encoder behaviour.
 * Return false to prevent default behaviour.
 * If true, the encoder will do a volume up/down over
 * the current code.
 *
 * index: The encoder id
 */
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state;
    switch(biton32(layer_state)) {
        case 2:
        case 1:
            mods_state = get_mods();
            if(mods_state & MOD_BIT(KC_LCTL)) {
                encoder_action_hsv_change(clockwise, 2, 0, 0); // Hue change
            } else if (mods_state & MOD_BIT(KC_LSFT)) {
                encoder_action_hsv_change(clockwise, 0, 2, 0); // Saturation change
            } else if (mods_state & MOD_BIT(KC_LALT)) {
                encoder_action_hsv_change(clockwise, 0, 0, 2); // Value/Brightness change
            } else {
                // No mod
                if (clockwise) {
                    //tap_code(KC_KP_PLUS);  // Keypad plus
                    tap_code(KC_MS_WH_DOWN);  // Mouse wheel down

                } else {
                    //tap_code(KC_KP_MINUS);  // Keypad minus
                    tap_code(KC_MS_WH_UP);  // Mouse wheel up
                }
            }
            break;
        default:
            if (get_mods() & MOD_BIT(KC_LCTL)) {
                if (clockwise) {
                    tap_code(KC_MS_WH_DOWN);  // Mouse wheel down
                } else {
                    tap_code(KC_MS_WH_UP);  // Mouse wheel up
                }
            } else {
                if (clockwise) {
                    tap_code(KC_VOLU);  // Volume up
                } else {
                    tap_code(KC_VOLD);  // Volume down
                }
            }
            break;
    }
    return false;  // To prevent the default behaviour
}
#endif // ENCODER_ENABLE
