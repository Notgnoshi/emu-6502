#!/bin/bash
set -o errexit
set -o pipefail
set -o nounset

# Define EMU_REPO for use by the test script for defining paths to test assets
SOURCE="${BASH_SOURCE[0]}"
EMU_REPO="$(cd "$(dirname "$SOURCE")" >/dev/null && pwd)"
EMU_REPO="$EMU_REPO/.."
EMU_REPO="$(readlink --canonicalize --no-newline "$EMU_REPO")"

EMU_TEST="$1"

## A diff shim that gives better looking diffs if delta is installed.
diff() {
    if command -v delta &>/dev/null; then
        delta "$@"
    else
        diff --unified --color='always' "$@"
    fi
}

set -x
# shellcheck disable=SC1090
source "$EMU_TEST" # Execute the test in the current environment
