#include <cassert>
#include "../engine/sim/sim.h"
int main(){
    sim_accumulate(0.1); assert(sim_needs_tick()==false);
    sim_accumulate(0.1); assert(sim_needs_tick()==true);
    sim_consume_tick(); assert(sim_needs_tick()==false);
    return 0;
}
