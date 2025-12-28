#include QMK_KEYBOARD_H

enum layers {
    LAYER_BASE,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_FNC,
};

// Mod-tap keys
#define MT_R LGUI_T(KC_R)
#define MT_T LSFT_T(KC_T)
#define MT_S LCTL_T(KC_S)
#define MT_SPC LALT_T(KC_SPC)
#define MT_BSPC RALT_T(KC_BSPC)
#define MT_H RCTL_T(KC_H)
#define MT_A RSFT_T(KC_A)
#define MT_E RGUI_T(KC_E)

// Layer-toggle keys
#define LT_FNC LT(LAYER_FNC, KC_X)
#define LT_NAV LT(LAYER_NAV, KC_TAB)
#define LT_SYM LT(LAYER_SYM, KC_ENT)

#define MOD_MASK_LCAG (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_TAB,   KC_B,     KC_L,     KC_D,     KC_C,     KC_V,             KC_J,     KC_Y,     KC_O,     KC_U,     KC_QUOT,  KC_EQL,
        KC_ESC,   KC_N,     MT_R,     MT_T,     MT_S,     KC_G,             KC_P,     MT_H,     MT_A,     MT_E,     KC_I,     KC_ENT,
        OS_LSFT,  LT_FNC,   KC_Q,     KC_M,     KC_W,     KC_Z,             KC_K,     KC_F,     KC_COMM,  KC_DOT,   KC_SLSH,  OS_RSFT,
                                                LT_NAV,   MT_SPC,           MT_BSPC,  LT_SYM
    ),
    // [1] = LAYOUT(
    //     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,            KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    //     KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,          KC_7,     KC_8,     KC_9,     KC_MINS,  KC_SLSH,  KC_F12,
    //     _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,          KC_4,     KC_5,     KC_6,     KC_PLUS,  KC_ASTR,  KC_BSPC,
    //     _______,  _______,  KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,          KC_1,     KC_2,     KC_3,     KC_DOT,   KC_EQL,   KC_ENT,
    //                                             _______,  _______,          _______,  KC_0
    // ),
    // [2] = LAYOUT(
    //     RM_TOGG,  QK_KB,    RM_NEXT,  RGB_M_P,  RM_VALD,  RM_VALU,          _______,  _______,  _______,  _______,  _______,  QK_BOOT,
    //     _______,  _______,  _______,  _______,  _______,  _______,          KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   _______,  _______,
    //     _______,  _______,  _______,  KC_MSTP,  _______,  _______,          KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,
    //     _______,  _______,  _______,  _______,  RM_HUED,  RM_HUEU,          _______,  C(S(KC_TAB)),C(KC_TAB),_______,_______, _______,
    //                                             _______,  _______,          _______,  _______
    // ),
    [LAYER_SYM] = LAYOUT(
        KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  KC_DQT,   KC_PLUS,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  KC_RCTL,  KC_RSFT,  KC_RGUI,  KC_RALT,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  KC_LABK,  KC_RABK,  KC_QUES,  _______,
                                                _______,  _______,          _______,  XXXXXXX
    ),
    [LAYER_NAV] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_LCTL,  _______,          KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,
                                                XXXXXXX,  _______,          KC_SPC,   _______
    ),
    [LAYER_FNC] = LAYOUT(
        EE_CLR,   _______,  _______,  _______,  _______,  QK_RBT,           RM_NEXT,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,
        _______,  _______,  _______,  _______,  _______,  _______,          RM_HUEU,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_VOLU,
        _______,  _______,  KC_LGUI,  KC_LSFT,  KC_LCTL,  _______,          RM_SATU,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,
        _______,  XXXXXXX,  _______,  _______,  _______,  _______,          RM_VALU,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   RM_TOGG,
                                                _______,  _______,          KC_DEL,   _______
    ),

    // [] {} | \ : ; ()
    //
    // -> => <= != (); += ~/ ~/. ```
    //
    //
    // - - - - -   - - - - -
    // - - - - -   - X X X X
    // - - - - -   - - X X X
    //
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
    //     _______,  MT_N,   MT_R,   MT_T,   MT_S,   KC_G,             KC_P,     MT_H,   MT_A,   MT_E,   MT_I,   KC_ENT,
    //     _______,  KC_X,     KC_Q,     KC_M,     KC_W,     KC_Z,             KC_K,     KC_F,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
    //                                             MO(_NAV), KC_SPC,           KC_BSPC,  MO(_SYM)
    // ),
    // [9] = layout(
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
          '*',      'L',      'L',      'L',      'L',      'L',              'R',      'R',      'R',      'R',      'R',      'R',
          '*',      'L',      'L',      'L',      'L',      'L',              'R',      'R',      'R',      'R',      'R',      '*',
          '*',      'L',      'L',      'L',      'L',      'L',              'R',      'R',      'R',      'R',      'R',      '*',
                                                  '*',      '*',              '*',      '*'
    );

static uint16_t key_press_keycode = KC_NO;

// https://docs.qmk.fm/understanding_qmk
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Keep track of the last pressed key so we can modify the "hold" decision
        key_press_keycode = keycode;
    }
    return true;
}

// https://docs.qmk.fm/tap_hold#hold-on-other-key-press
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_NAV:
            // Allow quick Tab -> Enter presses, but activate the layer otherwise
            return key_press_keycode != LT_SYM && key_press_keycode != KC_ENT;
        case LT_SYM:
            // Always prioritize the layer activation
            return true;
        case MT_R:
        case MT_S:
        case MT_SPC:
            // For snappier word and line deletion, resolve relevant modifiers
            // to "hold" immediately when backspace is pressed
            return key_press_keycode == MT_BSPC;
        default:
            return false;
    }
}

static bool override_mt_bspc = false;

// https://docs.qmk.fm/tap_hold#tapping-term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_BSPC:
            if ((get_mods() & MOD_MASK_LCAG) != 0) {
                // If modifiers are held, bypass mod-tap behavior.
                //
                // Here, we first clear the tapping term so that the key press is
                // resolved immediatly and passed on for further processing. This
                // will result in the "hold" action being selected, which needs
                // to be overriden to "tap" later.
                override_mt_bspc = true;
                return 0;
            }
        default:
            return TAPPING_TERM;
    }
}

// https://docs.qmk.fm/custom_quantum_functions#process-record-function-documentation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_BSPC:
            if (override_mt_bspc) {
                // We were forced to select the "hold" action to skip tapping term,
                // now undo this and emit the "tap" as intended
                uint8_t keycode = get_tap_keycode(MT_BSPC);
                if (record->event.pressed) {
                    register_code(keycode);
                } else {
                    override_mt_bspc = false;
                    unregister_code(keycode);
                }
                return false;
            }
        default:
            return true;
    }
}

// https://docs.qmk.fm/tap_hold#is-flow-tap-key
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & MOD_MASK_CAG) != 0) {
        return false; // Disable Flow Tap on hotkeys
    }
    switch (get_tap_keycode(keycode)) {
        case KC_1 ... KC_0:
        case KC_B ... KC_S: // Exclude LSFT ("A")
        case KC_U ... KC_Z: // Exclude RSFT ("T")
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

