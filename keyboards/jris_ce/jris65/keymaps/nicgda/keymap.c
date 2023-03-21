/*******************************************************************
 * ,--.   ,--.  ,---.  ,------. ,--.  ,--.,--.,--.  ,--. ,----.    *
 * |  |   |  | /  O  \ |  .--. '|  ,'.|  ||  ||  ,'.|  |'  .-./    *
 * |  |.'.|  ||  .-.  ||  '--'.'|  |' '  ||  ||  |' '  ||  | .---. *
 * |   ,'.   ||  | |  ||  |\  \ |  | `   ||  ||  | `   |'  '--'  | *
 * '--'   '--'`--' `--'`--' '--'`--'  `--'`--'`--'  `--' `------'  *
 *                                                                 *
 * This code was not provided, supported nor endorsed by Irislab.  *
 * This is a community project to let jris65 owner easily use QMK  *
 * on their keyboards, as intended when they bought it.            *
 *******************************************************************/
#include "nicgda.h"

/* Keymap
        `        1        2        3        4        5        6        7        8        9        0         -       =        BackSpc  Del
        Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \        PgUp
        Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter    PgDn
        Sh_L              Z        X        C        V        B        N        M        ,        .        /        Sh_R     Up       MO(1)
        Ct_L     GUI_L    Alt_L                               SPACE                      Atl_R    MO(2)             Left     Down     Right
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_65_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, MO(1),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_HYPR, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   MO(1),
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                    KC_RGUI, MO(2),          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  SGUI(KC_4),_______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_END,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______,
        _______, _______, _______,                            XXXXXXX,                   _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [2] = LAYOUT_65_ansi(
        KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_F16,  XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_NTGL, XXXXXXX,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______,                            XXXXXXX,                   _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

