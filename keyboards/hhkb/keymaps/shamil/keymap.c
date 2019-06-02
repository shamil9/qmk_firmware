/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#define BASE 0
#define HHKB 1
#define RARW M(1)
#define RARWF M(2)
#define LARW M(3)
#define FRA M(4)
#define FRE M(5)
#define FRA_ALT M(6)
#define FRE_ALT M(7)
#define FRE_ALT2 M(8)
#define FRU M(9)
#define FRC M(10)
#define SCLN_EQL M(11)

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

    /* BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | RGUI | RAlt |
            |------+------+-----------------------+------+------|
    */

    [0] = LAYOUT( //  default layer
        KC_ESC,         KC_1, KC_2, KC_3, KC_4, KC_5, TD(ALT_SIX), KC_7,      KC_8,   KC_9,    KC_0,      KC_MINS, KC_EQL, KC_BSLS, TD(ALT_GRAVE),
        KC_TAB,         KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U,  KC_I,      KC_O,   KC_P,    KC_LBRC,   KC_RBRC, KC_BSPC,
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,  KC_K,      KC_L,   KC_SCLN, TD(ALT_E), KC_ENT,
        KC_LSFT,        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,  TD(ALT_C), KC_DOT, KC_SLSH, KC_RSFT,   TD(GAMING),
        KC_LALT,        KC_LGUI, /*        */ LT(1, KC_SPACE),     KC_RGUI,   KC_RALT),

    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | VoD | VoU | Mut |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    [1] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_BSPC,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_BSPC, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, LARW,    RARW,    RARWF,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [2] = LAYOUT( // win layer
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,  KC_8,      KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_GRAVE,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U,  KC_I,      KC_O,   KC_P,    KC_LBRC,  KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,  KC_K,      KC_L,   KC_SCLN, KC_QUOTE, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,  KC_COMMA,  KC_DOT, KC_SLSH, KC_RSFT,  TD(DEFAULT),
        KC_LGUI, KC_LALT, /*        */ KC_SPACE,     KC_RALT,   KC_RGUI)
  };

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case 1:
            return (record->event.pressed ?
                    MACRO( I(15), T(MINS), D(LSFT), T(DOT), U(LSFT), END) :
                    MACRO_NONE );
        case 2:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), T(EQL), D(LSFT), T(DOT), U(LSFT), END) :
                    MACRO_NONE );
        case 3:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), D(LSFT), T(COMM), U(LSFT), T(MINS), END) :
                    MACRO_NONE );
        case 4:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), D(LALT), T(GRV), U(LALT), T(A), END) :
                    MACRO_NONE );
        case 5:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), D(LALT), T(E), U(LALT), T(E), END) :
                    MACRO_NONE );
        case 6:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), D(LALT), T(E), U(LALT), T(A), END) :
                    MACRO_NONE );
        case 7:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), D(LALT), T(GRV), U(LALT), T(E), END) :
                    MACRO_NONE );
        case 8:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), D(RALT), T(6), U(RALT), T(E), END) :
                    MACRO_NONE );
        case 9:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), D(LALT), T(GRV), U(LALT), T(U), END) :
                    MACRO_NONE );
        case 10:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), D(LALT), T(C), U(LALT), T(C), END) :
                    MACRO_NONE );
        case 11:
            return (record->event.pressed ?
                    MACRO( \
                          I(15), T(SPC), D(LSFT), T(SCLN), U(LSFT), T(EQL), T(SPC), END) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}
