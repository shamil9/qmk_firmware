UNICODE_ENABLE = no
UCIS_ENABLE = no
UNICODEMAP_ENABLE = yes
TAP_DANCE_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pk

SRC += shamil.c

# ifeq ($(strip $(MACROS_ENABLED)), yes)
#     OPT_DEFS += -DMACROS_ENABLED
# endif
