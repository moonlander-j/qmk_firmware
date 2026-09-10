# Development (horwitz keymap)

## Prerequisites

- Homebrew
- `qmk` CLI (`brew install qmk/qmk/qmk`)
- ARM toolchain (`brew install arm-gcc-bin@10`)
- `bear` (`brew install bear`)—used to generate `compile_commands.json` for VS Code
- VS Code (https://code.visualstudio.com)

## First-time setup

### 1. Fix qmk Python dependencies

```sh
/opt/homebrew/Cellar/qmk/1.1.8/libexec/bin/python -m pip install -r requirements.txt
```

(Run from the repo root. If the qmk version has changed, adjust the path accordingly.)

### 2. Install the VS Code `code` CLI

Open VS Code, then: `⌘⇧P` -> **Shell Command: Install 'code' command in PATH**

### 3. Install the clangd extension

```sh
code --install-extension llvm-vs-code-extensions.vscode-clangd
```

### 4. Disable conflicting Microsoft C/C++ extensions (workspace-only)

In VS Code Extensions (`⌘⇧X`), find each of the following and choose **Disable (Workspace)**:
- C/C++ (`ms-vscode.cpptools`)
- C/C++ Extension Pack (`ms-vscode.cpptools-extension-pack`)
- C/C++ Themes (`ms-vscode.cpptools-themes`)

### 5. Open the repo in VS Code

```sh
code /path/to/qmk_firmware_zsa
```

### 6. Generate the compilation database

`qmk generate-compilation-database` does not work with this ZSA fork (its Makefile
output format is too old for the QMK parser). Use `bear` instead, which intercepts
compiler calls directly:

```sh
make moonlander:horwitz:clean && bear -- make moonlander:horwitz
```

The clean is required so that `bear` sees every compile invocation; a cached build
produces an incomplete `compile_commands.json`.

Then in VS Code: `⌘⇧P` -> **clangd: Restart language server**

clangd will index briefly (watch the status bar for `clangd: indexing`), then
symbol navigation (F12 / Go to Definition, hover tooltips) will be fully functional.

## Ongoing: after changing rules.mk or adding source files

Regenerate the compilation database and restart clangd:

```sh
make moonlander:horwitz:clean && bear -- make moonlander:horwitz
```

`⌘⇧P` -> **clangd: Restart language server**

## Ongoing: normal compile (no rules.mk changes)

```sh
make moonlander:horwitz
```

## Flashing the keyboard

Put the Moonlander into bootloader mode (either press the red reset button on the
underside, or tap `QK_BOOT` on the `_NUMPAD` layer — top row, second key from the
left), then:

```sh
make moonlander:horwitz:flash
```

The flash will complete automatically and the keyboard will reboot.

## Unit tests

Tests live in `tests/horwitz/` and cover the pure-logic functions in `dance_step.c`
and `led_logic.c`. Run from the repo root:

```sh
make test:horwitz
```

## Linting & static analysis

All commands run from the repo root.

### cppcheck

Prerequisite: `brew install cppcheck`.

A script with the correct flags and suppressions is provided:

```sh
keyboards/moonlander/keymaps/horwitz/run-cppcheck.sh
```

### clang-tidy

Prerequisite: `brew install llvm`.
Requires `compile_commands.json` — see the "generate the compilation database" step above.

```sh
keyboards/moonlander/keymaps/horwitz/run-clang-tidy.sh
```

### -Wconversion

Add temporarily to `rules.mk`, compile, then remove:

```sh
# 1. Add to rules.mk:
echo 'EXTRAFLAGS += -Wconversion' >> keyboards/moonlander/keymaps/horwitz/rules.mk

# 2. Compile and filter to horwitz warnings only:
make moonlander:horwitz 2>&1 | grep 'warning:' | grep horwitz

# 3. Remove the added line from rules.mk when done.
```

## Formatting

### clang-format

Prerequisite: `brew install llvm`.

```sh
# Check (no changes written):
/opt/homebrew/opt/llvm/bin/clang-format --dry-run --Werror \
  keyboards/moonlander/keymaps/horwitz/*.c \
  keyboards/moonlander/keymaps/horwitz/*.h

# Apply:
/opt/homebrew/opt/llvm/bin/clang-format -i \
  keyboards/moonlander/keymaps/horwitz/*.c \
  keyboards/moonlander/keymaps/horwitz/*.h
```

Note: the repo's `.clang-format` style may conflict with the keymap's formatting
conventions (e.g., aligned columns in `LAYOUT_*` macros). Review diffs carefully.
