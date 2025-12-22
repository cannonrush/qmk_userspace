#include QMK_KEYBOARD_H

#define HR_N LALT_T(KC_N)
#define HR_R LALT_T(KC_R)
#define HR_T LSFT_T(KC_T)
#define HR_S LALT_T(KC_S)
#define HR_H RALT_T(KC_H)
#define HR_A RSFT_T(KC_A)
#define HR_E RALT_T(KC_E)
#define HR_I RALT_T(KC_I)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_TAB,   KC_B,     KC_L,     KC_D,     KC_C,     KC_V,             KC_J,     KC_Y,     KC_O,     KC_U,     KC_QUOT,  KC_EQL,
        KC_TAB,   HR_N,     HR_R,     HR_T,     HR_S,     KC_G,             KC_P,     HR_H,     HR_A,     HR_E,     HR_I,     KC_ENT,
        OS_LSFT,  KC_X,     KC_Q,     KC_M,     KC_W,     KC_Z,             KC_K,     KC_F,     KC_COMM,  KC_DOT,   KC_SLSH,  OS_RSFT,
                                                MO(1),    KC_SPC,           KC_BSPC,  MO(2)
    ),
    [1] = LAYOUT(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,            KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
        KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,          KC_7,     KC_8,     KC_9,     KC_MINS,  KC_SLSH,  KC_F12,
        _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,          KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_ASTR,  KC_BSPC,
        _______,  _______,  KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,          KC_1,     KC_2,     KC_3,     KC_DOT,   KC_EQL,   KC_ENT,
                                                _______,  _______,          _______,  KC_0
    ),
    [2] = LAYOUT(
        RM_TOGG,  QK_KB,    RM_NEXT,  RGB_M_P,  RM_VALD,  RM_VALU,          _______,  _______,  _______,  _______,  _______,  QK_BOOT,
        _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,  _______,          KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   _______,  _______,
        _______,  KC_MPRV,  KC_MNXT,  KC_MSTP,  KC_MPLY,  _______,          KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,
        _______,  _______,  _______,  _______,  RM_HUED,  RM_HUEU,          _______,  C(S(KC_TAB)),C(KC_TAB),_______,_______, _______,
                                                _______,  _______,          _______,  _______
    ),
    [4] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_N,     KC_R,     HR_T,   KC_S,     _______,          _______,  KC_H,     HR_A,   KC_E,     KC_I,     _______,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,          _______,  _______
    ),
    // [0] = LAYOUT(
    //     KC_GRV,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MINS,
    //     KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_QUOT,  KC_EQL,
    //     KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_ENT,
    //     OS_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  KC_COMM,  KC_DOT,   KC_SLSH,  OS_RSFT,
    //                                             XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX
    // ),
    // [0] = LAYOUT(
    //     _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
    //     _______,  KC_B,     KC_L,     KC_D,     KC_C,     KC_V,             KC_J,     KC_Y,     KC_O,     KC_U,     _______,  KC_EQL,
    //     _______,  HR_N,   HR_R,   HR_T,   HR_S,   KC_G,             KC_P,     HR_H,   HR_A,   HR_E,   HR_I,   KC_ENT,
    //     _______,  KC_X,     KC_Q,     KC_M,     KC_W,     KC_Z,             KC_K,     KC_F,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
    //                                             MO(_NAV), KC_SPC,           KC_BSPC,  MO(_SYM)
    // ),
    // [9] = LAYOUT(
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //                                             _______,  _______,          _______,  _______
    // ),
};

// https://docs.qmk.fm/tap_hold#chordal-hold-handedness
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
          'L',      'L',      'L',      'L',      'L',      'L',              'R',      'R',      'R',      'R',      'R',      'R',
          'L',      'L',      'L',      'L',      'L',      'L',              'R',      'R',      'R',      'R',      'R',      'R',
          'L',      'L',      'L',      'L',      'L',      'L',              'R',      'R',      'R',      'R',      'R',      'R',
          'L',      'L',      'L',      'L',      'L',      'L',              'R',      'R',      'R',      'R',      'R',      'R',
                                                  '*',      '*',              '*',      '*'
    );

static uint16_t key_press_keycode = KC_NO;

// https://docs.qmk.fm/understanding_qmk
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        key_press_keycode = keycode;
    }
    return true;
}

// https://docs.qmk.fm/tap_hold#hold-on-other-key-press
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_N:
        case HR_R:
        case HR_S:
        case HR_H:
        case HR_E:
        case HR_I:
            // For snappier word and line deletion, resolve relevant modifiers
            // to "hold" immediately when backspace is pressed
            return key_press_keycode == KC_BSPC;
        default:
            return false;
    }
}

// https://docs.qmk.fm/tap_hold#is-flow-tap-key
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_B ... KC_S: // Exclude LSFT ("A")
        case KC_U ... KC_Z: // Exclude RSFT ("T")
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// https://docs.qmk.fm/tap_hold#tapping-term
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case HR_T:
//         case HR_A:
//             return TAPPING_TERM;
//         default:
//             return TAPPING_TERM;
//     }
// }

// https://docs.qmk.fm/features/combo
// const uint16_t PROGMEM ou_combo[] = {KC_O, KC_U, COMBO_END};
// const uint16_t PROGMEM yo_combo[] = {KC_Y, KC_O, COMBO_END};
// combo_t key_combos[] = {
//     COMBO(ou_combo, KC_BSPC),
//     COMBO(yo_combo, KC_BSPC),
// };

