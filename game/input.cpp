#include "input.h"
#include "raylib.h"
#include "engine/ui/ui.h"
extern bool s_contextOpen;
void input_update(){
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) { s_contextOpen = true; }
}
