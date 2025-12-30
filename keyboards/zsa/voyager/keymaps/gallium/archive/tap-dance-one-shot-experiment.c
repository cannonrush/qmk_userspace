/**
 * NOTE: this implementation does not handle combinations (quick sequences) of
 * one-shot modifiers. See "fn_smart_mod_on_dance_finished" for details.
 *
 * DO NOT USE!
 *
 * Contains the configuration for all tap-dance functionality. Extracted due
 * to its complexity.
 *
 * Currently, this only houses one-shot modifier tap-dances.
 * Some applications require (support) modifier-only shortcuts, e.g., "Shift
 * Shift" in IntelliJ IDEA, and the only way we can currently access those is
 * by having normal modifiers on a layer.
 *
 * One-shot modifiers is another nice-to-have, but are competing for the same
 * keymap location. To support both, we introduce here an intricate tap-dance
 * scheme, which emits OSM on tap, normal modifier on hold and a double-tap on,
 * well, double-tap.
 */

// Stick these into your keymap
#define TD_LALT TD(TD_IDX_LALT)
#define TD_LGUI TD(TD_IDX_LGUI)
#define TD_LSFT TD(TD_IDX_LSFT)
#define TD_LCTL TD(TD_IDX_LCTL)
#define TD_RCTL TD(TD_IDX_RCTL)
#define TD_RSFT TD(TD_IDX_RSFT)
#define TD_RGUI TD(TD_IDX_RGUI)
#define TD_RALT TD(TD_IDX_RALT)

typedef struct {
    uint16_t keycode;
    bool is_registered;
} td_mod_data_t;

void fn_smart_mod_on_each_tap(tap_dance_state_t *state, void *user_data) {
    // Do nothing on first tap, it will resolve into either one-shot or
    // normal modifier once tap-dance finishes
    if (state->count == 1) return;

    // Clear all outstanding one-shot mods; this isn't strictly necessary,
    // but since we never want additional mods to be active during a mod
    // double-tap -- it might help us avoid misinputs
    clear_oneshot_mods();

    // Immediately resolve into a double-tap
    td_mod_data_t *data = (td_mod_data_t *)user_data;
    uint16_t keycode = data->keycode;
    tap_code(keycode);
    tap_code(keycode);

    // Terminate tap-dance early
    reset_tap_dance(state);
}

void fn_smart_mod_on_dance_finished(tap_dance_state_t *state, void *user_data) {
    // Do nothing on mutli-taps, they are fully handled by "on_each_tap"
    if (state->count > 1) return;

    td_mod_data_t *data = (td_mod_data_t *)user_data;
    uint16_t keycode = data->keycode;

    // TODO: to make all this work properly, we need to:
    // 1. Prevent one-shot mods from being "consumed" on irrelevant interrupting
    //    actions, such as other layers, modifeirs and other one-shot keys
    // 2. Defer the tap-dance "finish" in these cases -- we'd need to handle
    //    both the tapping term timeouts as well as all other key presses;
    //    this is the hard part
    // if (state->interrupted) {
    //     action_t action = action_for_keycode(state->interrupting_keycode);
    //     if (action.kind.id != ACT_USAGE) {
    //     }
    // }

    if (state->pressed) {
        // Handle another key being pressed, or the TD key being held for
        // longer than the TAPPING_TERM by resolving into a normal modifier
        // event. This behavior should be equivalent to what OSMs and "hold on
        // other key press" MTs do.
        register_code(keycode);
        data->is_registered = true;
        return;
    }

    // We are here because tap-dance has finished with count of "1" and the
    // tap key was released in time, meaning we resolve the "sequence" into
    // a one-shot modifier event
    uint8_t mods = get_oneshot_mods() | MOD_BIT(keycode);
    set_oneshot_mods(mods);
}

void fn_smart_mod_on_reset(tap_dance_state_t *state, void *user_data) {
    td_mod_data_t *data = (td_mod_data_t *)user_data;
    if (data->is_registered) {
        // Clean up modifier code if it previously resolved to "hold"
        unregister_code(data->keycode);
        data->is_registered = false;
    }
}

// https://docs.qmk.fm/features/tap_dance#example-3
#define ACTION_TAP_DANCE_SMART_MOD(keycode) { \
    .fn = { \
        .on_each_tap = fn_smart_mod_on_each_tap, \
        .on_dance_finished = fn_smart_mod_on_dance_finished, \
        .on_reset = fn_smart_mod_on_reset, \
        .on_each_release = NULL, \
    }, \
    .user_data = &((td_mod_data_t){keycode, false}), \
}

enum tap_dance_indices {
    TD_IDX_LALT,
    TD_IDX_LGUI,
    TD_IDX_LSFT,
    TD_IDX_LCTL,
    TD_IDX_RCTL,
    TD_IDX_RSFT,
    TD_IDX_RGUI,
    TD_IDX_RALT,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_IDX_LALT] = ACTION_TAP_DANCE_SMART_MOD(KC_LALT),
    [TD_IDX_LGUI] = ACTION_TAP_DANCE_SMART_MOD(KC_LGUI),
    [TD_IDX_LSFT] = ACTION_TAP_DANCE_SMART_MOD(KC_LSFT),
    [TD_IDX_LCTL] = ACTION_TAP_DANCE_SMART_MOD(KC_LCTL),
    [TD_IDX_RCTL] = ACTION_TAP_DANCE_SMART_MOD(KC_RCTL),
    [TD_IDX_RSFT] = ACTION_TAP_DANCE_SMART_MOD(KC_RSFT),
    [TD_IDX_RGUI] = ACTION_TAP_DANCE_SMART_MOD(KC_RGUI),
    [TD_IDX_RALT] = ACTION_TAP_DANCE_SMART_MOD(KC_RALT),
};

