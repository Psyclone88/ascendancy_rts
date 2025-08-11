#include "ui.h"
#include "engine/gfx/gfx.h"
#include "raylib.h"
static UIStyle g_style;

void ui_set_style(const UIStyle& s){ g_style=s; }
void ui_begin(){}
void ui_end(){}

bool ui_button(float x,float y,float w,float h,const char* label){
    Rectangle r{ x,y,w,h };
    bool hover = CheckCollisionPointRec(GetMousePosition(), r);
    bool down = hover && IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    gfx_draw_rect(x,y,w,h, hover ? 0x88FFFFFF : 0x44FFFFFF);
    gfx_draw_text(x+8,y+8,label,0xFFFFFFFF);
    return hover && IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}
void ui_label(float x,float y,const char* text){ gfx_draw_text(x,y,text,0xFFFFFFFF); }

void ui_context_wheel(float cx,float cy,const char** items,int count,int* outIndex,bool* open){
    if(!*open) return;
    float r=60.0f;
    for(int i=0;i<count;i++){
        float ang = (float)i/count * 6.2831853f;
        float bx = cx + cosf(ang)*r - 40;
        float by = cy + sinf(ang)*r - 20;
        if (ui_button(bx,by,80,40,items[i])) { *outIndex = i; *open=false; }
    }
}
bool ui_minimap(float x,float y,float w,float h){
    gfx_draw_rect(x,y,w,h,0x2222AAFF);
    return false;
}
