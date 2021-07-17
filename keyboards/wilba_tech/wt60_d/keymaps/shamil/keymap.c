// Default layout for WT60-D
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
  UTWO,
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

    // Default layer
    [0] = LAYOUT_all(
        KC_ESC,            KC_1,       KC_2,       KC_3,    KC_4,    KC_5,    TD(ALT_SIX),    KC_7,       KC_8,       KC_9,      KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_BSPC,
        KC_TAB,            KC_Q,       KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,           KC_U,       KC_I,       KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                KC_BSLS,
        LCTL_T(KC_ESC),    KC_A,       KC_S,       KC_D,    KC_F,    KC_G,    KC_H,           KC_J,       KC_K,       KC_L,      KC_SCLN,    KC_QUOT,                            KC_ENT,
        KC_LSFT,           KC_NO,      KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,           KC_N,       KC_M,       KC_COMM,   KC_DOT,     KC_SLSH,    KC_RSFT,                TD(GAMING),
        KC_HYPR,           KC_LALT,    KC_LGUI,                      LT(1, KC_SPACE),                     OSL(1),     KC_RGUI,   KC_RALT,                                        KC_HYPR
    ),

    // Fn1 Layer
    [1] = LAYOUT_all(
        KC_GRAVE,          KC_F1,      KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,      KC_F8,      KC_F9,      KC_F10,    KC_F11,     KC_F12,     KC_DEL,     KC_DEL,
        KC_TAB,            KC_Q,       KC_W,       EONE,    ETWO,    KC_T,    KC_Y,           UONE,       UTWO,       KC_O,       KC_P,      KC_MPRV,    KC_MNXT,                KC_BSLS,
        KC_LCTRL,          ATWO,       AONE,       KC_BSPC, KC_F,    KC_G,    KC_LEFT,        KC_DOWN,    KC_UP,      KC_RIGHT,   KC_SCLN,   KC_QUOT,                            KC_ENT,
        KC_LSFT,           KC_NO,      KC_Z,       KC_X,    CONE,    KC_V,    KC_B,           KC_N,       KC_M,       LARW,       RARW,      RARWF,      KC_RSFT,                RESET,
        KC_HYPR,           KC_LALT,    KC_LGUI,                      LT(1, KC_SPACE),                     OSL(1),     KC_RGUI,    KC_RALT,                                       KC_HYPR
    ),

    // Fn2 Layer
    [2] = LAYOUT_all(
        KC_ESC,            KC_1,       KC_2,       KC_3,    KC_4,    KC_5,    KC_6,            KC_7,      KC_8,       KC_9,        KC_0,      KC_MINS,    KC_EQL,    KC_BSPC,    KC_BSPC,
        KC_TAB,            KC_Q,       KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,            KC_U,      KC_I,       KC_O,        KC_P,      KC_LBRC,    KC_RBRC,               KC_BSLS,
        KC_LCTRL,          KC_A,       KC_S,       KC_D,    KC_F,    KC_G,    KC_H,            KC_J,      KC_K,       KC_L,        KC_SCLN,   KC_QUOT,                           KC_ENT,
        KC_LSFT,           KC_NO,      KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,            KC_N,      KC_M,       KC_COMM,     KC_DOT,    KC_SLSH,    KC_RSFT,               TD(DEFAULT),
        KC_HYPR,           MO(3),      KC_LALT,                      KC_SPC,                              OSL(3),     KC_RALT,     KC_RGUI,                                      KC_HYPR
    ),

    // Fn3 Layer
    [3] = LAYOUT_all(
        KC_GRAVE,          KC_F1,      KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,      KC_F8,      KC_F9,      KC_F10,    KC_F11,     KC_F12,     KC_DEL,     KC_DEL,
        KC_TAB,            KC_Q,       KC_W,       KC_TRNS, KC_TRNS, KC_T,    KC_Y,           KC_TRNS,    KC_TRNS,    KC_O,       KC_P,      KC_MPRV,    KC_MNXT,                KC_BSLS,
        KC_LCTRL,          KC_TRNS,    KC_TRNS,    KC_TRNS, KC_F,    KC_G,    KC_LEFT,        KC_DOWN,    KC_UP,      KC_RIGHT,   KC_SCLN,   KC_QUOT,                            KC_TRNS,
        KC_LSFT,           KC_NO,      KC_Z,       KC_X,    KC_TRNS, KC_V,    KC_B,           KC_N,       KC_M,       LARW,       RARW,      RARWF,      KC_RSFT,                TD(GAMING),
        KC_HYPR,           KC_TRNS,    KC_TRNS,                      KC_TRNS,                             KC_TRNS,    KC_TRNS,    KC_RALT,                                       KC_HYPR
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
          SEND_STRING(SS_LALT("`")"u");
          break;

        case UTWO:
          SEND_STRING(SS_LALT("e")"u");
          break;
    }
  }

  return true;
};
