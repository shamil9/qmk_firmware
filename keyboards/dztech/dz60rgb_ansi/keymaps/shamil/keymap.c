#include QMK_KEYBOARD_H

//Tap Dance Declarations
enum {
  GAMING,
  DEFAULT,
};

enum custom_keycodes {
  RARW = SAFE_RANGE,
  LARW,
  RARWF,
  EONE,
  ETWO,
  ETHREE,
  AONE,
  ATWO,
  UONE,
  CONE,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [GAMING]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, 3),
  [DEFAULT]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, 0),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[0] = LAYOUT_60_ansi( /* Base */
			KC_GRAVE,       KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,\
		    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLASH,\
			CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,\
		    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
		    KC_HYPR,        KC_LALT, KC_LGUI,                 LT(1, KC_SPACE),                       OSL(1),  KC_RALT, MO(2),             TD(GAMING)),
		[1] = LAYOUT_60_ansi( /* FN */
			KC_NO,          KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5,  KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,\
			KC_NO,          KC_NO,   KC_NO,   EONE,    ETWO,  ETHREE, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_MPLY, KC_MPRV, KC_MNXT,  KC_MUTE,\
			KC_NO,          ATWO,    AONE,    KC_BSPC, KC_NO, KC_NO,  KC_LEFT,     KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,             RESET,\
			KC_NO,          KC_NO,   KC_NO,   CONE,    KC_NO, KC_NO,  KC_NO,       KC_NO,   LARW,    RARW,    RARWF,   KC_NO,\
			KC_NO,          KC_NO,   KC_NO,                   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,             KC_NO),
		[2] = LAYOUT_60_ansi( /* FN2 */
			KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_SPD,  RGB_SPI, KC_NO,\
			RGB_TOG,        RGB_HUI, RGB_HUD, KC_NO,   KC_NO,  KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_RMOD, RGB_MOD, KC_NO,\
			KC_NO,          RGB_SAI, RGB_SAD, KC_NO,   KC_NO,  KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,\
			KC_NO,          RGB_VAI, RGB_VAD, KC_NO,   KC_NO,  KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
			KC_NO,          KC_NO,   KC_NO,                    KC_NO,                                KC_NO,   KC_NO,   KC_NO,             KC_NO),
		[3] = LAYOUT_60_ansi( /* FN3 */
			KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,\
			KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,  KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLASH,\
			CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,  KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,\
			KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,  KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
			KC_HYPR,        KC_LGUI, KC_LALT,                  KC_SPC,                               MO(4),   KC_NO,   KC_NO,             TD(DEFAULT)),
		[4] = LAYOUT_60_ansi( /* FN4 */
			KC_NO,          KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5, KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,\
			KC_NO,          KC_NO,   KC_UP,   KC_NO,   KC_NO,  KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV,  KC_MNXT, KC_MUTE,\
			KC_NO,          KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,  KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,\
			KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
			KC_NO,          KC_NO,   KC_NO,                    KC_NO,                                KC_NO,   KC_NO,   KC_NO,             KC_NO),
		};

void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
        rgb_matrix_set_color( i, red, green, blue );
    }
  }
}

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

            case ETHREE:
                SEND_STRING(SS_LALT("6")"e");
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
        }
    }

    return true;
};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}
