#include "led_logic.h"

bool should_capitalize_inner(bool caps_lock, bool caps_word, bool shift_pressed) {
    return caps_lock || caps_word || shift_pressed;
}

uint8_t caps_led_mode(bool caps_lock, bool caps_word) {
    if (caps_lock) return LED_ON;
    if (caps_word) return LED_BLINK_FAST;
    return LED_OFF;
}

// led_index 1-5: LED 5 tracks layer bit 0, LED 4 tracks bit 1, ..., LED 1 tracks bit 4.
uint8_t layer_led_mode(uint8_t layer, int led_index) {
    return (layer & (1 << (5 - led_index))) ? LED_ON : LED_OFF;
}
