#pragma once
#include <cstdint>
struct ANativeWindow;
void gfx_android_set_window(ANativeWindow* win);
bool gfx_init(int w, int h);
void gfx_shutdown();
void gfx_resize(int w, int h);
double gfx_frame_time();
void gfx_begin_frame();
void gfx_end_frame();
void gfx_draw_rect(float x,float y,float w,float h, unsigned int rgba);
void gfx_draw_text(float x,float y,const char* text, unsigned int rgba, float scale=1.0f);
