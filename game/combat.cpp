#include "combat.h"
static uint32_t rng(uint32_t& s){ s ^= s<<13; s ^= s>>17; s ^= s<<5; return s; }
CombatOutcome resolve_combat(int aA,int dA,int aB,int dB,uint32_t seed){
    uint32_t s=seed;
    int rollA = (int)(rng(s)%6)+1;
    int rollB = (int)(rng(s)%6)+1;
    int dmgA = std::max(0, aA + rollA - dB);
    int dmgB = std::max(0, aB + rollB - dA);
    return {dmgA,dmgB};
}
