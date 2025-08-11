#pragma once
#include <functional>

struct UIStyle { float scale=1.0f; };
void ui_begin();
void ui_end();
bool ui_button(float x,float y,float w,float h,const char* label);
void ui_label(float x,float y,const char* text);
void ui_context_wheel(float cx,float cy, const char** items, int count, int* outIndex, bool* open);
bool ui_minimap(float x,float y,float w,float h);
void ui_set_style(const UIStyle& s);
