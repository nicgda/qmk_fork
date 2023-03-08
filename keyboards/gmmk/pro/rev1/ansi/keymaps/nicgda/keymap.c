#include "nicgda.h"


/******************************************************************************************************************************************
 *  Documentation
 *
 * HID values
 * -----------------
 *  vid = 0x320F
 *  pid = 0x5044
 *  usage_id = 0x61
 *  page_id = 0xFF60
 *
 *
 * Keymap
 * -----------------
 *      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      Del      Rotary
 *      ~        1        2        3        4        5        6        7        8        9        0         -       (=)      BackSpc  Home
 *      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \        PgUp
 *      Caps     A        S        D        F        G        H        J        K        L        ;        '                 Enter    PgDn
 *      Sh_L     Z        X        C        V        B        N        M        ,        .        /                 Sh_R     Up       End
 *      Ct_L     Alt_L    Mac_L                      SPACE                      Mac_R    MO(1)             MO(2)    Left     Down     Right
 ******************************************************************************************************************************************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        // Base layer
        KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_F16,  RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  MO(1),
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_HYPR, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                    KC_RGUI, MO(1),            MO(2),   KC_LEFT, KC_DOWN, KC_RGHT
        ),
	[1] = LAYOUT(
        // Alt functions
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  SGUI(KC_4),_______,
        XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_PMNS, KC_PPLS, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______, XXXXXXX,
        _______, _______, _______,                   XXXXXXX,                   _______, _______,          _______, _______, _______, _______
        ),
    [2] = LAYOUT(
        // UI functions
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NSAV,          KC_NTGL, XXXXXXX,
        XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, NK_TOGG, XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT,          XXXXXXX, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                   XXXXXXX, _______,          _______, _______, _______, _______
        ),
};


//////////////////////////////////////////////////////////
// RGB LED layout

//  Key leds
//         0        6        12       18       23       28       34       39       44       50       56       61       66       69       xx
//         1        7        13       19       24       29       35       40       45       51       57       62       78       85       72
//         2        8        14       20       25       30       36       41       46       52       58       63       89       93       75
//         3        9        15       21       26       31       37       42       47       53       59       64                96       86
//         4        10       16       22       27       32       38       43       48       54       60                90       94       82
//         5        11       17                         33                         49       55                65       95       97       79

//  Side leds
//  67      68
//  70      71
//  73      74
//  76      77
//  80      81
//  83      84
//  87      88
//  91      92
