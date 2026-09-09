# --------------------------------------------------------------------------------
# Keep this file, even if it is empty, as a marker that this folder contains tests
# --------------------------------------------------------------------------------

KEYMAP_DIR := keyboards/moonlander/keymaps/horwitz

# Use a full path so make doesn't need VPATH to find dance_step.c.
SRC += $(KEYMAP_DIR)/dance_step.c

# Append the keymap dir to VPATH after tests/test_common (via the $(TEST)_VPATH hook
# in build_test.mk) so the compiler finds test_common/keymap.c before ours.
$(TEST)_VPATH += $(KEYMAP_DIR)
