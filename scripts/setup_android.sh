#!/usr/bin/env bash
set -euo pipefail

# Installs Android SDK/NDK/Build-Tools locally in .android and fetches raylib.
# Ubuntu deps
sudo apt-get update
sudo apt-get install -y openjdk-17-jdk unzip zip curl git cmake ninja-build python3

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
ANDROID_HOME="$ROOT/.android/sdk"
ANDROID_NDK_VERSION="26.3.11579264"
SDK_BUILD_TOOLS="35.0.0"
SDK_PLATFORM="android-34"

mkdir -p "$ANDROID_HOME"
export ANDROID_HOME
export ANDROID_SDK_ROOT="$ANDROID_HOME"
export PATH="$ANDROID_HOME/cmdline-tools/latest/bin:$PATH"

# Download cmdline-tools
if [ ! -d "$ANDROID_HOME/cmdline-tools/latest" ]; then
  mkdir -p "$ANDROID_HOME/cmdline-tools"
  cd "$ANDROID_HOME/cmdline-tools"
  curl -L -o tools.zip https://dl.google.com/android/repository/commandlinetools-linux-11076708_latest.zip
  unzip -q tools.zip -d latest
  rm tools.zip
fi

yes | sdkmanager --licenses

sdkmanager "platform-tools" \
           "platforms;$SDK_PLATFORM" \
           "build-tools;$SDK_BUILD_TOOLS" \
           "cmake;3.22.1" \
           "ndk;$ANDROID_NDK_VERSION"

# Fetch raylib at pinned tag
cd "$ROOT/third_party"
if [ ! -d raylib/.git ]; then
  git clone --depth=1 --branch 5.0 https://github.com/raysan5/raylib.git
fi

# Generate simple app icons (procedural)
python3 - <<'PY'
from PIL import Image, ImageDraw, ImageFont
import os
sizes=[(48,'mipmap-mdpi'),(72,'mipmap-hdpi'),(96,'mipmap-xhdpi'),(144,'mipmap-xxhdpi'),(192,'mipmap-xxxhdpi')]
root=os.path.join('android','app','src','main','res')
for sz,dirn in sizes:
    p=os.path.join(root,dirn)
    os.makedirs(p,exist_ok=True)
    img=Image.new('RGBA',(sz,sz),(20,24,28,255))
    d=ImageDraw.Draw(img)
    d.ellipse((6,6,sz-6,sz-6),outline=(120,200,255,255),width=max(2,sz//16))
    d.rectangle((sz//3,sz//3,sz-6,sz-6),outline=(255,200,80,255),width=max(2,sz//16))
    img.save(os.path.join(p,'ic_launcher.png'))
print("Icons generated.")
PY

echo "Android SDK installed under $ANDROID_HOME"
echo "Raylib fetched under third_party/raylib"
