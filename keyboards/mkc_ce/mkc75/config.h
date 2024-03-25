/*
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

/*******************************************************************
 * ,--.   ,--.  ,---.  ,------. ,--.  ,--.,--.,--.  ,--. ,----.    *
 * |  |   |  | /  O  \ |  .--. '|  ,'.|  ||  ||  ,'.|  |'  .-./    *
 * |  |.'.|  ||  .-.  ||  '--'.'|  |' '  ||  ||  |' '  ||  | .---. *
 * |   ,'.   ||  | |  ||  |\  \ |  | `   ||  ||  | `   |'  '--'  | *
 * '--'   '--'`--' `--'`--' '--'`--'  `--'`--'`--'  `--' `------'  *
 *                                                                 *
 * This code was not provided, supported nor endorsed by Mykeyclub.*
 * This is a community project to let mkc75 owners easily use QMK  *
 * on their keyboards, as intended when they bought it.            *
 *******************************************************************/


/*
 *                             P P
 *             P P   P P P P P A A
 *             B B   B B B B B 1 1
 *         . . 9 8 . 7 6 5 4 3 5 4
 *       ,-----L-----o-o-o-o-o-o---.
 *      .| 1     5         0       |.
 *  PC13 |       4         4    35 |.
 *  PC14 |                         | PA13
 *  PC15 |                         | PA12
 *   PF0 | 5                       | PA11
 *   PF1 |        STM32F072        o PA10
 *      .|                      30 o PA9
 *      .|                         o PA8
 *      .|                         o PB15
 *   PA0 o 10                      o PB14
 *   PA1 o     1         2         o PB13
 *   PA2 x     5         0      25 o PB12
 *       '-------o-o-o-o---o-o-----'
 *         P P P P P P P P P P . .
 *         A A A A A B B B B B
 *         3 4 5 6 7 0 1 2 1 1
 *                         0 1
 */

#pragma once

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { B7, B6, B5, B4, B3, A15 }
#define MATRIX_COL_PINS { B12, B13, B14, B15, A8, A9, A10, B11, B10, B1, B0, A7, A6, A0, A1 }
/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* NKRO */
#define FORCE_NKRO

/* Key leds */
// #define LED_CAPS_LOCK_PIN A2

/* Led display */
#define WS2812_DI_PIN B9
#define RGBLIGHT_LED_COUNT 5
#define RGBLIGHT_HUE_STEP 4
#define RGBLIGHT_LIMIT_VAL 128
#define RGBLIGHT_DEFAULT_ON false
