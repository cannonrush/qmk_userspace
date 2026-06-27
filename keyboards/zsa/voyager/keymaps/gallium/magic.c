/**
 * test
 */

#define MAGIC_TIMEOUT 500

static struct {
    uint16_t last_key_time;
    bool is_active;
} magic_state;

static inline uint16_t magic_state_send_key(uint16_t keycode) {
    magic_state.last_key_time = timer_read();
    return keycode;
}

static inline bool magic_state_is_timeout(void) {
    return timer_elapsed(magic_state.last_key_time) > MAGIC_TIMEOUT;
}

void remember_last_key_magic(void) {
    magic_state.is_active = true;
    magic_state.last_key_time = timer_read();
}

uint16_t get_alt_repeat_key_keycode_magic(uint16_t keycode) {
    if (magic_state.is_active) {
        switch (get_tap_keycode(keycode)) {
            case KC_S: return magic_state_send_key(KC_C);
            case KC_R: return magic_state_send_key(KC_L);
            case KC_G: return magic_state_send_key(KC_S);
            case KC_W: return magic_state_send_key(KC_S);
            case KC_C: return magic_state_send_key(KC_S);
            case KC_P: return magic_state_send_key(KC_L);
            case KC_B: return magic_state_send_key(KC_L);
            case KC_Q: return magic_state_send_key(KC_U);
            case KC_Y: return magic_state_send_key(KC_E);
        }
    }
    return KC_Y;
}

void housekeeping_task_magic(void) {
    if (magic_state.is_active && magic_state_is_timeout()) {
        magic_state.is_active = false;
    }
}

