#include <jni.h>
#include <android/native_window_jni.h>
#include "engine/core/log.h"
#include "engine/gfx/gfx.h"
#include "engine/sim/sim.h"
#include "game/game.h"

extern "C" {
JNIEXPORT void JNICALL Java_com_ascendancy_rts_MainActivity_nativeOnCreate(JNIEnv* env, jclass, jobject surface) {
    ANativeWindow* win = ANativeWindow_fromSurface(env, surface);
    gfx_android_set_window(win);
    gfx_init(1280, 720);
    game_init();
}
JNIEXPORT void JNICALL Java_com_ascendancy_rts_MainActivity_nativeOnResize(JNIEnv*, jclass, jint w, jint h) {
    gfx_resize(w, h);
}
JNIEXPORT void JNICALL Java_com_ascendancy_rts_MainActivity_nativeOnDestroy(JNIEnv*, jclass) {
    game_shutdown();
    gfx_shutdown();
}
JNIEXPORT void JNICALL Java_com_ascendancy_rts_MainActivity_nativeOnResume(JNIEnv*, jclass) {
    log_info("Resume");
}
JNIEXPORT void JNICALL Java_com_ascendancy_rts_MainActivity_nativeOnPause(JNIEnv*, jclass) {
    log_info("Pause");
}
}
