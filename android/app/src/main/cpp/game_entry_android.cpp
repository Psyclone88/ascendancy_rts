#include "engine/gfx/gfx.h"
#include "engine/sim/sim.h"
#include "engine/ui/ui.h"
#include "game/game.h"

extern "C" void android_main_loop_tick() {
    // Called each frame by gfx module internally (see gfx.cpp)
    const double dt = gfx_frame_time();
    sim_accumulate(dt);
    while (sim_needs_tick()) {
        game_fixed_update(sim_fixed_dt());
        sim_consume_tick();
    }
    const float alpha = sim_alpha();
    game_render(alpha);
}
