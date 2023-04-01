#undef DEBOUNCE
#define DEBOUNCE 8

#include "quantum.h"

enum custom_keycodes {
  RARW = SAFE_RANGE,
  LARW,
  RARWF,
  EONE,
  ETWO,
  ETHREE,
  IONE,
  ATWO,
  UONE,
  OONE,
  CONE,
  WIN_LAYOUT,
  MAC_LAYOUT,
};

//Tap Dance Declarations
enum {
  GAMING = 1,
  DEFAULT = 2,
};
