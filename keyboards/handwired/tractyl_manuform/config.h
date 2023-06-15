/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC

/* PMW33XX Settings */

#define PMW33XX_CS_PIN B6

// Added Defines from Discord
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSACTION_IDS_KB RPC_ID_KB_CONFIG_SYNC
#define SPLIT_POINTING_ENABLE
#define ROTATIONAL_TRANSFORM_ANGLE  -25
// #define POINTING_DEVICE_INVERT_Y // only available for single
// #define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT_Y_RIGHT
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define PMW3XX_LIFTOFF_DISTANCE 0x0A
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 3

// #define CHARYBDIS_DRAGSCROLL_REVERSE_Y

// #define CHARYBDIS_MINIMUM_DEFAULT_DPI 120
// #define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 400
// #define CHARYBDIS_MINIMUM_SNIPING_DPI 400
// #define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 200
// #define CHARYBDIS_DRAGSCROLL_DPI 1
// #define CHARYBDIS_POINTER_ACCELERATION_ENABLE