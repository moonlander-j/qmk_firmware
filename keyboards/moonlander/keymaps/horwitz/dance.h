#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    // bool is_press_action;  // standard QMK tap-dance field; unused in this keymap
    uint8_t step;
} tap;

// clang-format off
enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };
// clang-format on

