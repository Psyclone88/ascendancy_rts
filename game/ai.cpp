#include "ai.h"
#include "engine/core/log.h"
static AIDifficulty g_diff;
void ai_init(AIDifficulty d){ g_diff=d; }
void ai_update(double){ /* build order & threat response would go here */ (void)g_diff; }
