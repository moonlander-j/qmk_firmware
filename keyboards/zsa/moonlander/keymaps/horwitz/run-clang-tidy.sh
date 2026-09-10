#!/bin/sh
# Run clang-tidy on the horwitz keymap.
# Must be run from the repo root.
#
# Prerequisites:
#   1. Install clang-tidy:  brew install llvm
#                           then add /opt/homebrew/opt/llvm/bin to PATH
#   2. Generate a compilation database (qmk generate-compilation-database does not
#      work with this ZSA fork; use bear instead):
#        make zsa/moonlander/reva:horwitz:clean && bear -- make zsa/moonlander/reva:horwitz
#      This produces compile_commands.json in the repo root.
#
# clang-tidy reads .clang-tidy from the source file's directory for check config.
set -e
clang-tidy \
    -p . \
    keyboards/zsa/moonlander/keymaps/horwitz/keymap.c
