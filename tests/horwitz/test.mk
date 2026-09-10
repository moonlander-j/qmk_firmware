# --------------------------------------------------------------------------------
# Keep this file, even if it is empty, as a marker that this folder contains tests
# --------------------------------------------------------------------------------

KEYMAP_DIR := keyboards/zsa/moonlander/keymaps/horwitz

# Use full paths so make doesn't need VPATH to find these files (avoids
# shadowing tests/test_common/keymap.c with the keymap dir in VPATH).
SRC += $(KEYMAP_DIR)/dance_step.c
SRC += $(KEYMAP_DIR)/led_logic.c

# Append the keymap dir to VPATH after tests/test_common (via the $(TEST)_VPATH
# hook in build_test.mk) so the compiler finds dance.h and led_logic.h.
$(TEST)_VPATH += $(KEYMAP_DIR)
