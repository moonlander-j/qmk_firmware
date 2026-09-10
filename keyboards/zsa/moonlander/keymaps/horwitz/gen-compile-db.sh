#!/bin/sh
# Generate compile_commands.json for the horwitz keymap.
# Must be run from the repo root.
#
# QMK's build system #includes keymap.c from a generated wrapper rather than
# compiling it directly, so bear does not capture a compile_commands.json entry
# for it.  This script runs bear, then adds a synthetic entry for keymap.c by
# copying the dance.c entry (same flags) and appending the build result so
# clangd can analyze keymap.c with all the correct defines and include paths.
set -e

make zsa/moonlander/reva:horwitz:clean
bear -- make zsa/moonlander/reva:horwitz

python3 - <<'EOF'
import json, copy, sys

DB = "compile_commands.json"
KEYMAP_SRC = "keyboards/zsa/moonlander/keymaps/horwitz/keymap.c"
DANCE_SRC   = "keyboards/zsa/moonlander/keymaps/horwitz/dance.c"

with open(DB) as f:
    db = json.load(f)

# Remove any stale keymap.c entry from a previous run.
db = [e for e in db if not e["file"].endswith("keymap.c")
      or KEYMAP_SRC not in e["file"]]

# Find the dance.c entry to use as the template.
template = next((e for e in db if e["file"].endswith(DANCE_SRC)), None)
if template is None:
    sys.exit(f"dance.c entry not found in {DB}")

entry = copy.deepcopy(template)
entry["file"] = KEYMAP_SRC

db.append(entry)

with open(DB, "w") as f:
    json.dump(db, f, indent=2)

print(f"Added keymap.c entry to {DB}")
EOF

echo "Done. Restart clangd in VS Code: ⌘⇧P → clangd: Restart language server"
