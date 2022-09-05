/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "bcotton.h"





// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |     ' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |Adjust| Nav  | Space|      |  |      | Bksp | Sym  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT_stack(
     KC_TAB,      KC_Q ,       KC_W,        KC_E,        KC_R,        KC_T ,
     CTL_ESC,     LCTL_T(KC_A),LALT_T(KC_S),LGUI_T(KC_D),KC_F,        LSFT_T(KC_G),
     KC_LSFT,     KC_Z,        KC_X,        KC_C,        KC_V ,       KC_B , ADJUST,_______,
                               S_GUI_A,  NUM, NAV, MT(HYPER,KC_SPC) , _______   ,

                                                     KC_Y,   KC_U , KC_I ,       KC_O ,       KC_P ,            KC_BSPC,
                                                     RSFT_T(KC_H),  KC_J,        RGUI_T(KC_K),RALT_T(KC_L),RCTL_T(KC_SCOLON),KC_QUOT,
                         _______ , _______,          KC_N,   KC_M,  KC_COMMA,    KC_DOT,      TD(DANCE_3),      KC_RSFT,
                         HYPER , KC_BSPC , SYM, HYPER, _______
    ),



/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |Back  |T/left|T/right| Fwd | VolDn| VolUp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |  ←   |   ↓  |  ↑   |   →  | Enter| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT_stack(
      _______, _______, _______, _______, _______, _______,
      _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,
      _______, _______, _______, _______, _______, _______, _______,_______,
                                 _______, _______, _______, _______, _______,


                                                        B_BACK, TAB_LEFT, TAB_RIGHT, B_FORWARD,  KC_VOLD, KC_VOLU,
                                                        KC_LEFT,KC_DOWN,  KC_UP,     KC_RGHT,    KC_ENTER, KC_INS,
                                      _______, _______, _______, _______,  _______, _______,  _______,  _______,
                                      _______, _______, _______, _______, _______
    ),


/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  '   |  <   |  >   |  "   |  .   |                              |   &  |  ::  |  [   |  ]   |  %   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  !   |  -   |  +   |  =   |  #   |                              |   |  |  :   |  (   |  )   |  ?   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   ^  |  /   |  *   |  \   | ../  |      |      |  |      |      |   ~  |  $   |  {   |  }   |  @   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT_stack(
    _______,  KC_GRV,  KC_LT,    KC_GT,   KC_DQT,   KC_DOT ,
    _______,  KC_EXLM, KC_MINUS, KC_PLUS, KC_EQUAL, KC_HASH,
    _______, KC_CIRC,  KC_SLASH, KC_ASTR, KC_BSLS,  UPDIR, _______, _______,
                       _______, _______, _______, _______, _______,

                                                            KC_AMPR, DOUBLE_COLON,    KC_LBRC, KC_RBRC ,KC_PERC, _______,
                                                            KC_PIPE, KC_COLN,         KC_LPRN, KC_RPRN, KC_QUES, _______,
                                        _______, _______,  KC_TILD, KC_DLR,          KC_LCBR, KC_RCBR, KC_AT,   _______,
                                        _______, _______, _______, _______, _______

    ),

/*
 * Num Layer: Numbers on a numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |   (  |  )   |      |  .   |                              |      |  7   |  8   |  9   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |   -  |  +   |   =  |      |                              |   .  |  4   |  5   |  6   | Ret  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |   /  |  *   |      |      |      |      |  |      |      |   0  |  1   |  2   |  3   |  .   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT_stack(
      _______, _______, KC_LPRN, KC_RPRN, _______, KC_DOT,
     _______, _______, KC_MINUS, KC_PLUS, KC_EQUAL, _______,
     _______, _______, KC_SLASH, KC_ASTR, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,

                                                                    _______, KC_7, KC_8, KC_9, _______, _______,
                                                                    KC_DOT,  KC_4, KC_5, KC_6, KC_ENTER, _______,
                                                  _______, _______, KC_0,    KC_1, KC_2, KC_3, KC_DOT,   _______,
                                                  _______, _______, _______, _______, _______
    ),


/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT_stack(
      _______, _______, _______, QWERTY , _______, _______,
      _______, _______, _______, _______ , _______, _______,
      _______, _______, _______, _______, _______, _______,_______,_______,
                                 _______, _______, _______,_______, _______,

                                                                     _______, _______, _______,  _______, _______,_______,
                                                                     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
                                                   _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                                   _______, _______, _______, _______, _______
    ),

};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
            tap_code(KC_MS_WH_UP);
        }
    }
    return false;
}
#endif




layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
        case _QWERTY:
            rgblight_setrgb (0x20,  0x20, 0x20);
            break;
        case _NAV:
            rgblight_setrgb(0xFF, 0xFF, 0x00);
            break;
        case _NUM:
            rgblight_setrgb(0x00, 0xFF, 0x00);
            break;
        case _SYM:
            rgblight_setrgb(0x00, 0x00, 0xFF);
            break;
        default:
            rgblight_setrgb (0x20,  0x20, 0x20);
    }
#endif
    // return update_tri_layer_state(state, _NAV, _SYM, _NUM);
    return state;
}
