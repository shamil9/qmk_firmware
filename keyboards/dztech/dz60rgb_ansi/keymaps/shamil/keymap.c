#include QMK_KEYBOARD_H
#include "shamil.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi( /* Base */
        KC_GRAVE,      KC_1,    KC_2,    KC_3,    KC_4,         KC_5,    KC_6,    KC_7,         KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,\
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,    KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,\
        CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    LALT_T(KC_F), KC_G,    KC_H,    LALT_T(KC_J), KC_K,    KC_L,    KC_SCLN, KC_QUOT,            HYPR_T(KC_ENT),\
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,    KC_N,    KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,\
        KC_HYPR,       KC_LALT, KC_RGUI,                 LT(2, KC_SPACE),                       KC_RGUI, KC_RALT, KC_RCTL, WIN_LAYOUT),

    [1] = LAYOUT_60_ansi( /* FN2 */
        KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPD,  RGB_SPI, KC_TRNS,\
        KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_MOD, KC_TRNS,\
        KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_F,         KC_TRNS, KC_TRNS, KC_J,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_ENT,\
        KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
        KC_TRNS,       OSL(2),  KC_LALT,                  KC_SPACE,                             KC_TRNS, KC_TRNS, KC_TRNS, MAC_LAYOUT),

    [2] = LAYOUT_60_ansi( /* FN */
        KC_TRNS,       KC_F1,   KC_F2,   KC_F3,   KC_F4,        KC_F5,   KC_F6,   KC_F7,        KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   QK_BOOT,\
        RGB_MOD,       KC_TRNS, KC_TRNS, X(0),    X(2),         X(4),    KC_TRNS, X(24),        X(14),   X(22),   KC_MPLY, KC_MPRV, KC_MNXT,  KC_MUTE,\
        KC_TRNS,       X(10),   KC_TRNS, KC_BSPC, KC_TRNS,      KC_TRNS, KC_LEFT, KC_DOWN,      KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,           KC_TRNS,\
        KC_TRNS,       KC_TRNS, KC_TRNS, X(12),   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, RARW,    RARWF,   KC_TRNS,\
        KC_TRNS,       KC_TRNS, KC_TRNS,                  KC_TRNS,                              RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD),
};

// void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
//   for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
//     if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
//         rgb_matrix_set_color( i, red, green, blue );
//     }
//   }
// }


// void matrix_init_user(void) {
//   //user initialization
// }

// void matrix_scan_user(void) {
//   //user matrix
// }
