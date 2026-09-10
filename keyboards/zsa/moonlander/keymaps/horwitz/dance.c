#include QMK_KEYBOARD_H
#include "dance.h"

static tap dance_state[10];

// clang-format off
// left to right, so [0]=1, [1]=2, ..., [9]=0
static const uint16_t num_row[] = {KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0};

// left to right, so [0]=F1, [1]=F2, ..., [9]=F10
static const uint16_t f_row[]   = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10};
// clang-format on

static void on_dance_i(const tap_dance_state_t *state, const void *user_data, int i) {
    if (state->count == 3) {
        tap_code16(num_row[i]);
        tap_code16(num_row[i]);
        tap_code16(num_row[i]);
    }
    if (state->count > 3) {
        tap_code16(num_row[i]);
    }
}

static void dance_i_finished(const tap_dance_state_t *state, void *user_data, int i) {
    dance_state[i].step = dance_step(state->count, state->interrupted, state->pressed);
    switch (dance_state[i].step) {
        case SINGLE_TAP:        register_code16(num_row[i]);                             break;
        case SINGLE_HOLD:       register_code16(f_row[i]);                               break;
        case DOUBLE_TAP:        register_code16(num_row[i]); register_code16(num_row[i]); break;
        case DOUBLE_SINGLE_TAP: tap_code16(num_row[i]);      register_code16(num_row[i]); break;
    }
}

static void dance_i_reset(tap_dance_state_t *state, void *user_data, int i) {
    wait_ms(10);
    switch (dance_state[i].step) {
        case SINGLE_TAP:
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP: unregister_code16(num_row[i]); break;
        case SINGLE_HOLD:       unregister_code16(f_row[i]);   break;
    }
    dance_state[i].step = 0;
}

#define DEFINE_DANCE(n) \
    void on_dance_##n(tap_dance_state_t *s, void *d)         { on_dance_i(s, d, n); } \
    void dance_##n##_finished(tap_dance_state_t *s, void *d) { dance_i_finished(s, d, n); } \
    void dance_##n##_reset(tap_dance_state_t *s, void *d)    { dance_i_reset(s, d, n); }

DEFINE_DANCE(0)
DEFINE_DANCE(1)
DEFINE_DANCE(2)
DEFINE_DANCE(3)
DEFINE_DANCE(4)
DEFINE_DANCE(5)
DEFINE_DANCE(6)
DEFINE_DANCE(7)
DEFINE_DANCE(8)
DEFINE_DANCE(9)
