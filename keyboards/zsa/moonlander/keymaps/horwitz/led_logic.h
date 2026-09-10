#pragma once
#include <stdbool.h>
#include <stdint.h>

// clang-format off
enum { LED_OFF = 0, LED_ON = 1, LED_BLINK_SLOW = 2, LED_BLINK_FAST = 3 };
// clang-format on

// Defined in led_logic.c (no QMK dependency) to allow for standalone unit testing.
bool    should_capitalize_inner(bool caps_lock, bool caps_word, bool shift_pressed);
uint8_t caps_led_mode(bool caps_lock, bool caps_word);
uint8_t layer_led_mode(uint8_t layer, int led_index);
bool    led_on_at_phase_inner(uint8_t mode, uint8_t phase);
