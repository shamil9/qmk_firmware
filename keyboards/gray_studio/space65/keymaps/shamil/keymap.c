#include QMK_KEYBOARD_H

enum custom_keycodes {
  RARW = SAFE_RANGE,
  LARW,
  RARWF,
};

//Tap Dance Declarations
enum {
  ALT_E = 0,
  ALT_SIX = 1,
  ALT_GRAVE = 2,
  ALT_C = 3,
  FAT_ARROW = 4,
  MORE_THAN = 5,
  LESS_THAN = 6,
  GAMING = 7,
  DEFAULT = 8,
};

void fat_arrow(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_SLASH);
    unregister_code(KC_SLASH);
    reset_tap_dance (state);
  } else {
    SEND_STRING ("=>");
    reset_tap_dance (state);
  }
}

void more_than(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_DOT);
    unregister_code(KC_DOT);
    reset_tap_dance (state);
  } else {
    SEND_STRING (">=");
    reset_tap_dance (state);
  }
}

void less_than(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_COMMA);
    unregister_code(KC_COMMA);
    reset_tap_dance (state);
  } else {
    SEND_STRING ("<=");
    reset_tap_dance (state);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [ALT_E]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, LALT(KC_E)),
  [ALT_SIX]  = ACTION_TAP_DANCE_DOUBLE(KC_6, LALT(KC_6)),
  [ALT_GRAVE]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, LALT(KC_GRAVE)),
  [ALT_C]  = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, LALT(KC_C)),
  [FAT_ARROW]  = ACTION_TAP_DANCE_FN(fat_arrow),
  [MORE_THAN]  = ACTION_TAP_DANCE_FN(more_than),
  [LESS_THAN]  = ACTION_TAP_DANCE_FN(less_than),
  [GAMING]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, 2),
  [DEFAULT]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, 0),
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        KC_ESC,         KC_1,  KC_2, KC_3, KC_4, KC_5, TD(ALT_SIX), KC_7, KC_8, KC_9,      KC_0,    KC_MINS,   KC_EQL,  KC_BSPC, KC_BSPC, TD(ALT_GRAVE),
        KC_TAB,         KC_Q,  KC_W, KC_E, KC_R, KC_T, KC_Y,        KC_U, KC_I, KC_O,      KC_P,    KC_LBRC,   KC_RBRC, KC_BSLS,          KC_PGUP,
        LCTL_T(KC_ESC), KC_A,  KC_S, KC_D, KC_F, KC_G, KC_H,        KC_J, KC_K, KC_L,      KC_SCLN, TD(ALT_E), KC_ENT,                    KC_PGDN,
        KC_LSFT,        KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_N, KC_M, TD(ALT_C), KC_DOT,  KC_SLSH,   KC_RSFT, KC_UP,            TD(GAMING),
        KC_HYPR,     KC_LALT, KC_LGUI, KC_SPC, LT(1, KC_SPACE), KC_SPC, KC_LGUI, KC_RALT,             KC_LEFT, KC_DOWN, KC_RGHT
    ),

	[1] = LAYOUT(
        KC_F1, KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_DEL,
        KC_NO, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO, KC_NO,        KC_NO,
        KC_NO, RGB_SPI, RGB_SPD, KC_BSPC,  KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,  KC_NO,  KC_NO,               KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, LARW,    RARW,   RARWF,  KC_NO, KC_NO,        RESET,
        KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO,  KC_NO, KC_NO
    ),

    [2] = LAYOUT(
        KC_ESC,  KC_1,  KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,     KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_BSPC, KC_GRAVE,
        KC_TAB,  KC_Q,  KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,     KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_LCTL, KC_A,  KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,     KC_SCLN, KC_QUOTE, KC_ENT,                    KC_PGDN,
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,            TD(DEFAULT),
        KC_HYPR,       KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RGUI,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case RARW:
        SEND_STRING("->");
        break;

       case RARWF:
         SEND_STRING("=>");
         break;

        case LARW:
          SEND_STRING("<-");
          break;
    }
  }

  return true;
};
