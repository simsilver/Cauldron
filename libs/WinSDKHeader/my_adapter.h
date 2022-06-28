#ifndef MY_ADAPTER_H
#define MY_ADAPTER_H

// make NULL defined and then redefine it
#include <string>
#include <cstring>
#undef NULL
#define NULL nullptr

// add ms std funcs not in linux
namespace std {
    inline float tanf(float v) {
        return std::tan(v);
    }
    inline float fabsf(float v) {
        return std::fabs(v);
    }

    inline float sqrtf(float v) {
        return std::sqrt(v);
    }
}// namespace std

#endif// MY_ADAPTER_H
