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

#pragma once

#include "quantum.h"

/*
 * This code only support the soldered/wired board in the specific
 * configuration I personally use.
 */

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

/*
 *   ┌───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┐
 *   │000│ |001│002│003│004│ |005│006│007│008│ |009│010│011│012│ |led│
 *   ├───┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┼───┼───┼───┼───┼─┴─┬─┴─┬─┴─┬─┴───┴─┼───┤
 *   │100│101│102│103│104│105│106│107│108│109│110│111│112│114    │014│
 *   ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 *   │200  │201│202│203│204│205│206│207│208│209│210│211│212│213  │214│
 *   ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 *   │300   │301│302│303│304│305│306│307│308│309│310│311│313     │314│
 *   ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 *   │400     │402│403│404│405│406│407│408│409│410│411│412   │413│414│
 *   ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 *   │500 │501 │502 │507                     │510 │511 │ │512│513│514│
 *   └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */

