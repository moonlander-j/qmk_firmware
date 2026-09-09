#include "dance.h"

uint8_t dance_step(uint8_t count, bool interrupted, bool pressed) {
    switch (count) {
        case 1: return (interrupted || !pressed) ? SINGLE_TAP : SINGLE_HOLD;
        case 2:
            if (interrupted) return DOUBLE_SINGLE_TAP;
            return pressed ? DOUBLE_HOLD : DOUBLE_TAP;
        default: return MORE_TAPS;
    }
}
