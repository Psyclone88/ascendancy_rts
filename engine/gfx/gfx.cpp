#include "gfx.h"
#include "engine/core/log.h"
#include "engine/core/profile.h"
#include "engine/ui/ui.h"
#include "engine/sim/sim.h"
#include "raylib.h"
#include "stb_easy_font.h"

static double s_lastTime=0.0;
static ANativeWindow* s_win=nullptr;

void gfx_android_set_window(ANativeWindow* win){ s_win=win; }

bool gfx_init(int w,int h){
#if defined(PLATFORM_ANDROID)
    if (s_win) SetAndroidAppWindow(s_win);
#endif
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(w,h,"Ascendancy RTS");
    SetTargetFPS(0); // render uncapped; we interpolate
    InitAudioDevice();
    s_lastTime = GetTime();
    return true;
}
void gfx_shutdown(){ CloseAudioDevice(); CloseWindow(); }
void gfx_resize(int w,int h){ SetWindowSize(w,h); }

double gfx_frame_time(){
    double t=GetTime(); double dt=t-s_lastTime; s_lastTime=t; return dt;
}

void gfx_begin_frame(){ BeginDrawing(); ClearBackground({20,24,28,255}); }
void gfx_end_frame(){ EndDrawing(); }

void gfx_draw_rect(float x,float y,float w,float h,unsigned int rgba){
    Color c{(unsigned char)((rgba>>24)&255),(unsigned char)((rgba>>16)&255),(unsigned char)((rgba>>8)&255),(unsigned char)(rgba&255)};
    DrawRectangle((int)x,(int)y,(int)w,(int)h,c);
}

void gfx_draw_text(float x,float y,const char* text,unsigned int rgba,float scale){
    char buf[9999]; int quads = stb_easy_font_print(x,y,(char*)text,nullptr,buf,sizeof(buf));
    Color c{(unsigned char)((rgba>>24)&255),(unsigned char)((rgba>>16)&255),(unsigned char)((rgba>>8)&255),(unsigned char)(rgba&255)};
    for (int i=0;i<quads;i++){
        float* v = (float*)buf + i*16;
        DrawTriangle({v[0],v[1]}, {v[2],v[3]}, {v[4],v[5]}, c);
        DrawTriangle({v[4],v[5]}, {v[6],v[7]}, {v[0],v[1]}, c);
    }
}
