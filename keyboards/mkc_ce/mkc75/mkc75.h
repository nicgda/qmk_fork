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

#define ____ KC_NO

/*
 * This code only support the soldered/wired board in the specific
 * configuration I personally use.
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

#define LAYOUT_ansi( \
     K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, \
     K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112 ,      K114, \
     K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, \
     K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \
     K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, \
     K500, K501, K502,                         K507,             K510, K511, K512, K513, K514  \
 ) { \
     { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014 }, \
     { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114 }, \
     { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214 }, \
     { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, ____, K313, K314 }, \
     { K400, ____, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414 }, \
     { K500, K501, K502, ____, ____, ____, ____, K507, ____, ____, K510, K511, K512, K513, K514 }  \
 }
