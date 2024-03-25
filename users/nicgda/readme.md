Nicolas' (nicgda) read me

# Keyboards

- gmmk/pro/rev1/ansi/keymaps/nicgda/
- idobao/id80/v2/ansi/keymaps/nicgda/
- jris_ce/jris65/keymaps/nicgda/
- mkc_ce/mkc75/keymaps/nicgda/

Being a mac user, the keymap are configured accordingly... almost.

The left side is standard (Control, Option, Command), but on the left of the
spacebar, I use Command and MO (momentary layer selection).

I use the media keys by default and have the F keys on a layer. I very often
use the Mission Control (F3 key), F4 mapped to F16 for Notification Center (?),
and the volumes (F11 and F12).

# Build

./util/docker_build.sh gmmk/pro/rev1/ansi:nicgda

./util/docker_build.sh idobao/id80/v2/ansi:nicgda

./util/docker_build.sh jris_ce/jris65:nicgda

./util/docker_build.sh mkc_ce/mkc75:nicgda

# Features

The common code is in the users/nicgda/ directory.

## Nic mode

Not a very original name, but a little feature for myself.

The goal if to have a visual notification when the work timer is running.
I use Timery and start/stop the timer (and many other things) using two
Shortcuts listening for F17 and F18.

Using a single custom keycode (`KC_NTGL`), the F17/F18 is sent depending on
the current state of the nic mode. The process_record_user() function
handling this is in the common nicgda.c file.

For the notification, the underglow is used on the ID80 and mkc75 (rgb light) and 
the side leds on the GMMK pro (rgd matrix).

### HID communication

The function `raw_hid_receive()` handles the simple HID protocol to enable,
disable the nic mode and also to get or set the current led colour and to
save it in the EEPROM.  The initial goal was to be able to change colour
based on the timer used.  I use a Python script to send the commands.

TODO: Publish and link the project here.

### Setting the leds

The function `rgb_matrix_indicators_advanced_user()` is used to set the
side and underglow leds state and colour.

### Rotary encoder

The encoder code can be fount in the `encoder_update_user()` function.
Beside the normal volume, the nic mode led colour and intensity can be
changes with the encoder, it's way easier to find a nice colour that way
compared to trying new values.
The Ctrl, Shift and Alt modifiers are used to select which of the HSV value
is changed. For ease of usage, I also mapped these modifier just above the
MO key, for an easy single hand manipulation.


### EEPROM

The function `save_nic_mode()` saves the HSV value (mostly) in the 32 bits
(yes, bits, not bytes) user section of the EEPROM.

The values are read on startup, in the `keyboard_post_init_user()` function.

## Rotary encoder

Beside the nic mode handled in upper layers, the rotary is used for the
classic volume change.

Using the left Control modifier, it can also be used to scroll a page un
and down, just like the mouse wheel. Totally useless, but quite fun.

With two encoders, I would probably emulate a Etch A Sketch :-)

## Mac Mission Control

This is now supported directly with KC_MCTL, no need for custom code anymore.

## Keymaps notes

The `_______` key (7 underscores) is the equivalent of `KC_TRNS`, which will use
the first key found on a lower layer.

The `#######` key (7 #) is used to deactivate a key on that layer.

## Layer key colour

For the GMMK pro, my only keyboard who supports per key led setting, I change the
colour of the keys mapped specifically on that layer. The `KC_TRNS` are ignored.
Since the GMMK pro rgb matix is used for the key and side leds, the led config
flags are validated. The same principle is use to enable only the side led.

The code is in the `rgb_matrix_indicators_advanced_user()` function.

## WITH_ESC_TILDE

I need the ESC key and tilde (~) way more often then expected. I also use the
grave (`) a lot while writing in French. The WITH_ESC_TILDE let me use the ESC
key as follow:
 - Normal: KC_ESC
 - Shift: KC_TILDE
 - L_GUI or R_GUI: KC_GRAVE
 
To use this feature, just add 

    #define WITH_ESC_TILDE
    
in the *config.h* file next to your *keymap.c*.

# The little thing I always forget

git rebase --onto 0.23.3 0.22.12

