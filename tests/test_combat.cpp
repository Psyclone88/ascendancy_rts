#include <cassert>
#include "../game/combat.h"
int main(){
    auto r=resolve_combat(5,2,4,1,123);
    assert(r.dmgA>=0 && r.dmgB>=0);
    return 0;
}
