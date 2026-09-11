#include "led_logic.h"

bool should_capitalize_inner(bool caps_lock, bool caps_word, bool shift_pressed) {
    return caps_lock || caps_word || shift_pressed;
}

uint8_t caps_led_mode(bool caps_lock, bool caps_word) {
    if (caps_lock) return LED_ON;
    if (caps_word) return LED_BLINK_FAST;
    return LED_OFF;
}

// led_index 1-(NUM_LEDS-1): LED (NUM_LEDS-1) tracks layer bit 0, ..., LED 1 tracks bit (NUM_LEDS-2).
uint8_t layer_led_mode(uint8_t layer, int led_index) {
    return (layer & (1 << (NUM_LEDS - 1 - led_index))) ? LED_ON : LED_OFF;
}

// pattern[mode] encodes which of the 8 phases have the LED on as individual bits.
bool led_on_at_phase_inner(uint8_t mode, uint8_t phase) {
    static const uint8_t pattern[4] = {0x00, 0xff, 0x0f, 0xaa};
    return (pattern[mode] & (uint8_t)(1u << phase)) != 0;
}
