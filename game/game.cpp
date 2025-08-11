#include "game.h"
#include "engine/gfx/gfx.h"
#include "engine/ui/ui.h"
#include "engine/core/log.h"
#include "engine/path/path.h"
#include "engine/sim/sim.h"
#include "game/ui_hud.h"
#include "game/input.h"
#include "game/mapgen.h"
#include "game/ai.h"
#include <vector>
#include <string>

static int s_w=1280, s_h=720;
static bool s_contextOpen=false;
static int s_contextIndex=-1;

struct Unit { float x,y; int type; int hp; };
static std::vector<Unit> g_units;

void game_init(){
    log_info("Game Init");
    audio_init();
    mapgen_init(1337);
    g_units.push_back({10,10,0,100});
}
void game_shutdown(){ audio_shutdown(); }

void game_fixed_update(double){
    // Simple wander to demonstrate determinism
    for (auto& u: g_units) { u.x += 0.1f; if (u.x>100) u.x=10; }
}

void game_render(float){
    gfx_begin_frame();

    // World rects (placeholder visuals)
    for (auto& u: g_units) {
        gfx_draw_rect(u.x*8, u.y*8, 12, 12, 0x66FFAACC);
    }

    // HUD
    ui_begin();
    ui_label(10,10,"Ascendancy RTS 1.0.0");
    if (ui_button(10,40,160,40,"Play Click")) { audio_play_click(); }
    const char* wheel[]={"Move","Attack","Stop","Patrol","Build"};
    ui_context_wheel(s_w*0.5f,s_h*0.6f,wheel,5,&s_contextIndex,&s_contextOpen);
    ui_end();

    gfx_end_frame();
}

