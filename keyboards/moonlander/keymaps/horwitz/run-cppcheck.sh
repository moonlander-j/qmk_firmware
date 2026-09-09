#!/bin/sh
# Run cppcheck on the horwitz keymap.
# Must be run from the repo root.
#
# Suppressions:
#   missingInclude / missingIncludeSystem -- QMK headers are not available outside the build system
#   unknownMacro -- QMK build-system macros (QMK_KEYBOARD, SONG, ML_LED_*, etc.) are undefined here
#   unmatchedSuppression / checkersReport -- cppcheck housekeeping noise
set -e
cppcheck --enable=all \
    --suppress=missingIncludeSystem \
    --suppress=missingInclude \
    --suppress=unknownMacro \
    --suppress=unmatchedSuppression \
    --suppress=checkersReport \
    --check-level=exhaustive \
    --error-exitcode=1 \
    keyboards/moonlander/keymaps/horwitz/keymap.c \
    keyboards/moonlander/keymaps/horwitz/colors.h \
    keyboards/moonlander/keymaps/horwitz/user_song_list.h
