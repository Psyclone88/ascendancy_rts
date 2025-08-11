#include "mapgen.h"
#include "engine/math/noise.h"
#include "engine/gfx/gfx.h"
static unsigned g_seed=0;
void mapgen_init(unsigned s){ g_seed=s; (void)g_seed; /* terrain baked in future; visuals handled in game_render for demo */ }
