/* Copyright 2019 Ryota Goto
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all( /* Base */
    KC_ESC,         KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_6,           KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRAVE,
    KC_TAB,         KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,           KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,           KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT,        KC_BSLS, KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,          KC_LSFT, TD(GAMING),
    KC_LALT,        KC_LGUI, KC_LGUI,           KC_SPC,           LT(2, KC_SPACE),         KC_SPC,                     KC_SPC,  OSL(2),  KC_APP,  KC_HYPR
  ),

  [1] = LAYOUT_all( /* Base */
    KC_ESC,         KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_6,           KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRAVE,
    KC_TAB,         KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,           KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC,
    KC_LCTRL,       KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,           KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT,        KC_BSLS, KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,          KC_RSFT, TD(DEFAULT),
    KC_LGUI,        KC_LGUI, KC_LALT,           KC_SPC,           KC_SPACE,       KC_SPC,                     KC_SPC,  MO(2), KC_APP,  KC_HYPR
  ),

  [2] = LAYOUT_all( /* FN */
  KC_GRAVE,         KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
  UC_MOD,           KC_TRNS,  KC_TRNS, X(0),    X(2),    X(4),    KC_TRNS,        X(24),   X(14),   X(22),    KC_TRNS, KC_MPRV, KC_MNXT,          KC_DEL,
  KC_LCTRL,         X(10),    KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_LEFT,        KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,          KC_TRNS,
  KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS, X(12),   KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, LARW,     RARW,    RARWF,            KC_TRNS, RESET,
  _______,          _______,  _______,          _______,          _______,                 _______,                    _______, _______, _______, _______
  ),
};
