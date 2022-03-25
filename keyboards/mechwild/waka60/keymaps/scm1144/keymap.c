/* Copyright 2021 Kyle McCreery
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

// Keycodes
enum waka60_keycodes {
  _DUMMY = SAFE_RANGE,

	OOSSUU,	// OSU Orange
};

// Variables

//Lighting Layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {2,1,240,0,50} // Light LED 3 white when the caps lock is active
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer // Later layers take precedence
);

// Layers
enum waka60_layers {
	DEFAULT,
	LOWER,
	RAISE,
	FUNCT,
	LIGHT,
}; 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default
 * ,------------------------------------------------------        ------------------------------------------------------.
 * |  `     |    1   |    2   |    3   |    4   |    5   |        |    6   |    7   |    8   |    9   |    0   |  Bksp  |
 * |--------+--------+--------+--------+--------+--------+        +---_----+--------+--------+--------+--------+--------|
 * |  Esc   |    Q   |    W   |    E   |    R   |    T   |        |    Y   |    U   |    I   |    O   |    P   |  Del   |
 * |--------+--------+--------+--------+--------+--------+        +---_----+--------+--------+--------+--------+--------|
 * |  Tab   |    A   |    S   |    D   |    F   |    G   |        |    H   |    J   |    K   |    L   |    ;   |  Enter |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Shift |    Z   |    X   |    C   |    V   |    B   |  MPLY  |    N   |    M   |    ,   |    .   |   Up   |  / Sft |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  Ctrl  | Light  |  Alt   |  GUI   | Lower  |          Space           | Raise  | Funct  |  Left  |  Down  | Right  |
 * `--------------------------------------------------------------------------------------------------------------------'
 */
[DEFAULT] = LAYOUT(
    KC_GRV,  KC_1,      KC_2,    KC_3,    KC_4,      KC_5,            KC_6,   KC_7,      KC_8,      KC_9,    KC_0,    KC_BSPC,
    KC_ESC,  KC_Q,      KC_W,    KC_E,    KC_R,      KC_T,            KC_Y,   KC_U,      KC_I,      KC_O,    KC_P,    KC_DEL,
    KC_TAB,  KC_A,      KC_S,    KC_D,    KC_F,      KC_G,            KC_H,   KC_J,      KC_K,      KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,      KC_X,    KC_C,    KC_V,      KC_B,   KC_MPLY, KC_N,   KC_M,      KC_COMM,   KC_DOT,  KC_UP,   RSFT_T(KC_SLSH),
    KC_LCTL, TT(LIGHT), KC_LALT, KC_LGUI, TT(LOWER), KC_SPC, KC_SPC,  KC_SPC, TT(RAISE), TT(FUNCT), KC_LEFT, KC_DOWN, KC_RGHT
),
/* Lower
 * ,------------------------------------------------------        ------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |    7   |    8   |    9   |        |        |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |    4   |    5   |    6   |   +    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |    1   |    2   |    3   |   -    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |--------|                          |        |    0   |    .   | Enter  |        |
 * `--------------------------------------------------------------------------------------------------------------------'
 */
[LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_PENT, _______
),
/* Raise
 * ,------------------------------------------------------        ------------------------------------------------------.
 * |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |        |   F7   |   F8   |   F9   |   F10  |   F11  |   F12  |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |    [   |   ]    |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |    +   |   '    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |    -   |   \    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |                          |--------|        |        |    =   |        |
 * `--------------------------------------------------------------------------------------------------------------------'
 */
[RAISE] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_PLUS, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, RSFT_T(KC_BSLS),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EQL,  _______
),
/* Function
 * ,------------------------------------------------------        ------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |  Home  |Page Up |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |  End   |Page Dn |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * | CapsLck|        |        |        |        |        |        |        |        |        |        |  Mute  |  MPLY  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | NumLck |        |        |        |        |        |        |        |        |        |        | Vol Up |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |                          |        |--------|  MPRV  | Vol Dn |  MNXT  |
 * `--------------------------------------------------------------------------------------------------------------------'
 */
[FUNCT] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_HOME, KC_PGUP,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_END,  KC_PGDN,
    KC_CAPS, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_MUTE, KC_MPLY,
    KC_NUM,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT 
),
/* Lighting
 * ,------------------------------------------------------        ------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        | Toggle |        |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | OOSSUU |  Mod   |        |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |  RMOD  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | Hue Up | Sat Up | Hue Up |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |--------|        |        |        |                          |        | Hue Dn | Sat Dn | Hue Dn |        |
 * `--------------------------------------------------------------------------------------------------------------------'
 */
[LIGHT] = LAYOUT(
    _______, RGB_M_P, RGB_M_B, _______, _______, _______,          _______, _______, _______, _______,  RGB_TOG, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______,  OOSSUU,  _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI,  RGB_VAI, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD,  RGB_VAD, _______
)
};

// Old layers
/* Mouse
 * ,------------------------------------------------------        ------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        | Acl 2  |        |        |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | Acl 1  | Scr U  |  M BT2 |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | Acl 0  | Scr Dn |  M BT1 |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | Scr L  |  M Up  |  Scr R |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |--------|        |        |        |                          |        |        |  M Lf  |  M Dn  |  M Ri  |
 * `--------------------------------------------------------------------------------------------------------------------'
 */
/*
[MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_ACL2, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_ACL1, KC_WH_U, KC_BTN2,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_ACL0, KC_WH_D, KC_BTN1,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
),
*/

/* Template
 * ,------------------------------------------------------        ------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |                          |        |        |        |        |        |
 * `--------------------------------------------------------------------------------------------------------------------'
 */
/*[TEMPLATE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
*/

//Set LEDs when plugged in
void keyboard_post_init_user(void) {
  // Due to a "it is a quirk of the ws2812b + blackpill" need to turn on/off the LEDs
  // to not have the first LED bright green
  // rgblight_enable();
  // rgblight_disable();
  
  // Enable the LED Layers
  rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}

// Macros for key presses
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    
    // Set LEDs to OSU orange
    case OOSSUU:
      if (record->event.pressed) {
        rgblight_sethsv(24,255,250);
      }
      return false;

    default:
      return true; // Process all other keycodes normally
  }
}

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    switch (index) {
        case 0:
            if (layer_state_is(DEFAULT)) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            else if (layer_state_is(FUNCT)){
                if (clockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDN);
                }
            }
            else if (layer_state_is(LIGHT)){
                if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
            }
        break;
    }
    return true;
}
#endif
