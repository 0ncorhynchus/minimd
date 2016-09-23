#ifndef __MINIMD_MEMORY_H
#define __MINIMD_MEMORY_H

#include <stdlib.h>

static inline float* alloc_float(const int n) {
    float* heap = (float*)malloc(sizeof(float) * n);
    if (heap == NULL)
        exit(1); // TODO Error Message
    return heap;
}

#endif
