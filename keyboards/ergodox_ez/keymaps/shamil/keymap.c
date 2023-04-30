#include QMK_KEYBOARD_H
#include "version.h"
#include "shamil.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ergodox_pretty(
  KC_GRV,         KC_1,  KC_2,    KC_3,    KC_4,    KC_5, KC_MINS,      KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_BSPC,
  KC_TAB,         KC_Q,  KC_W,    KC_E,    KC_R,    KC_T, KC_F2,        KC_F4,   KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_BSLS,
  LCTL_T(KC_ESC), KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,
  KC_RSFT,        KC_Z,  KC_X,    KC_C,    KC_V,    KC_B, KC_F1,        KC_F3,   KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,
  MO(2),          KC_NO, KC_LCTL, KC_RGUI, KC_LALT,                                       KC_RALT, KC_RGUI, KC_CAPS,  KC_NO,    WIN_LAYOUT,
                                                 KC_MPLY, KC_MUTE,      KC_MPRV, KC_MNXT,
                                                          KC_HOME,      KC_PGUP,
                                  LT(2, KC_SPC), KC_RSFT, KC_END,       KC_PGDN, KC_RSFT, HYPR_T(KC_ENT)
),

[1] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_RGUI, MO(2),   KC_LALT,                                         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,MAC_LAYOUT,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_SPC,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_ENT
),

[2] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,      KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,  KC_LBRC, KC_RBRC,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  RARWF,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, QK_BOOT,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),

[3] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, X(0),    X(2),    X(4),    KC_TRNS,     KC_TRNS, KC_TRNS, X(24),   X(14),   X(22),   KC_TRNS, KC_TRNS,
  KC_TRNS, X(10),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, X(12),   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};
