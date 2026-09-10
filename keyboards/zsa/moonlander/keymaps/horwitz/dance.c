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

void on_dance_0(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 0); }
void dance_0_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 0); }
void dance_0_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 0); }

void on_dance_1(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 1); }
void dance_1_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 1); }
void dance_1_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 1); }

void on_dance_2(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 2); }
void dance_2_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 2); }
void dance_2_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 2); }

void on_dance_3(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 3); }
void dance_3_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 3); }
void dance_3_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 3); }

void on_dance_4(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 4); }
void dance_4_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 4); }
void dance_4_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 4); }

void on_dance_5(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 5); }
void dance_5_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 5); }
void dance_5_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 5); }

void on_dance_6(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 6); }
void dance_6_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 6); }
void dance_6_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 6); }

void on_dance_7(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 7); }
void dance_7_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 7); }
void dance_7_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 7); }

void on_dance_8(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 8); }
void dance_8_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 8); }
void dance_8_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 8); }

void on_dance_9(tap_dance_state_t *state, void *user_data) { on_dance_i(state, user_data, 9); }
void dance_9_finished(tap_dance_state_t *state, void *user_data) { dance_i_finished(state, user_data, 9); }
void dance_9_reset(tap_dance_state_t *state, void *user_data) { dance_i_reset(state, user_data, 9); }
