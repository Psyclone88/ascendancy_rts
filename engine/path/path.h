#pragma once
#include <vector>
#include <cstdint>
#include "engine/math/math.h"

struct Grid {
    int w,h; std::vector<uint8_t> cost; // 0=blocked, 1..=cost
    bool passable(int x,int y) const { return x>=0&&y>=0&&x<w&&y<h&&cost[y*w+x]>0; }
};

struct Path { std::vector<Vec2> pts; };

Path astar(const Grid& g, int sx,int sy, int tx,int ty);
