#pragma once
#include <cstdio>
inline void log_info(const char* fmt, ...) {
    va_list args; va_start(args, fmt); vfprintf(stdout, fmt, args); fprintf(stdout, "\n"); va_end(args);
}
inline void log_warn(const char* fmt, ...) {
    va_list args; va_start(args, fmt); vfprintf(stderr, fmt, args); fprintf(stderr, "\n"); va_end(args);
}
inline void log_err(const char* fmt, ...) {
    va_list args; va_start(args, fmt); vfprintf(stderr, fmt, args); fprintf(stderr, "\n"); va_end(args);
}
