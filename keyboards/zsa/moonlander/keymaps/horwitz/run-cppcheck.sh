#!/bin/sh
# Run cppcheck on the horwitz keymap.
# Must be run from the repo root.
#
# Suppressions:
#   missingInclude / missingIncludeSystem -- QMK headers are not available outside the build system
#   unknownMacro -- QMK build-system macros (QMK_KEYBOARD, SONG, ML_LED_*, etc.) are undefined here
#   unmatchedSuppression / checkersReport -- cppcheck housekeeping noise
#
#   dance.c: unusedFunction / constParameterPointer -- public functions are QMK callbacks stored in
#     function-pointer tables in keymap.c; cppcheck cannot see across translation units.
#     dance.h is not listed as a standalone target; it is checked through keymap.c's #include.
set -e
cppcheck --enable=all \
    --suppress=missingIncludeSystem \
    --suppress=missingInclude \
    --suppress=unknownMacro \
    --suppress=unmatchedSuppression \
    --suppress=checkersReport \
    "--suppress=unusedFunction:keyboards/zsa/moonlander/keymaps/horwitz/dance.c" \
    "--suppress=constParameterPointer:keyboards/zsa/moonlander/keymaps/horwitz/dance.c" \
    --check-level=exhaustive \
    --error-exitcode=1 \
    keyboards/zsa/moonlander/keymaps/horwitz/keymap.c \
    keyboards/zsa/moonlander/keymaps/horwitz/dance.c \
    keyboards/zsa/moonlander/keymaps/horwitz/colors.h \
    keyboards/zsa/moonlander/keymaps/horwitz/user_song_list.h
