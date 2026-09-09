#include "gtest/gtest.h"

extern "C" {
#include "dance.h"
}

// count == 1: released normally -> SINGLE_TAP
TEST(DanceStep, SingleTap_Released) {
    EXPECT_EQ(SINGLE_TAP, dance_step(1, false, false));
}

// count == 1: still held -> SINGLE_HOLD
TEST(DanceStep, SingleHold) {
    EXPECT_EQ(SINGLE_HOLD, dance_step(1, false, true));
}

// count == 1: interrupted (another key pressed mid-tap) -> SINGLE_TAP regardless of pressed
TEST(DanceStep, SingleTap_Interrupted_NotPressed) {
    EXPECT_EQ(SINGLE_TAP, dance_step(1, true, false));
}
TEST(DanceStep, SingleTap_Interrupted_StillPressed) {
    EXPECT_EQ(SINGLE_TAP, dance_step(1, true, true));
}

// count == 2: released normally -> DOUBLE_TAP
TEST(DanceStep, DoubleTap) {
    EXPECT_EQ(DOUBLE_TAP, dance_step(2, false, false));
}

// count == 2: still held -> DOUBLE_HOLD
TEST(DanceStep, DoubleHold) {
    EXPECT_EQ(DOUBLE_HOLD, dance_step(2, false, true));
}

// count == 2: interrupted -> DOUBLE_SINGLE_TAP regardless of pressed
TEST(DanceStep, DoubleSingleTap_Interrupted_NotPressed) {
    EXPECT_EQ(DOUBLE_SINGLE_TAP, dance_step(2, true, false));
}
TEST(DanceStep, DoubleSingleTap_Interrupted_StillPressed) {
    EXPECT_EQ(DOUBLE_SINGLE_TAP, dance_step(2, true, true));
}

// count >= 3 -> MORE_TAPS
TEST(DanceStep, MoreTaps_Three) {
    EXPECT_EQ(MORE_TAPS, dance_step(3, false, false));
}
TEST(DanceStep, MoreTaps_Many) {
    EXPECT_EQ(MORE_TAPS, dance_step(10, true, true));
}

// count == 0 hits the default branch -> MORE_TAPS
TEST(DanceStep, ZeroCount) {
    EXPECT_EQ(MORE_TAPS, dance_step(0, false, false));
}
