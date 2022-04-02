/*
Copyright 2021 Kyle McCreery

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6D77 // mw = "MechWild"
#define PRODUCT_ID      0x1709
#define DEVICE_VER      0x0101
#define MANUFACTURER    MechWild
#define PRODUCT         Waka60

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

#define EEPROM_I2C_24LC64

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { B8, B4, B3, B9, A15, B12, B13, B14, B15, A8 }
#define MATRIX_COL_PINS { B10, B1, B0, A7, A6, A5, A4 }
#define UNUSED_PINS

/* encoder pins */
#define ENCODERS_PAD_A { A3 }
#define ENCODERS_PAD_B { A2 }

/* encoder resolution */
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* RGB settings, uncomment this define to enable RGB */
#define RGB_DI_PIN A1
#ifdef RGB_DI_PIN
#	define RGBLED_NUM 3
#	define RGBLIGHT_HUE_STEP 10
#	define RGBLIGHT_SAT_STEP 17
#	define RGBLIGHT_VAL_STEP 17
#	define RGBLIGHT_LIMIT_VAL 255
#	define RGBLIGHT_SLEEP
#	define RGBLIGHT_DEFAULT_HUE 24
#	define RGBLIGHT_DEFAULT_SAT 255	// 0->255
#	define RGBLIGHT_DEFAULT_VAL 250	// 0->255
# define RGBLIGHT_EFFECT_BREATHING
//#define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#define RGBLIGHT_EFFECT_SNAKE
//#define RGBLIGHT_EFFECT_KNIGHT
//	#define RGBLIGHT_EFFECT_CHRISTMAS
//	#define RGBLIGHT_EFFECT_STATIC_GRADIENT
//	#define RGBLIGHT_EFFECT_RGB_TEST
//  #define RGBLIGHT_EFFECT_ALTERNATING
//	#define RGBLIGHT_EFFECT_TWINKLE
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
# define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
# define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
# define RGBLIGHT_EFFECT_BREATHE_MAX    100   // 0 to 255
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

/* Behaviors to Change */
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define RGBLIGHT_LAYERS
//#define RGBLIGHT_MAX_LAYERS 1
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
