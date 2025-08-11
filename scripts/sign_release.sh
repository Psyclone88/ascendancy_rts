#!/usr/bin/env bash
set -euo pipefail

APPID=com.ascendancy.rts
OUTDIR=android/app/build/outputs
KEYSTORE=ascendancy-release.keystore
ALIAS=ascendancy
PASS=${1:-ascendancy123}

if [ ! -f "$KEYSTORE" ]; then
  keytool -genkeypair -v -keystore "$KEYSTORE" -alias "$ALIAS" -storepass "$PASS" -keypass "$PASS" \
    -keyalg RSA -keysize 4096 -validity 36500 -dname "CN=Ascendancy,O=Studio,C=SE"
fi

APK=android/app/build/outputs/apk/release/app-release-unsigned.apk
AAB=android/app/build/outputs/bundle/release/app-release.aab

jarsigner -sigalg SHA256withRSA -digestalg SHA-256 -keystore "$KEYSTORE" -storepass "$PASS" "$APK" "$ALIAS"
${ANDROID_SDK_ROOT:-.android/sdk}/build-tools/35.0.0/apksigner sign --ks "$KEYSTORE" --ks-pass pass:"$PASS" --in "$APK" --out "${APK%.apk}-signed.apk"

jarsigner -sigalg SHA256withRSA -digestalg SHA-256 -keystore "$KEYSTORE" -storepass "$PASS" "$AAB" "$ALIAS"

echo "Signed APK: ${APK%.apk}-signed.apk"
echo "Signed AAB: $AAB"
