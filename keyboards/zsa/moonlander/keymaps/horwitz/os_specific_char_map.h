#pragma once
#include <stdbool.h>
#include <stdint.h>

#define MAX_SEQ_LEN 4

typedef struct {
    uint8_t keys[MAX_SEQ_LEN];
    uint8_t count;  // 0 = no sequence for this OS/case
} os_specific_sequence_t;

// Expands to a zero-count os_specific_sequence_t initializer (no sequence available).
#define NO_SEQUENCE \
    { {0}, 0 }

typedef struct {
    uint16_t               kc;
    bool                   is_cased;
    os_specific_sequence_t win_lower;
    os_specific_sequence_t win_upper;  // count = 0 when no uppercase variant exists
    os_specific_sequence_t mac_lower;
    os_specific_sequence_t mac_upper;  // count = 0 when no uppercase variant exists
} os_specific_char_map_entry_t;

extern const os_specific_char_map_entry_t os_specific_char_map[];
extern const uint8_t                      OS_SPECIFIC_CHAR_MAP_COUNT;

// TODO handle this better
// First and last custom_keycodes enum values that appear in os_specific_char_map[].
// All char-map keycodes must form a contiguous block in the enum between these two
// values (no non-char-map keycodes in between), so the bounds check in handle_os_char
// produces no false positives.
#define OS_SPECIFIC_CHAR_MAP_KC_MIN ACUTE_A
#define OS_SPECIFIC_CHAR_MAP_KC_MAX UP_ARROW
