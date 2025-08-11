#include "sim.h"
static const double FIXED_DT = 1.0/15.0; // 15 Hz
static double acc=0.0;
void sim_accumulate(double dt){ if(dt>0.25) dt=0.25; acc+=dt; }
bool sim_needs_tick(){ return acc >= FIXED_DT; }
void sim_consume_tick(){ acc -= FIXED_DT; }
double sim_fixed_dt(){ return FIXED_DT; }
float sim_alpha(){ return (float)(acc/FIXED_DT); }
