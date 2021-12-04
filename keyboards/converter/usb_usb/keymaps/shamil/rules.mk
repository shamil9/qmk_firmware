EXTRAFLAGS+=-flto
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no  # Mouse keys
EXTRAKEY_ENABLE  = yes  # Audio control and System control
CONSOLE_ENABLE   = no  # Console for debug
COMMAND_ENABLE   = no  # Commands for debug and configuration
SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE      = no  # USB Nkey Rollover - not yet supported in LUFA
BACKLIGHT_ENABLE = no
USB_HID_ENABLE   = yes
CUSTOM_MATRIX    = yes

SRC = custom_matrix.cpp

DEFAULT_FOLDER = converter/usb_usb/hasu
