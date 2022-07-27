#ifndef MY_ADAPTER_H
#define MY_ADAPTER_H

#include <cmath>
#include <SDL.h>

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

inline char *my_strcpy_size (char *dst, const char *src, size_t size) {
    return strncpy(dst, src, size - 1);
}

inline char *my_strncat_size (char *dest, const char *src, size_t n, size_t size) {
    int len = strlen(dest);
    int left = size - len - 1;
    if(left < 0) {
        left = 0;
    }
    if(left > n) {
        return strncat(dest, src, n);
    } else {
        return strncat(dest, src, left);
    }
}

inline double max(double v1, double v2) {
    if(v1 >= v2) {
        return v1;
    } else {
        return v2;
    }
}

typedef uint32_t UINT32;


#define VK_TAB SDLK_KP_TAB
#define VK_LEFT SDLK_LEFT
#define VK_RIGHT SDLK_RIGHT
#define VK_UP SDLK_UP
#define VK_DOWN SDLK_DOWN
#define VK_PRIOR SDLK_PAGEUP
#define VK_NEXT SDLK_PAGEDOWN
#define VK_HOME SDLK_HOME
#define VK_END SDLK_END
#define VK_DELETE SDLK_DELETE
#define VK_BACK SDLK_BACKSPACE
#define VK_RETURN SDLK_RETURN
#define VK_ESCAPE SDLK_ESCAPE
#define VK_CONTROL SDLK_LCTRL
#define VK_SHIFT SDLK_LSHIFT
#define VK_MENU SDLK_LALT

#endif// MY_ADAPTER_H
