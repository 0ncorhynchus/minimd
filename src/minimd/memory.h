#ifndef __MINIMD_MEMORY_H
#define __MINIMD_MEMORY_H

#include <stdlib.h>

static inline float* alloc_float(const size_t n) {
    float* heap = (float*)calloc(n, sizeof(float));
    if (heap == NULL)
        exit(1); // TODO Error Message
    return heap;
}

#endif
