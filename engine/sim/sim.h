#pragma once
double sim_fixed_dt();
void sim_accumulate(double dt);
bool sim_needs_tick();
void sim_consume_tick();
float sim_alpha();
