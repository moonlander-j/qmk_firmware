# Development (horwitz keymap)

## Overview

**Keyboard:** ZSA Moonlander reva — Colemak-DH base layout

**Key features:**
- Auto-detected OS (Windows vs. macOS) via `OS_DETECTION_ENABLE`; plays a different startup song per OS and switches between `_WIN_BASE` / `_MAC_BASE` on boot; `OS_DETECTION_SINGLE_REPORT` prevents spurious re-detection
- Dual Unicode strategies dispatched at runtime by `handle_os_char()`: Windows uses Alt+numpad (CP1252/CP437 codes), macOS uses Option+hex (Unicode code points); 101 char-map keycodes; sequences live in a generated `os_specific_char_map[]` table in `os_specific_char_map.c`
- ~190 custom keycodes total: 101 char-map (accented chars, Greek, symbols), 80+ song keys, and a handful of utility keys (pair-insert, version print)
- `_WIN_SYM`/`_MAC_SYM` and `_GREEK_W`/`_GREEK_M` remain as separate layers — OS-specific LED colors make consolidation non-trivial
- 9 accent sub-layers (`_A_ACUTE`, `_A_GRAVE`, etc.) triggered via OSL from `_ACCENT` — Windows only; macOS users use the built-in hold-and-pick popup
- 80+ song keys across `_J1`/`_J2` layers; each references a named `static float` array in `user_song_list.h`
- Tap-dance number row: tap = digit, hold = F-key, double-tap = repeat digit
- `_LMAPS` layer: tap-dance keys that type out their own layer's source text (double-tap) or the layer name (single-tap) — a self-documenting reference
- Moonlander LEDs: LED 1 = caps indicator (steady = CapsLock, fast-blink = CapsWord); LEDs 2–6 = binary display of current layer number
- All large generated sections (keymaps, ledmap, `os_specific_char_map[]`, char-map enum values, `_LMAPS` tap-dances) come from an external [qmk-tools](https://github.com/jhmail/qmk-tools) generator

**21 layers:** `_WIN_BASE`, `_MAC_BASE`, `_WIN_SYM`, `_MAC_SYM`, `_NUMPAD`, `_GREEK_W`, `_GREEK_M`, `_ACCENT`, `_A_ACUTE`, `_A_CARON`, `_A_CEDILLA`, `_A_CIRCUMFLEX`, `_A_DIAERESIS`, `_A_GRAVE`, `_A_RING_ABOVE`, `_A_STROKE`, `_A_TILDE`, `_J1`, `_J2`, `_COLEMAK_DH`, `_LMAPS`

## Prerequisites

- Homebrew
- `qmk` CLI (`brew install qmk/qmk/qmk`)
- ARM toolchain (`brew install arm-gcc-bin@10`)
- `bear` (`brew install bear`)—used to generate `compile_commands.json` for VS Code
- VS Code (https://code.visualstudio.com)

## First-time setup

### 1. Fix qmk Python dependencies

```sh
$(brew --prefix qmk)/libexec/bin/python -m pip install -r requirements.txt
```

(Run from the repo root.)

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

```sh
keyboards/zsa/moonlander/keymaps/horwitz/gen-compile-db.sh
```

This script runs `bear -- make` (intercepting every compiler invocation) and then
adds an entry for `keymap.c`.  A dedicated entry is necessary because QMK's build
system `#include`s `keymap.c` from a generated wrapper rather than compiling it
directly, so `bear` does not capture it automatically.  `qmk generate-compilation-database`
handles this in mainline QMK, but that command does not work with this ZSA fork.

Then in VS Code: `⌘⇧P` -> **clangd: Restart language server**

clangd will index briefly (watch the status bar for `clangd: indexing`), then
symbol navigation (F12 / Go to Definition, hover tooltips) will be fully functional.

## Ongoing: after changing rules.mk or adding source files

Regenerate the compilation database and restart clangd:

```sh
keyboards/zsa/moonlander/keymaps/horwitz/gen-compile-db.sh
```

`⌘⇧P` -> **clangd: Restart language server**

## Ongoing: normal compile (no rules.mk changes)

```sh
make zsa/moonlander/reva:horwitz
```

## Flashing the keyboard

Put the Moonlander into bootloader mode (either press the red reset button on the
underside, or tap `QK_BOOT` on the `_NUMPAD` layer — top row, second key from the
left), then:

```sh
make zsa/moonlander/reva:horwitz:flash
```

The flash will complete automatically and the keyboard will reboot.

## Generated code

Several files (or sections of files) are produced by
[qmk-tools](https://github.com/jhmail/qmk-tools) and pasted in by hand.
A generated-code header comment marks each block and names the generator method.

| generated block                | target file                                              | generator method                                            |
|--------------------------------|----------------------------------------------------------|-------------------------------------------------------------|
| `os_specific_char_map[]` array | `os_specific_char_map.c`                                 | `ProcessRecordUserUnicodeCases.toStringWithHeader()`        |
| char-map enum values           | `custom_keycodes.h` (between `RGB_SLD` and `PLAY_ZELDA`) | `ProcessRecordUserUnicodeCases.toCustomKeycodesEnumBlock()` |
| `keymaps[]` array              | `keymap.c`                                               | `Keymap.getKeymap()`                                        |
| `ledmap[]` array               | `keymap.c`                                               | `Ledmap.getLedmap()`                                        |
| `_LMAPS` tap-dance methods     | `keymap.c`                                               | `LmapTapDances.getLmapTapDances()`                          |

The array and its enum values are always generated together from the same data
file (`process-record-user-unicode-raw-data.txt`), so they stay in sync.

**When to regenerate:** any time a char-map keycode is added, removed, or
reordered — i.e., when `process-record-user-unicode-raw-data.txt` changes.
Run `main()` in `KeyboardForTesting.kt` (or `./gradlew test` to verify), then
paste both outputs in the same commit.

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
keyboards/zsa/moonlander/keymaps/horwitz/run-cppcheck.sh
```

### clang-tidy

Prerequisite: `brew install llvm`.
Requires `compile_commands.json` — see the "generate the compilation database" step above.

```sh
keyboards/zsa/moonlander/keymaps/horwitz/run-clang-tidy.sh
```

### -Wconversion

Add temporarily to `rules.mk`, compile, then remove:

```sh
# 1. Add to rules.mk:
echo 'EXTRAFLAGS += -Wconversion' >> keyboards/zsa/moonlander/keymaps/horwitz/rules.mk

# 2. Compile and filter to horwitz warnings only:
make zsa/moonlander/reva:horwitz 2>&1 | grep 'warning:' | grep horwitz

# 3. Remove the added line from rules.mk when done.
```

## Formatting

### clang-format

Prerequisite: `brew install llvm`.

```sh
# Check (no changes written):
/opt/homebrew/opt/llvm/bin/clang-format --dry-run --Werror \
  keyboards/zsa/moonlander/keymaps/horwitz/*.c \
  keyboards/zsa/moonlander/keymaps/horwitz/*.h

# Apply:
/opt/homebrew/opt/llvm/bin/clang-format -i \
  keyboards/zsa/moonlander/keymaps/horwitz/*.c \
  keyboards/zsa/moonlander/keymaps/horwitz/*.h
```

Note: the repo's `.clang-format` style may conflict with the keymap's formatting
conventions (e.g., aligned columns in `LAYOUT_*` macros). Review diffs carefully.

---

## Porting notes: firmware23 → firmware25

These are the non-obvious decisions made when porting the `horwitz23` branch
(based on `firmware23`) to `horwitz25` (based on `firmware25`).

### Keyboard path restructure

All ZSA keyboards moved from `keyboards/<kb>/` to `keyboards/zsa/<kb>/`. The
Moonlander keyboard is now `zsa/moonlander`, with two hardware revisions:
`zsa/moonlander/reva` (USB PID `0x1969`, i2c EEPROM, stm32-dfu bootloader) and
`zsa/moonlander/revb` (USB PID `0x1972`, embedded flash, custom bootloader).
Identify your revision via `ioreg -p IOUSB` → `idProduct` field. This keyboard
is reva.

### Build target

```
# firmware23
make moonlander:horwitz

# firmware25
make zsa/moonlander/reva:horwitz
```

### Community modules replace rules.mk feature flags

firmware25 introduces a community modules system. Features that were enabled via
`rules.mk` flags in firmware23 are now declared as modules in `keymap.json`.

| firmware23 (`rules.mk`)       | firmware25 (`keymap.json` modules) |
|-------------------------------|------------------------------------|
| `ORYX_ENABLE = yes`           | `"zsa/oryx"` (if needed)           |
| (implicit via oryx keymap)    | `"zsa/defaults"`                   |

The horwitz keymap does not use any oryx APIs (raw HID, webhid, LED protocol),
so `zsa/oryx` is **not** declared. `zsa/defaults` is declared because it owns
`LED_LEVEL` and `TOGGLE_LAYER_COLOR`.

`RGB_MATRIX_CUSTOM_KB = yes` was also removed: it was carried over from the
oryx-derived starting point but the horwitz keymap defines no custom RGB matrix
effects. In firmware25 the custom effect (`oryx_webhid_effect`) lives in
`modules/zsa/oryx/` and is only included when that module is active.

### `ML_SAFE_RANGE` → `ZSA_SAFE_RANGE`

The custom keycode base enum value was renamed. Update any `enum custom_keycodes`
that starts from `ML_SAFE_RANGE`.

### `key_overrides` declaration format changed

firmware23 used a NULL-terminated pointer (iterated with a while loop):
```c
const key_override_t **key_overrides = (const key_override_t *[]){
    &my_override,
    NULL
};
```
firmware25 uses a real array (sized with `ARRAY_SIZE`):
```c
const key_override_t *key_overrides[] = {
    &my_override,
};
```
Remove the NULL terminator; `keymap_introspection.c` uses `ARRAY_SIZE`, not
NULL termination.

### `rawhid_state` requires the oryx community module

`rawhid_state` (used to detect whether Oryx has taken over RGB control) is
defined in `modules/zsa/oryx/oryx.h`. Without the `zsa/oryx` module it is
unavailable. Guard references with `#ifdef COMMUNITY_MODULE_ORYX_ENABLE`:

```c
#ifdef COMMUNITY_MODULE_ORYX_ENABLE
    if (!rawhid_state.rgb_control && !keyboard_config.disable_layer_led) {
#else
    if (!keyboard_config.disable_layer_led) {
#endif
```

### `SRC =` vs `SRC +=` in keymap `rules.mk`

The keyboard-level `keyboards/zsa/moonlander/rules.mk` appends `mcp23018.c` via
`SRC +=`. Using `SRC =` in the keymap `rules.mk` silently overwrites this and
drops `mcp23018.c`, causing linker errors. Always use `SRC +=` in keymap files.

### `OSLIBINC` / `LIBINC` name mismatch in ChibiOS

`platforms/chibios/platform.mk` references `$(OSLIBINC)` but the version of
`lib/chibios/os/oslib/oslib.mk` in this repo defines `$(LIBINC)`. Fixed by
adding `OSLIBINC ?= $(LIBINC)` in `platform.mk` after the `oslib.mk` include.

### `-Wstrict-prototypes` in Apple clang

Apple clang 21 (Xcode 26) enables `-Wstrict-prototypes` by default. Two QMK
files needed `()` → `(void)` to silence it in test builds:
- `quantum/process_keycode/process_space_cadet.c`: `reset_space_cadet()`
- `tmk_core/protocol/usb_device_state.c`: `usb_device_state_get_protocol()`

### drashna/ChibiOS-Contrib submodule is deleted upstream

As of June 2026, `lib/chibios-contrib` points to a deleted GitHub repo
(`drashna/ChibiOS-Contrib`). The Moonlander (STM32) does not need it. In CI,
skip it with:
```sh
git -c submodule."lib/chibios-contrib".update=none submodule update --init --recursive
```

### `ast.Num` removed in Python 3.12

`lib/python/qmk/math.py` used `ast.Num` which was removed in Python 3.12.
Replaced with:
```python
if isinstance(node, ast.Constant) and isinstance(node.value, (int, float)):
    return node.value
```
