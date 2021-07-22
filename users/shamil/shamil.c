#include "shamil.h"

enum unicode_names {
  E_AIG,
  E_AIG_MAJ,
  E_GRV,
  E_GRV_MAJ,
  E_CIRC,
  E_CIRC_MAJ,
  E_TREMA,
  E_TREMA_MAJ,
  A_CIRC,
  A_CIRC_MAJ,
  A_GRV,
  A_GRV_MAJ,
  C_CEDILLE,
  C_CEDILLE_MAJ,
  I_CIRC,
  I_CIRC_MAJ,
  EURO,
  BAHT,
  COPYRIGHT,
  REGISTERED,
  OMEGA,
  OMEGA_MAJ,
  O_CIRC,
  O_CIRC_MAJ,
  U_GRAV,
  U_GRAV_MAJ,
  OE,
  OE_MAJ,
  PI,
  DEGREE,
  N_TILDE,
  N_TILDE_MAJ,
  MICRO,
  SIGMA,
  INFEQ,
  SUPEQ,
  GUILL_G,
  GUILL_R,
  UNEQUAL,
  PRETTYMUCH,
  INFINIT,
};

const uint32_t PROGMEM unicode_map[] = {
  [E_AIG]  = 0x00E9,  // 0 é
  [E_AIG_MAJ] = 0x00C9,  // 1 É
  [E_GRV]  = 0x00E8,  // 2 è
  [E_GRV_MAJ] = 0x00C8,  // 3 È
  [E_CIRC]  = 0x00EA,  // 4 ê
  [E_CIRC_MAJ] = 0x00CA,  // 5 Ê
  [E_TREMA]  = 0x00EB,  // 6 ë
  [E_TREMA_MAJ] = 0x00CB,  // 7 Ë
  [A_CIRC]  = 0x00E2,  // 8 â
  [A_CIRC_MAJ] = 0x00C2,  // 9 Ê
  [A_GRV]  = 0x00E0,  // 10 Â
  [A_GRV_MAJ] = 0x00C0,  // 11 À
  [C_CEDILLE]  = 0x00E7,  // 12 ç
  [C_CEDILLE_MAJ] = 0x00C7,  // 13 Ç
  [I_CIRC]  = 0x00EE,  // 14 î
  [I_CIRC_MAJ] = 0x00CE,  // 15 Î
  [EURO]  = 0x20AC,  // 16 €
  [BAHT] = 0x0E3F,  // 17 ฿
  [COPYRIGHT]  = 0x00A9,  // 18 ©
  [REGISTERED] = 0x00AE,  // 19 ®
  [OMEGA]  = 0x03C9,  // 20 ω
  [OMEGA_MAJ] = 0x03A9,  // 21 Ω
  [O_CIRC]  = 0x00F4,  // 22 ô
  [O_CIRC_MAJ] = 0x00D4,  // 23 Ô
  [U_GRAV]  = 0x00F9,  // 24 ù
  [U_GRAV_MAJ] = 0x00D9,  // 25 Ù
  [OE]  = 0x0153,  // 26 œ
  [OE_MAJ] = 0x0152,  // 27 Œ
  [PI] = 0x03C0, // 28 π
  [DEGREE] = 0x00B0, // 29 °
  [N_TILDE]  = 0x00F1,  // 30 ñ
  [N_TILDE_MAJ] = 0x00D1,  // 31 Ñ
  [MICRO]  = 0x00B5,  // 32 µ
  [SIGMA] = 0x03C3,  // 33 σ
  [INFEQ]  = 0x2264,  // 34 ≤
  [SUPEQ] = 0x2265,  // 35 ≥
  [GUILL_G]  = 0x00AB,  // 36 «
  [GUILL_R] = 0x00BB,  // 37 »
  [UNEQUAL]  = 0x2260,  // 38 ≠
  [PRETTYMUCH] = 0x2248,  // 39 ≈
  [INFINIT] = 0x221E,  // 40 ∞
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [GAMING]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, 1),
  [DEFAULT]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, 0),
// Other declarations would go here, separated by commas, if you have them
};

uint16_t gui_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case KC_LSFT:
        if (record->event.pressed) {
            register_mods(MOD_BIT(KC_LSFT));
            gui_timer = timer_read();
        } else {
            if (timer_elapsed (gui_timer) > TAPPING_TERM) {
                unregister_mods(MOD_BIT(KC_LSFT));
            } else {
                register_code(keycode);
                unregister_code(keycode);
                unregister_mods(MOD_BIT(KC_LSFT));
                layer_on(2);
                set_oneshot_layer(2, ONESHOT_START);
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
        }

        break;

        if (record->event.pressed) {
            case RARW:
              SEND_STRING("->");
              break;

            case RARWF:
               SEND_STRING("=>");

            case LARW:
                SEND_STRING("<-");
                break;
        }
    }

    return true;
};
