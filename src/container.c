#include <stdlib.h>
#include "container.h"

inline float* alloc_float(const int n) {
    float* heap = (float*)malloc(sizeof(float) * n);
    if (heap == NULL)
        exit(1); // TODO Error Message
    return heap;
}

void alloc_cont(const int num_beads, Container* container) {
    container->num_beads = num_beads;
    container->mass = alloc_float(num_beads);
    container->coordinates = alloc_float(num_beads);
    container->velocities = alloc_float(num_beads);
}

void dealloc_cont(Container* container) {
    free(container->mass);
    free(container->coordinates);
    free(container->velocities);
}
