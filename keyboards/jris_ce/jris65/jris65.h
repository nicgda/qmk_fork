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
 * This is a community project to let jris65 owner easily use QMK  *
 * on their keyboards, as intended when they bought it.            *
 *******************************************************************/

#pragma once

#include "quantum.h"

#define ____ KC_NO

/*
 *              ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐    ┌───────┐
 *              │000│001│002│003│004│005│006│007│008│009│010│011│012│013│014│015│    │014    │ 2u Backspace
 *              ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤    └─┬─────┤
 *              │100  │101│102│103│104│105│106│107│108│109│110│111│112│113  │114│      │213  │
 *  2.25u       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤   ┌──┴┐    │ ISO Enter
 *  LShift      │200   │201│202│203│204│205│206│207│208│209│210│211│213     │214│   │212│    │
 * ┌────────┐   ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤   └───┴────┘
 * │300     │   │300 │301│302│303│304│305│306│307│308│309│310│311│312   │313│314│
 * └────────┘   ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 *              │400 │401 │402 │403                     │410 │411 │ │412│413│414│
 *              └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 *              ┌─────┬───┬─────┬───────────────────────────┬─────┐
 *              │400  │401│402  │403                        │411  │ Tsangan
 *              └─────┴───┴─────┴───────────────────────────┴─────┘
 */

/* General layout */
#define LAYOUT_all( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

/* ANSI layout */

#define LAYOUT_65_ansi( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213, K214,       \
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, ____, K213, K214, ____ }, \
    { K300, ____, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_ansi_split_bs( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213, K214,       \
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, ____, K213, K214, ____ }, \
    { K300, ____, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_ansi_split_lshift( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, ____, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_ansi_split_bs_lshift( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, ____, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

/* ANSI tsangan (7U spacebar) layout */

#define LAYOUT_65_ansi_tsangan( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213, K214,       \
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                           K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, ____, K213, K214, ____ }, \
    { K300, ____, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, ____, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_ansi_tsangan_split_bs( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213, K214,       \
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                           K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, ____, K213, K214, ____ }, \
    { K300, ____, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, ____, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_ansi_tsangan_split_lshift( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                           K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, ____, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, ____, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_ansi_tsangan_split_bs_lshift( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                           K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, ____, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, ____, K411, K412, K413, K414, ____ }  \
}

/* ISO layout */

#define LAYOUT_65_iso( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, ____, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_iso_split_bs( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, ____, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_iso_split_lshift( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_iso_split_bs_lshift( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                     K410, K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, K410, K411, K412, K413, K414, ____ }  \
}

/* ISO tsangan (7U spacebar) layout */

#define LAYOUT_65_iso_tsangan( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                           K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, ____, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, ____, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_iso_tsangan_split_bs( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                           K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, ____, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, ____, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_iso_tsangan_split_lshift( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                           K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, ____, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, ____, K411, K412, K413, K414, ____ }  \
}

#define LAYOUT_65_iso_tsangan_split_bs_lshift( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K114,       \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       \
    K400, K401, K402, K403,                                           K411, K412, K413, K414        \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, ____, K114, ____ }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____ }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____ }, \
    { K400, K401, K402, K403, ____, ____, ____, ____, ____, ____, ____, K411, K412, K413, K414, ____ }  \
}
