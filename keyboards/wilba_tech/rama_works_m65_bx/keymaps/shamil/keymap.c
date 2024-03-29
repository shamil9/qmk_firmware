#include QMK_KEYBOARD_H
#include "shamil.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
      KC_ESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,          KC_7,        KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,  KC_BSPC, KC_GRAVE, \
      KC_TAB,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,          KC_U,        KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,           KC_PGUP,    \
LCTL_T(KC_ESC),  KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,          KC_J,        KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,                        KC_PGDN,   \
      KC_LSFT,   KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,          KC_M,        KC_COMM,    KC_DOT,     KC_SLSH,    KC_LSFT,    KC_UP,                         TD(GAMING),   \
      KC_HYPR,   KC_LALT,    KC_LGUI,                LT(2, KC_SPACE),                       KC_RGUI,                                         KC_LEFT,    KC_DOWN,    KC_RIGHT),

  [1] = LAYOUT_all(
      KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,   \
      KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,   \
      KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                       KC_TRNS,   \
      KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                       TD(DEFAULT),    \
      MO(2),     KC_NO,      KC_LALT,                KC_SPACE,                              KC_TRNS,                                         KC_TRNS,    KC_TRNS,    KC_TRNS),

  [2] = LAYOUT_all(
      RGB_TOG,   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,         KC_F7,       KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,  KC_DEL,  KC_TRNS,   \
      UC_MOD,    KC_TRNS,    KC_TRNS,    X(0),       X(2),       X(4),       KC_TRNS,       X(24),       X(14),      X(22),      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,          BR_INC,   \
      KC_TRNS,   X(10),      KC_TRNS,    KC_BSPC,    KC_TRNS,    KC_TRNS,    KC_LEFT,       KC_DOWN,     KC_UP,      KC_RGHT,    KC_TRNS,    KC_TRNS,    KC_TRNS,                      BR_DEC,   \
      KC_TRNS,   KC_TRNS,    KC_TRNS,    X(12),      KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,     LARW,       RARW,       RARWF,      KC_TRNS,    EF_INC,                       RESET,    \
      KC_TRNS,   KC_TRNS,    KC_TRNS,                KC_TRNS,                               KC_TRNS,                                         KC_MPRV,    EF_DEC,     KC_MNXT),
};
