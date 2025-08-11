#include "audio.h"
#include "raylib.h"

static Sound s_click;
void audio_init(){
    if(!IsAudioDeviceReady()) InitAudioDevice();
    Wave w = GenTriangleWave(440.0, 0.05);
    s_click = LoadSoundFromWave(w);
    UnloadWave(w);
}
void audio_shutdown(){ if (IsSoundReady(s_click)) UnloadSound(s_click); }
void audio_play_click(){ PlaySound(s_click); }
