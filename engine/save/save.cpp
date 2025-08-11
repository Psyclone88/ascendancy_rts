#include "save.h"
#include <cstdio>
bool save_bytes(const std::string& p, const std::vector<uint8_t>& d){ FILE* f=fopen(p.c_str(),"wb"); if(!f) return false; fwrite(d.data(),1,d.size(),f); fclose(f); return true; }
std::vector<uint8_t> load_bytes(const std::string& p){ std::vector<uint8_t> v; FILE*f=fopen(p.c_str(),"rb"); if(!f) return v; fseek(f,0,SEEK_END); long sz=ftell(f); fseek(f,0,SEEK_SET); v.resize(sz); fread(v.data(),1,sz,f); fclose(f); return v; }
