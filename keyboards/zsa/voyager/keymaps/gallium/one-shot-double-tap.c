/**
 * Some applications require (support) modifier-only shortcuts, e.g., "Shift
 * Shift" in IntelliJ IDEA, and the only way we can currently access those is
 * by having normal modifiers on a layer.
 *
 * One-shot modifiers is another nice-to-have, but are competing for the same
 * keymap location. To support both, we introduce here a simple extension,
 * which should be called from "process_user_record". It will emit a one-shot
 * mod on tap, a normal modifier on hold and a double-tap on, well, double-tap.
 */

#define DBL_TAP_TERM (TAPPING_TERM * 2)

typedef struct {
    uint16_t mod;
    uint16_t time;
} oneshot_mod_state_t;

// Get the state of the given one-shot modifier keycode
oneshot_mod_state_t* get_oneshot_state(uint16_t keycode) {
    static oneshot_mod_state_t states[8] = {
        [0] = {.mod = KC_LALT},
        [1] = {.mod = KC_LGUI},
        [2] = {.mod = KC_LSFT},
        [3] = {.mod = KC_LCTL},
        [4] = {.mod = KC_RCTL},
        [5] = {.mod = KC_RSFT},
        [6] = {.mod = KC_RGUI},
        [7] = {.mod = KC_RALT},
    };

    switch(keycode) {
        case OS_LALT: return &states[0];
        case OS_LGUI: return &states[1];
        case OS_LSFT: return &states[2];
        case OS_LCTL: return &states[3];
        case OS_RCTL: return &states[4];
        case OS_RSFT: return &states[5];
        case OS_RGUI: return &states[6];
        case OS_RALT: return &states[7];
        default: return NULL;
    }
}

// When a one-shot mod is tapped twice within DBL_TAP_TERM, produce a modifier
// double-tap instead and return "false" to signal to halt further processing.
//
// Call this from "process_record_user" for every one-shot modifier keycode.
bool process_oneshot_or_double_tap(uint16_t keycode, keyrecord_t *record) {
    // Ignore key releases
    if (!record->event.pressed) return true;

    oneshot_mod_state_t *state = get_oneshot_state(keycode);
    // Safety first: let's not crash if this was called with a wrong keycode
    if (state) {
        // Store the interval between the key presses and then update the timer
        // regardless of how we process this event
        uint16_t delta = TIMER_DIFF_16(record->event.time, state->time);
        state->time = record->event.time;

        // If the OSM is already ON (meaning this is not the first tap in a
        // sequence) AND the last tap event happened less than DBL_TAP_TERM
        // ago, then send a double-tap instead of another OSM event
        if (get_oneshot_mods() & MOD_BIT(state->mod) && delta < DBL_TAP_TERM) {
            // Technically, we don't have to clear ALL one-shot mods, but I
            // don't see the reason to keep them ON as they will interfere with
            // our double-tap action
            clear_oneshot_mods();

            tap_code(state->mod);
            tap_code(state->mod);

            // Prevetn further processing
            return false;
        }
    }

    // We didn't do nothing
    return true;
}
