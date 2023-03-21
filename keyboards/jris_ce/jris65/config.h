/*
Copyright 2023 QMK jris community

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
 * This code was not provided, supported nor endorsed by Irislab.  *
 * This is a community project to let jris65 owner easely use QMK  *
 * on their keyboards, as intended when they bought it.            *
 *******************************************************************/


/*
 *               P P P P P P
 *               F F F F F F
 *         . . . 0 1 4 5 6 7 . .
 *       ,-----------------------.
 *   PE6 | 1       0         5   | .E2
 *      .|         4         3   | PC7
 *    D- |                       | PC6
 *    D+ |                    30 | PB6
 *      .| 5                     | PB5
 *      .|      ATmega32U4       | PB4
 *      .|                       | PD7
 *   PB0 |                       | .D6
 *   PB1 |                    25 | .D4
 *   PB2 | 10    1         2     | .
 *   PB3 |       5         0     | .
 *       '-----------------------'
 *         P . . . . . P P P . .
 *         B           D D D D D
 *         7           0 1 2 3 5
 */
#pragma once

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { F7, F6, F5, B2, F4 }
#define MATRIX_COL_PINS { B6, C6, C7, F1, F0, E6, B0, B1, B3, B7, D2, D1, D0, D7, B4, B5 }
/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* NKRO */
#define FORCE_NKRO
