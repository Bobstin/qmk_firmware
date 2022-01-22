// Developed by Justin Kahn. Adapted from the  Glorious GMMK Pro default layout. See Licence Below.

/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#include QMK_KEYBOARD_H
#include "print.h"
#include "features/caps_word.h"
#include "features/tap_dances.h"

// Left-hand home row mods
#define HMOD_A LGUI_T(KC_A)
#define HMOD_S LALT_T(KC_S)
#define HMOD_D LSFT_T(KC_D)
#define HMOD_F LCTL_T(KC_F)

// Right-hand home row mods
#define HMOD_J RCTL_T(KC_J)
#define HMOD_K RSFT_T(KC_K)
#define HMOD_L LALT_T(KC_L)
#define HMOD_SC RGUI_T(KC_SCLN)

// One shot shift
#define OS_LSFT OSM(MOD_LSFT)

// Custom keycodes
enum custom_keycodes {
    CAPSWRD = SAFE_RANGE,
    OTHER_KEYCODE,
};

// Tap dances
enum {
    TD_SQLD = 0,
    TD_SQLI,
    TD_SQLS,
    TD_SQLG,
    TD_SQLO,
    TD_SQLW,
    TD_SQLL,
    TD_SQLF,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SQLD] = ACTION_TAP_DANCE_FN(sql_d_dance),
    [TD_SQLI] = ACTION_TAP_DANCE_FN(sql_i_dance),
    [TD_SQLS] = ACTION_TAP_DANCE_FN(sql_s_dance),
    [TD_SQLG] = ACTION_TAP_DANCE_FN(sql_g_dance),
    [TD_SQLO] = ACTION_TAP_DANCE_FN(sql_o_dance),
    [TD_SQLW] = ACTION_TAP_DANCE_FN(sql_w_dance),
    [TD_SQLL] = ACTION_TAP_DANCE_FN(sql_l_dance),
    [TD_SQLF] = ACTION_TAP_DANCE_FN(sql_f_dance),
};

#define TDSQLD TD(TD_SQLD)
#define TDSQLI TD(TD_SQLI)
#define TDSQLS TD(TD_SQLS)
#define TDSQLG TD(TD_SQLG)
#define TDSQLO TD(TD_SQLO)
#define TDSQLW TD(TD_SQLW)
#define TDSQLL TD(TD_SQLL)
#define TDSQLF TD(TD_SQLF)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

\
    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.

    // The FN key is also used to switch layers. Press it plus a number key to switch to that layer permanently

    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.

    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
/*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
*/


    // Standard layout
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(3),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Layer with home row mods and one shot shift
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        CAPSWRD, HMOD_A,  HMOD_S,  HMOD_D,  HMOD_F,  _______, _______, HMOD_J,  HMOD_K,  HMOD_L,  HMOD_SC, _______,          _______,          _______,
        OS_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    // SQL Layer
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, TDSQLW,  _______, _______, _______, _______, _______, TDSQLI,  TDSQLO,  _______, _______, _______, _______,          _______,
        _______, _______, TDSQLS,  TDSQLD,  TDSQLF,  TDSQLG,  _______, _______, _______, TDSQLL,  _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    // Layer change layer + Bootloader + RGB controls
    [3] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, TO(1),   TG(2),   TO(3),   _______, _______, _______, _______, _______, _______, TO(0),   _______, _______, _______,          _______,
        _______, RGB_TOG, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, MO(3),   _______, RGB_SPD, RGB_RMOD, RGB_SPI
    )

};



// Volume knob ---------------------------------------------------------------------------------------
// clang-format on
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif // ENCODER_ENABLE


// Home row mods ---------------------------------------------------------------------------------------
// Key specific settings for mod tap interrupt
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HMOD_A:
        case HMOD_S:
        case HMOD_D:
        case HMOD_F:
        case HMOD_J:
        case HMOD_K:
        case HMOD_L:
        case HMOD_SC:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return true;
        default:
            // Force the mod-tap key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return false;
    }
}

// Key specific settings for tapping force hold
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HMOD_A:
        case HMOD_S:
        case HMOD_D:
        case HMOD_F:
        case HMOD_J:
        case HMOD_K:
        case HMOD_L:
        case HMOD_SC:
            return true;
        default:
            return false;
    }
}


// Caps word---------------------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  switch (keycode) {
    case CAPSWRD:
        print("Detected caps word");
        if (record->event.pressed){
            if (caps_word_get()){
                print("Caps word was on, turning it off");
                caps_word_set(false);
            } else {
                print("Caps word was off, turning it on");
                caps_word_set(true);
            }
        }
        break;
  }

  return true;
}

// Old mechanism using a combo
/*
enum combo_events {
  CAPS_COMBO,
  // Other combos...
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// Define the combos here
const uint16_t PROGMEM caps_combo[] = {KC_DOT, KC_C, COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO] = COMBO_ACTION(caps_combo),
  // Other combos...
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        print("Caps word turned on\n");
        caps_word_set(true);  // Activate Caps Word!
      }
      break;

    // Other combos...
  }
}

void caps_word_set_user(bool active) {
    print("Caps word state changed\n");
    rgb_matrix_set_color_all(255,0,0);
}
*/

// LED Controls---------------------------------------------------------------------------------------
void rgb_matrix_indicators_user(void) {
    if (caps_word_get()){
        rgb_matrix_set_color_all(RGB_GOLDENROD);
        return;
    }

    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case 0:
            rgb_matrix_set_color_all(36, 120, 37);
            break;
        case 1:
            rgb_matrix_set_color_all(57, 104, 179);
            break;
        case 2:
            rgb_matrix_set_color_all(RGB_YELLOW);
            break;
        case 3:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;
    }
}
