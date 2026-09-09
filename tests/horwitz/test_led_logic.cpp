#include "gtest/gtest.h"

extern "C" {
#include "led_logic.h"
}

// ---------------------------------------------------------------------------
// should_capitalize_inner
// ---------------------------------------------------------------------------

TEST(ShouldCapitalize, AllOff) {
    EXPECT_FALSE(should_capitalize_inner(false, false, false));
}
TEST(ShouldCapitalize, CapsLockOnly) {
    EXPECT_TRUE(should_capitalize_inner(true, false, false));
}
TEST(ShouldCapitalize, CapsWordOnly) {
    EXPECT_TRUE(should_capitalize_inner(false, true, false));
}
TEST(ShouldCapitalize, ShiftOnly) {
    EXPECT_TRUE(should_capitalize_inner(false, false, true));
}
TEST(ShouldCapitalize, AllOn) {
    EXPECT_TRUE(should_capitalize_inner(true, true, true));
}

// ---------------------------------------------------------------------------
// caps_led_mode: caps_lock takes priority over caps_word
// ---------------------------------------------------------------------------

TEST(CapsLedMode, NeitherOn) {
    EXPECT_EQ(LED_OFF, caps_led_mode(false, false));
}
TEST(CapsLedMode, CapsWordOnly) {
    EXPECT_EQ(LED_BLINK_FAST, caps_led_mode(false, true));
}
TEST(CapsLedMode, CapsLockOnly) {
    EXPECT_EQ(LED_ON, caps_led_mode(true, false));
}
TEST(CapsLedMode, BothOn_CapsLockWins) {
    EXPECT_EQ(LED_ON, caps_led_mode(true, true));
}

// ---------------------------------------------------------------------------
// layer_led_mode: bit (5 - led_index) of layer controls LED led_index
//   LED 5 = bit 0, LED 4 = bit 1, LED 3 = bit 2, LED 2 = bit 3, LED 1 = bit 4
// ---------------------------------------------------------------------------

TEST(LayerLedMode, Layer0_AllOff) {
    for (int i = 1; i <= 5; ++i) {
        EXPECT_EQ(LED_OFF, layer_led_mode(0, i)) << "led_index=" << i;
    }
}

TEST(LayerLedMode, Layer1_OnlyLed5On) {
    // layer 1 = 0b00001 -> bit 0 set -> LED 5 on, rest off
    EXPECT_EQ(LED_ON,  layer_led_mode(1, 5));
    EXPECT_EQ(LED_OFF, layer_led_mode(1, 4));
    EXPECT_EQ(LED_OFF, layer_led_mode(1, 3));
    EXPECT_EQ(LED_OFF, layer_led_mode(1, 2));
    EXPECT_EQ(LED_OFF, layer_led_mode(1, 1));
}

TEST(LayerLedMode, Layer2_OnlyLed4On) {
    // layer 2 = 0b00010 -> bit 1 set -> LED 4 on
    EXPECT_EQ(LED_OFF, layer_led_mode(2, 5));
    EXPECT_EQ(LED_ON,  layer_led_mode(2, 4));
    EXPECT_EQ(LED_OFF, layer_led_mode(2, 3));
    EXPECT_EQ(LED_OFF, layer_led_mode(2, 2));
    EXPECT_EQ(LED_OFF, layer_led_mode(2, 1));
}

TEST(LayerLedMode, Layer16_OnlyLed1On) {
    // layer 16 = 0b10000 -> bit 4 set -> LED 1 on
    EXPECT_EQ(LED_OFF, layer_led_mode(16, 5));
    EXPECT_EQ(LED_OFF, layer_led_mode(16, 4));
    EXPECT_EQ(LED_OFF, layer_led_mode(16, 3));
    EXPECT_EQ(LED_OFF, layer_led_mode(16, 2));
    EXPECT_EQ(LED_ON,  layer_led_mode(16, 1));
}

TEST(LayerLedMode, Layer31_AllOn) {
    // layer 31 = 0b11111 -> all 5 bits set -> LEDs 1-5 all on
    for (int i = 1; i <= 5; ++i) {
        EXPECT_EQ(LED_ON, layer_led_mode(31, i)) << "led_index=" << i;
    }
}
