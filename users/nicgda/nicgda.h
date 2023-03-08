#pragma once
#include QMK_KEYBOARD_H

////////////////////
// Custom key codes
//
enum my_keycodes {
	KC_NTGL = SAFE_RANGE, // Nic mode toggle
    KC_NSAV, // Nic mode save
};


//////////////////////////
// Nic mode HDI commands
//

enum hid_nic_command {
    HNC_ON = 0x01,
    HNC_OFF,
    HNC_SET,
    HNC_GET,
    HNC_SAVE,
};
