#pragma once
#include <vector>
#include <cstdint>
#include <string>
struct ReplayEvent { double t; uint32_t cmd; uint32_t a,b; };
struct Replay { std::vector<ReplayEvent> events; };
bool save_bytes(const std::string& path, const std::vector<uint8_t>& data);
std::vector<uint8_t> load_bytes(const std::string& path);
