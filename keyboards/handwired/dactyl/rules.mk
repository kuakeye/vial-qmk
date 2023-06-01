# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = halfkay

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
POINTING_DEVICE_ENABLE  = yes
MOUSEKEY_ENABLE         = yes  # Mouse keys
EXTRAKEY_ENABLE         = no # Audio control and System control
CONSOLE_ENABLE          = no  # Console for debug
COMMAND_ENABLE          = yes  # Commands for debug and configuration
CUSTOM_MATRIX           = yes # Custom matrix file for the Dactyl
NKRO_ENABLE = yes           # Enable N-Key Rollover
UNICODE_ENABLE          = yes # Unicode
SWAP_HANDS_ENABLE       = yes # Allow swapping hands of keyboard
RGBLIGHT_ENABLE         = no

# project specific files
QUANTUM_LIB_SRC += i2c_master.c
SRC += matrix.c
