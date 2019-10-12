#include QMK_KEYBOARD_H

enum custom_keycodes {
  RARW = SAFE_RANGE,
  LARW,
  RARWF,
  EONE,
  ETWO,
  AONE,
  ATWO,
  UONE,
  CONE,
};

//Tap Dance Declarations
enum {
  ALT_SIX = 0,
  GAMING = 1,
  DEFAULT = 2,
};


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [ALT_SIX]  = ACTION_TAP_DANCE_DOUBLE(KC_6, LALT(KC_6)),
  [GAMING]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, 2),
  [DEFAULT]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, 0),
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
      KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   TD(ALT_SIX),   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_GRAVE, \
      KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,          KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, LT(3, KC_PGUP),    \
      LCTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,          KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,           KC_PGDN,   \
      KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,          KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,             TD(GAMING),   \
      KC_HYPR, KC_LALT, KC_LGUI,                   LT(1, KC_SPACE),               OSL(1),  KC_HYPR,                   KC_LEFT, KC_DOWN,  KC_RIGHT),

  [1] = LAYOUT(
      KC_NO, KC_F1, KC_F2, KC_F3,   KC_F4, KC_F5, KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_NO,   KC_DEL,   \
      KC_NO, KC_NO, KC_NO, EONE,    ETWO,  KC_NO, KC_NO,   UONE,    KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
      KC_NO, ATWO,  AONE,  KC_BSPC, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,  KC_NO,   KC_NO,            KC_NO,   \
      KC_NO,        KC_NO, KC_NO,   CONE,  KC_NO, KC_NO,   KC_NO,   KC_NO, LARW,    RARW,   RARWF,   KC_VOLU, KC_NO,   RESET,    \
      KC_NO, KC_NO, KC_NO,                     KC_NO,                      KC_NO,   KC_NO,  KC_MPRV, KC_VOLD, KC_MNXT),

  [2] = LAYOUT(
      KC_NO, KC_F1, KC_F2, KC_F3,   KC_F4, KC_F5, KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_NO,   KC_DEL,   \
      KC_NO, KC_NO, KC_NO, EONE,    ETWO,  KC_NO, KC_NO,   UONE,    KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
      KC_NO, ATWO,  AONE,  KC_BSPC, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,  KC_NO,   KC_NO,            KC_NO,   \
      KC_NO,        KC_NO, KC_NO,   CONE,  KC_NO, KC_NO,   KC_NO,   KC_NO, LARW,    RARW,   RARWF,   KC_VOLU, KC_NO,   RESET,    \
      KC_NO, KC_NO, KC_NO,                     KC_NO,                      KC_NO,   KC_NO,  KC_MPRV, KC_VOLD, KC_MNXT),

  [3] = LAYOUT(
      KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   \
      KC_NO, RGB_TOG, RGB_MOD, RGB_RMOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   \
      KC_NO, RGB_HUI, RGB_HUD, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,   \
      KC_NO,          RGB_VAI, RGB_VAD,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    \
      KC_NO, KC_NO,   KC_NO,                      KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)

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

        case EONE:
          SEND_STRING(SS_LALT("e")"e");
          break;

        case ETWO:
          SEND_STRING(SS_LALT("`")"e");
          break;

        case AONE:
          SEND_STRING(SS_LALT("e")"a");
          break;

        case ATWO:
          SEND_STRING(SS_LALT("`")"a");
          break;

        case CONE:
          SEND_STRING(SS_LALT("c")"c");
          break;

        case UONE:
          SEND_STRING(SS_LALT("e")"u");
          break;
    }
  }

  return true;
};
