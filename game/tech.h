#pragma once
#include <string>
#include <vector>
struct Tech { std::string id; int epoch; std::string desc; };
extern std::vector<Tech> g_techs;
void tech_load_defaults();
