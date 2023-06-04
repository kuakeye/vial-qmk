/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
// Compile command: 
// qmk flash -kb handwired/tractyl_manuform/5x6_right/elite_c -km default -bl dfu-split-left

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif  // CONSOLE_ENABLE

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE,
};

// Layers
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// Custom codes n combos
#define KC_WSL LCTL(LGUI(KC_LEFT))
#define KC_WSR LCTL(LGUI(KC_RIGHT))
#define SWITCH LGUI(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x6_right(
     KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_EQL,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
     KC_BSPC, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_ESC, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
     KC_LCTL,KC_LGUI, KC_LALT,LOWER,                                                     LOWER, KC_EQL,KC_PLUS, KC_EQL,
                        MT(MOD_LSFT, KC_ENT), KC_DEL,                        KC_RGUI, LT(_RAISE,KC_SPC)
  ),

  [_LOWER] = LAYOUT_5x6_right(
     KC_TILD,KC_F1  , KC_F2 ,KC_F3 , KC_F4 , KC_F5,                               KC_F6,   KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11,
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE,                        KC_LT,   KC_P7 , KC_P8 , KC_P9 ,KC_PAST,KC_PLUS,
     KC_UNDS ,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,KC_GRV,                         KC_GT,   KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_EQL,
     _______ ,KC_PERC ,KC_CIRC ,KC_LBRC ,KC_RBRC ,KC_TILD,                        KC_AMPR, KC_P1 , KC_P2 , KC_P3 ,KC_PPLS,_______,
     _______,_______,_______,_______,                                                         KC_P0 , KC_DOT,KC_PSLS,_______,
                                             _______,_______,        _______,_______

  ),

  [_RAISE] = LAYOUT_5x6_right(
       QK_BOOT,_______,_______,_______,_______,_______,                        _______,_______,_______,KC_MPRV,KC_MNXT,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,SWITCH,_______,KC_MPLY ,KC_VOLD,
       _______,_______,_______,_______,_______,_______,                        _______,KC_WSL,_______,KC_WSR,_______,_______,
       _______,_______,_______,_______,_______,_______,                        _______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END,
       _______,_______,_______,_______,                                                        KC_LEFT,KC_DOWN, KC_UP ,KC_RIGHT,
                                             DRGSCRL,_______,        _______,_______
  ),

    [_MOUSE] = LAYOUT_5x6_right(
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                        _______,KC_MS_BTN1,KC_MS_BTN2,KC_MS_BTN3,_______,_______,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                             _______,_______,        _______,_RAISE
  ),
};

void keyboard_post_init_user(void) {
// #ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
// #else
//     debug_enable=false;
//     debug_matrix=false;
//     debug_keyboard=false;
//     debug_mouse=false;
// #endif
};

/* For when dual trackballs arrive
// source: https://docs.qmk.fm/#/feature_pointing_device
void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 1000); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}
*/

/* Blank layer template
  [_RAISE] = LAYOUT_5x6_right(
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                             _______,_______,        _______,_______
  ),

*/

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
};