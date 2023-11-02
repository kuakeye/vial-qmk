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
#include "5x6_right.h"
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
    _HYPER,
};

// Trackball mode switching keycodes and other keyboard macros
enum custom_keycodes {
    _SCROLL,
    _ARROWS,
    _DBLCLK,
    _TRPLCLK,
};
// Default trackball values on startup
bool set_scrolling = false;
bool set_arrows = true;


// Layers
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define HYPER MO(_HYPER)

// Custom codes n combos
// Part 1: window management
#define KC_WSL LCTL(LGUI(KC_LEFT))
#define KC_WSR LCTL(LGUI(KC_RIGHT))
#define SWITCH LGUI(KC_TAB)
#define MOUSESEMI LT(_MOUSE,KC_SCLN) 

// Part 2: Code
#define REFS LCTL(LSFT(KC_G))

// Part 3: Hypers - used with Keyboard Maestro (https://www.keyboardmaestro.com/)
#define ARC    HYPR(KC_A)
#define TEXTS  HYPR(KC_T)
#define BIBLE  HYPR(KC_B)
#define FINDER HYPR(KC_F)
#define EMAIL  HYPR(KC_E)
#define CAL    HYPR(KC_C)


// TODOS
// 1. Make a hyper shortcut that is dedicated to launching apps. 
  // Hyper+...
    // E = email, T = texts, B = browser, C = calendar, M = music, R = reminders, G = bible, W = weather


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x6_right(
     KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_EQL,
     KC_TAB, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
     KC_BSPC, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,MOUSESEMI,KC_QUOT,
     KC_ESC, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
     KC_LCTL,KC_LGUI, KC_LALT,LOWER,                                                     LOWER, HYPER,_ARROWS, KC_EQL,
                        MT(MOD_LSFT, KC_ENT), LT(_RAISE,KC_DEL),                         KC_RGUI, LT(_RAISE,KC_SPC)
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
       QK_BOOT,_______,_______,_______,_______,_______,                        _______,_______,SWITCH,_______,KC_MPLY ,KC_VOLD,
       _______,_______,_SCROLL,_______,_______,_______,                         _______,KC_WSL,KC_UP,KC_WSR,_______,_______,
       _______,KC_F11 ,KC_F10 ,LSFT(KC_F11),_TRPLCLK,_DBLCLK,                        _______,KC_LEFT ,KC_DOWN,KC_RIGHT,_______,_______,
       _______,KC_F12,LSFT(KC_F12),REFS,                                       KC_HOME,KC_PGDOWN, KC_PGUP,KC_END,
                                             _______,_______,        _______,_______
  ), 
  
    [_MOUSE] = LAYOUT_5x6_right(
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,                         _______,KC_MS_BTN1,KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN4,KC_MS_BTN5,
       _______,_______,_______,_______,_______,_______,                     KC_MS_BTN1,KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN4,KC_MS_BTN5,_______,
       _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                               _______,_RAISE,                 _______,_RAISE
  ),

    [_HYPER] = LAYOUT_5x6_right(
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______, EMAIL ,_______, TEXTS ,                        _______,_______,_______,_______,_______,_______,
       _______,  ARC  ,_______,_______,FINDER ,_______,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,  CAL  ,_______, BIBLE ,                        _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                             _______,_______,        _______,_______
  ),
};

/* For when dual trackballs arrive, insert this for dual trackball support. Want to make left trackball into multi-function ball: 
Press A = go back to regular scrolling
Press S = 
Press D = cursor moving
So there won't be a 'default' layer, but a bunch of toggles between these different functions. That is the hope. 

// source: https://docs.qmk.fm/#/feature_pointing_device
*/
void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 300); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 101); //Set cpi on right side to a reasonable value for mousing.
}

#define CHARYBDIS_DRAGSCROLL_BUFFER_SIZE 15
#define CHARYBDIS_POINTER_ACCELERATION_FACTOR 24
#define DISPLACEMENT_WITH_ACCELERATION(d) (CONSTRAIN_HID(d > 0 ? d * d / CHARYBDIS_POINTER_ACCELERATION_FACTOR + \
                                            d : -d * d / CHARYBDIS_POINTER_ACCELERATION_FACTOR + d))



report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    static int16_t scroll_buffer_x = 0;
    static int16_t scroll_buffer_y = 0;
    static report_mouse_t temp_report; 

    if (!(has_mouse_report_changed(&temp_report,&left_report)))
    {
      return pointing_device_combine_reports(left_report, right_report);
    }

    if ((left_report.x == 0) && (left_report.y == 0 ))
    {
      return pointing_device_combine_reports(left_report, right_report);
    }
    
    if (set_scrolling)
    {
      scroll_buffer_x += left_report.x;
      scroll_buffer_y -= left_report.y;

      left_report.x = 0;
      left_report.y = 0;


      if (abs(scroll_buffer_x) > CHARYBDIS_DRAGSCROLL_BUFFER_SIZE) {
        left_report.h = scroll_buffer_x > 0 ? 1 : -1;
        scroll_buffer_x = 0;
      }
      if (abs(scroll_buffer_y) > CHARYBDIS_DRAGSCROLL_BUFFER_SIZE) {
        left_report.v = scroll_buffer_y > 0 ? 1 : -1;
        scroll_buffer_y = 0;
      }
    }
    temp_report = left_report;
    return pointing_device_combine_reports(left_report, right_report);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == _SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    else if (keycode == _ARROWS && record->event.pressed) {
        set_arrows = !set_arrows;
    }
    else if (keycode == _DBLCLK && record->event.pressed) {
        SEND_STRING(SS_TAP(X_BTN1) SS_TAP(X_BTN1));
        // SEND_STRING("{}" SS_TAP(X_LEFT));
    }
    else if (keycode == _DBLCLK && record->event.pressed) {
        SEND_STRING(SS_TAP(X_BTN1) SS_TAP(X_BTN1) SS_TAP(X_BTN1));
    }
    return true;}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
};

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