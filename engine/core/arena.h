#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

struct Arena {
    std::vector<uint8_t> buf;
    size_t head = 0;

    void init(size_t cap) { buf.resize(cap); head = 0; }
    void reset() { head = 0; }
    void* alloc(size_t sz, size_t align=8) {
        size_t p = (head + (align-1)) & ~(align-1);
        if (p + sz > buf.size()) return nullptr;
        void* out = buf.data() + p;
        head = p + sz;
        return out;
    }
};
