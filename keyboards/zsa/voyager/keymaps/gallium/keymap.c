#include QMK_KEYBOARD_H

/**
 * Do next:
 * TOOD: symbols layer (!)
 * TODO: add Home, End, Page Down and Page Up to the NAV layer
 *
 * Do later:
 * TODO: consider putting layer keys on the primary thumb buttons
 * TODO: figure out how to do key repeat for R, T, S, H, A, E and X
 * TODO: consider making secondary thumb buttons (or one of them) into leader keys
 * TODO: consider https://docs.qmk.fm/features/dynamic_macros (better to do this at the OS level?)
 * TODO: change start-up LED sequence, making the right half light up first (no way to override at
 *       user level, but we can modify the core repo and submit a PR)
 *
 * Thumb Shift:
 * - Doesn't work bilaterally, as it leads to "Space Shift" bigram on the left
 * - Can be placed on the primary right button, but this results in some awkward
 *   right-hand bigrams; still, could be worth it for fast typing
 */

enum layers {
    LAYER_BSE,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_FNC,
};

#define EX_FNC MO(LAYER_FNC)

#define EX_E LALT_T(KC_E)
#define EX_A LGUI_T(KC_A)
#define EX_C LCTL_T(KC_C)
#define EX_ENT LT(LAYER_NAV, KC_ENT)
#define EX_SPC LSFT_T(KC_SPC)

#define EX_SFT OS_RSFT
#define EX_TAB LT(LAYER_SYM, KC_TAB)
#define EX_J RCTL_T(KC_J)
#define EX_K RGUI_T(KC_K)
#define EX_L RALT_T(KC_L)

// #include "magic.c"
// #define MAGIC QK_ALT_REPEAT_KEY // or QK_AREP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BSE] = LAYOUT(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
        _______,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,             KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_SCLN,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,             KC_H,     KC_J,     KC_K,     KC_L,     KC_BSPC,  KC_QUOT,
        EX_FNC,   KC_DOT,   KC_Z,     KC_X,     KC_C,     KC_V,             KC_B,     KC_N,     KC_M,     KC_COMM,  KC_SLSH,  _______,
                                                EX_ENT,   KC_SPC,           OS_RSFT,  EX_TAB
    ),
    // [1] = LAYOUT(
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,          _______,  _______,  _______,  KC_MINS,  KC_SLSH,  _______,
    //     _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,          _______,  _______,  _______,  KC_PLUS,  KC_ASTR,  _______,
    //     _______,  _______,  KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,          _______,  _______,  _______,  KC_DOT,   KC_EQL,   _______,
    //                                             _______,  _______,          _______,  _______,
    // ),
    // [2] = LAYOUT(
    //     RM_TOGG,  QK_KB,    RM_NEXT,  RGB_M_P,  RM_VALD,  RM_VALU,          _______,  _______,  _______,  _______,  _______,  QK_BOOT,
    //     _______,  _______,  _______,  _______,  _______,  _______,          KC_PGUP,  KC_HOME,  _______,  KC_END,   _______,  _______,
    //     _______,  _______,  _______,  KC_MSTP,  _______,  _______,          KC_PGDN,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  RM_HUED,  RM_HUEU,          _______,  C(S(KC_TAB)),C(KC_TAB),_______,_______, _______,
    //                                             _______,  _______,          _______,  _______
    // ),
    [LAYER_SYM] = LAYOUT(
        KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,
        _______,  _______,  KC_LCBR,  KC_RCBR,  _______,  _______,          _______,  _______,  _______,  _______,  KC_DQT,   KC_PLUS,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  KC_RALT,  KC_RCTL,  KC_RGUI,  KC_RSFT,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  KC_LABK,  KC_RABK,  KC_QUES,  _______,
                                                _______,  _______,          XXXXXXX,  _______
    ),
    [LAYER_NAV] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_LSFT,  KC_LGUI,  KC_LCTL,  KC_LALT,  _______,          KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
                                                _______,  XXXXXXX,          _______,  _______
    ),
    [LAYER_FNC] = LAYOUT(
        EE_CLR,   _______,  _______,  _______,  _______,  QK_RBT,           RM_NEXT,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,
        _______,  _______,  _______,  _______,  _______,  _______,          RM_HUEU,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_VOLU,
        _______,  _______,  KC_LGUI,  KC_LSFT,  KC_LCTL,  _______,          RM_SATU,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,
        _______,  XXXXXXX,  _______,  _______,  _______,  _______,          RM_VALU,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   RM_TOGG,
                                                KC_LALT,  _______,          KC_DEL,   _______
    ),

    // [] {} | \ : ; ()
    //
    // -> => <= != (); += -= ~/ ~/. ``` :% := ;.
    //
    // []  | \ (yo?)
    // -> => <= != (); += -= ~/ ~/. ``` :% := ;,
    //
    // - ( ) : -   - - - - "
    // - { } ; -   - C S G A
    // - - - - -   - - < > ?
    //
    // [] {} | \ : ; ()
    // -> => <= != (); += -= ~/ ~/. ``` :% :=
    //
    // - - - - -   - - - - X
    // - - - - -   - X X X X
    // - - - - -   - - X X X
    //
    // [9] = layout(
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
    //                                             _______,  _______,          _______,  _______
    // ),
};

// https://docs.qmk.fm/tap_hold#chordal-hold-handedness
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    '*', '*', '*', '*', '*', '*',   '*', '*', '*', '*', '*', '*',
    '*', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', '*',
    '*', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', '*',
    '*', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', '*',
                        '*', '*',   '*', '*'
);

// Keycodes store modifiers in a compact 5bit format;
// extract and expand them into a full 8bit mask
// https://github.com/qmk/qmk_firmware/blob/master/quantum/modifiers.h
#define QK_MOD_TAP_GET_MOD_BITS(kc) (((kc) & 0x0F00) >> ((kc) & 0x1000) ? 4 : 8)

static uint16_t last_pressed_keycode = KC_NO;

// https://docs.qmk.fm/understanding_qmk#process-record
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        last_pressed_keycode = keycode;
    }
    // Process the record normally
    return true;

}

// https://docs.qmk.fm/tap_hold#hold-on-other-key-press
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EX_E:
        case EX_A:
        case EX_C:
        case EX_J:
        case EX_K:
        case EX_L:
            return get_tap_keycode(last_pressed_keycode) == KC_BSPC;
        case EX_ENT:
        case EX_TAB:
            return true;
    }
    return false;
}

// https://docs.qmk.fm/tap_hold#is-flow-tap-key
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & MOD_MASK_CAG) == 0) {
        switch (get_tap_keycode(keycode)) {
            case KC_1 ... KC_0:
            case KC_A ... KC_Z:
            case KC_DOT:
            case KC_COMM:
            case KC_QUOT:
            case KC_SLSH:
            case KC_GRV:
            case KC_MINS:
            case KC_EQL:
            case KC_SPC:
            case KC_BSPC:
                return true;
        }
    }
    return false;
}

// https://docs.qmk.fm/feature_layers#layer-change-code
// https://github.com/qmk/qmk_firmware/tree/master/keyboards/zsa/voyager#voyager-customization
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    // STATUS_LED_1(false);           // Right, Red (Top)
    STATUS_LED_2(layer == LAYER_SYM); // Right, Green (Bottom)
    STATUS_LED_3(layer == LAYER_FNC); // Left, Red (Top)
    STATUS_LED_4(layer == LAYER_NAV); // Left, Green (Bottom)
    return state;
}

// https://docs.qmk.fm/features/repeat_key#defining-alternate-keys
// uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
//     return get_alt_repeat_key_keycode_magic(keycode);
// }

// https://docs.qmk.fm/features/repeat_key#ignoring-certain-keys-and-mods
// bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* mods) {
//     remember_last_key_magic();
//     return true;
// }

// https://docs.qmk.fm/custom_quantum_functions#keyboard-housekeeping
// void housekeeping_task_user(void) {
//     housekeeping_task_magic();
// }
