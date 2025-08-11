#include <cassert>
#include "../engine/path/path.h"
int main(){
    Grid g{8,8,std::vector<uint8_t>(64,1)};
    auto p=astar(g,0,0,7,7);
    assert(!p.pts.empty());
    return 0;
}
