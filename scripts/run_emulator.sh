#!/usr/bin/env bash
set -euo pipefail
echo "Use Android Studio or avdmanager to create an emulator image, then run:"
echo "$ANDROID_SDK_ROOT/emulator/emulator -avd <name> -gpu host"
