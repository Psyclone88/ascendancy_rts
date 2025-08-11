#!/usr/bin/env bash
set -euo pipefail
APK=android/app/build/outputs/apk/debug/app-debug.apk
adb install -r "$APK"
adb shell monkey -p com.ascendancy.rts -c android.intent.category.LAUNCHER 1
