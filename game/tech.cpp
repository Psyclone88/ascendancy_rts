#include "tech.h"
std::vector<Tech> g_techs;
void tech_load_defaults(){
    g_techs = {
        {"foraging",1,"Basic gathering speed +10%"},
        {"bronze_working",2,"Unlock bronze units"},
        {"iron_casting",3,"Melee +1"},
        {"feudal_law",4,"Population cap +10"},
        {"steam_power",5,"Work speed +10%"},
        {"ballistics",6,"Ranged accuracy +10%"},
        {"automation",7,"Economy +10%"},
    };
}
