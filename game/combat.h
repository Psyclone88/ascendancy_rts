#pragma once
#include <cstdint>
struct CombatOutcome { int dmgA; int dmgB; };
CombatOutcome resolve_combat(int atkA,int defA,int atkB,int defB, uint32_t seed);
