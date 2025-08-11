#pragma once
#include <string>
#include <vector>
#include <cstdio>

inline std::vector<uint8_t> file_read_all(const std::string& p){
    std::vector<uint8_t> out;
    FILE* f=fopen(p.c_str(),"rb"); if(!f) return out;
    fseek(f,0,SEEK_END); long sz=ftell(f); fseek(f,0,SEEK_SET);
    out.resize(sz); fread(out.data(),1,sz,f); fclose(f); return out;
}
