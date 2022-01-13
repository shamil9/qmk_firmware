#undef USB_POLLING_INTERVAL_MS
#define USB_POLLING_INTERVAL_MS 1

#undef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 12

#undef DEBOUNCE
#define DEBOUNCE 5

#include "quantum.h"

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
  UTWO,
  CONE,
};

//Tap Dance Declarations
enum {
  GAMING = 1,
  DEFAULT = 2,
};
