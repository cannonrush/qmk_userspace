#pragma once

#include "rgb.h" // RGB Matrix configuration

#define TAPPING_TERM 200  // https://docs.qmk.fm/tap_hold#tapping-term
#define PERMISSIVE_HOLD   // https://docs.qmk.fm/tap_hold#permissive-hold
#define CHORDAL_HOLD      // https://docs.qmk.fm/tap_hold#chordal-hold
#define FLOW_TAP_TERM 100 // https://docs.qmk.fm/tap_hold#flow-tap

// "0" value removes auto-repeat from dual-role keys, which is necessary to
// support quick successive tap -> hold actions
#define QUICK_TAP_TERM 0 // https://docs.qmk.fm/tap_hold#quick-tap-term

// Enabled to support early resolution of CTL, GUI and ALT when followed by BSPC
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY // https://docs.qmk.fm/tap_hold#hold-on-other-key-press
#define TAPPING_TERM_PER_KEY            // https://docs.qmk.fm/tap_hold#tapping-term

// https://docs.qmk.fm/features/caps_word#how-do-i-enable-caps-word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// https://github.com/qmk/qmk_firmware/tree/master/keyboards/zsa/voyager#voyager-customization
#define VOYAGER_USER_LEDS

