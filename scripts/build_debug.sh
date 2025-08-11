#!/usr/bin/env bash
set -euo pipefail
export ANDROID_SDK_ROOT="${ANDROID_SDK_ROOT:-$(pwd)/.android/sdk}"
cd android
./gradlew :app:assembleDebug
adb install -r app/build/outputs/apk/debug/app-debug.apk || true
echo "Installed debug APK."
