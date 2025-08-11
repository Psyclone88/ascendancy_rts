#pragma once
#include <chrono>
struct ProfScope {
    const char* name;
    std::chrono::high_resolution_clock::time_point t0;
    ProfScope(const char* n):name(n),t0(std::chrono::high_resolution_clock::now()){}
    ~ProfScope(){
        auto t1=std::chrono::high_resolution_clock::now();
        auto us=std::chrono::duration_cast<std::chrono::microseconds>(t1-t0).count();
        // Keep minimal to avoid Android log spam in release.
        (void)us;
    }
};
