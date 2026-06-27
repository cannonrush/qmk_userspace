#pragma once

#define TAPPING_TERM 200   // https://docs.qmk.fm/tap_hold#tapping-term
#define PERMISSIVE_HOLD    // https://docs.qmk.fm/tap_hold#permissive-hold
#define CHORDAL_HOLD       // https://docs.qmk.fm/tap_hold#chordal-hold
#define FLOW_TAP_TERM 75   // https://docs.qmk.fm/tap_hold#flow-tap
#define QUICK_TAP_TERM 100 // https://docs.qmk.fm/tap_hold#quick-tap-term

// Enabled to support early resolution of CTL, GUI and ALT when followed by BSPC
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY // https://docs.qmk.fm/tap_hold#hold-on-other-key-press

// https://github.com/qmk/qmk_firmware/tree/master/keyboards/zsa/voyager#voyager-customization
#define VOYAGER_USER_LEDS

#include "rgb.h" // RGB Matrix configuration
