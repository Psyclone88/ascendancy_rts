#!/usr/bin/env bash
set -euo pipefail
export ANDROID_SDK_ROOT="${ANDROID_SDK_ROOT:-$(pwd)/.android/sdk}"
cd android
./gradlew :app:assembleRelease :app:bundleRelease
echo "Release artifacts in android/app/build/outputs/{apk, bundle}/release"
