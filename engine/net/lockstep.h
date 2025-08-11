#pragma once
#include <vector>
#include <cstdint>
struct Command { uint32_t frame; uint32_t player; uint32_t type; uint32_t a,b; };
struct Lockstep { std::vector<Command> log; };
