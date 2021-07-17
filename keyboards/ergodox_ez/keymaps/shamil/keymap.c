#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
//#include "keymap_german.h"
//#include "keymap_french_osx.h"

enum custom_keycodes {
  MY_CUSTOM_MACRO = SAFE_RANGE,
  MY_OTHER_MACRO,
  EPRM,
  RGB_SLD,

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
  LEFT_BRACKET = 7,
  ALT_QUOTE = 8,
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
  [ALT_E]  = ACTION_TAP_DANCE_DOUBLE(KC_E, LALT(KC_E)),
  [ALT_SIX]  = ACTION_TAP_DANCE_DOUBLE(KC_6, LALT(KC_6)),
  [ALT_GRAVE]  = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, LALT(KC_GRAVE)),
  [ALT_C]  = ACTION_TAP_DANCE_DOUBLE(KC_C, LALT(KC_C)),
  [FAT_ARROW]  = ACTION_TAP_DANCE_FN(fat_arrow),
  [MORE_THAN]  = ACTION_TAP_DANCE_FN(more_than),
  [LESS_THAN]  = ACTION_TAP_DANCE_FN(less_than),
  [LEFT_BRACKET]  = ACTION_TAP_DANCE_DOUBLE(SFT_T(KC_LBRACKET), KC_LEFT_CURLY_BRACE),
  [ALT_QUOTE]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, LALT(KC_E)),
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(

  	// left
    KC_1,             KC_2,    KC_3,        KC_4,      KC_5, TD(ALT_SIX), KC_TRANSPARENT,
    KC_TAB,           KC_Q,    KC_W,        KC_E,      KC_R, KC_T,        KC_TRANSPARENT,
    CTL_T(KC_ESCAPE), KC_A,    KC_S,        KC_D,      KC_F, KC_G,
    KC_LSPO,          KC_Z,    KC_X,        KC_C,      KC_V, KC_B,        KC_TRANSPARENT,
    ALL_T(KC_NO),     KC_BSLS, LALT(KC_NO), KC_LGUI,   MO(1),

    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_SPACE,       KC_LSFT, KC_TRANSPARENT,

    // right
    KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_0,   KC_MINUS,  TD(ALT_GRAVE),
    KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,   KC_P,      KC_BSPACE,
                    KC_H,           KC_J,           KC_K,           KC_L,   KC_SCOLON, TD(ALT_QUOTE),
    KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT, KC_SLASH,  KC_RSPC,
                    MO(2),          GUI_T(KC_LEFT), ALT_T(KC_DOWN), KC_UP,  KC_RIGHT,

    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_RSFT, LT(3, KC_ENTER)
    ),

  [1] = LAYOUT_ergodox(

  	// left
  	KC_F1,          KC_F2,               KC_F3,               KC_F4,               KC_F5,          KC_F6,          KC_TRANSPARENT,
  	KC_TRANSPARENT,                      KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,

  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,


  	// right
  	KC_TRANSPARENT,  KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
  	KC_TRANSPARENT,  KC_MINUS,       KC_EQUAL,       KC_UNDS,        KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
  	KC_LEFT,KC_DOWN, KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  	),

  [2] = LAYOUT_ergodox(

  	// left
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_KP_PLUS,     KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7,     KC_KP_8,        KC_KP_9,     KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_4,     KC_KP_5,        KC_KP_6,     KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_1,     KC_KP_2,        KC_KP_3,     KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_0,     KC_KP_DOT,      KC_KP_COMMA,

  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,


  	// right
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

   	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  	),

  [3] = LAYOUT_ergodox(MY_CUSTOM_MACRO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case MY_CUSTOM_MACRO:
          SEND_STRING("=>");
          return false;
      case MY_OTHER_MACRO:
          SEND_STRING(SS_LCTRL("ac")); // selects all and copies
          return false;
      case EPRM:
          eeconfig_init();
          return false;
      break;
      case RGB_SLD:
          rgblight_mode(1);
          return false;
      break;
    }
  }

  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
