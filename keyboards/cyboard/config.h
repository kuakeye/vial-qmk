/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

/* Split keybard settings */
#define SERIAL_USART_TX_PIN GP28
#define SPLIT_HAND_PIN GP0

/* RGB settings */
#ifdef RGB_MATRIX_ENABLE
#    define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
#    define SPLIT_TRANSPORT_MIRROR
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE // Sets the default mode, if none has been set
#    define RGB_MATRIX_DEFAULT_HUE 33 // Sets the default hue value, if none has been set
#    define RGB_MATRIX_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
#    define RGB_MATRIX_DEFAULT_SPD 50
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif

/* Double-tap reset button parameters */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define USB_VBUS_PIN GP27

/* Vial set up */
#define VIAL_KEYBOARD_UID {0xC4, 0xCC, 0xB4, 0x76, 0x30, 0x16, 0xFC, 0x70}

#define VIAL_UNLOCK_COMBO_ROWS { 10, 10 }
#define VIAL_UNLOCK_COMBO_COLS { 3, 4 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 10

//trackball support
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define POINTING_DEVICE_CS_PIN GP21
// #define POINTING_DEVICE_INVERT_X
#define PMW3360_CPI 1600

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC

/* PMW33XX Settings */

// #define PMW33XX_CS_PIN B6

// Added Defines from Discord
// #define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC
// #define SPLIT_POINTING_ENABLE
// #define ROTATIONAL_TRANSFORM_ANGLE  -25
// #define POINTING_DEVICE_INVERT_Y // only available for single
// #define POINTING_DEVICE_ROTATION_90
// #define POINTING_DEVICE_INVERT_Y
// #define POINTING_DEVICE_INVERT_Y_RIGHT
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT
#define POINTING_DEVICE_INVERT_X_RIGHT
#define POINTING_DEVICE_COMBINED
// #define POINTING_DEVICE_TASK_THROTTLE_MS 1
// #define PMW3XX_LIFTOFF_DISTANCE 0x0A
// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #define AUTO_MOUSE_DEFAULT_LAYER 3