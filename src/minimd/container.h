#ifndef __MINIMD_CONTAINER_H
#define __MINIMD_CONTAINER_H

#include <stddef.h> // size_t

typedef struct Container {
    int num_beads;
    float* mass;
    float* coordinates;
    float* velocities;
} Container;

Container* alloc_cont(const int num_beads);
void dealloc_cont(Container* container);

void get_coordinate(Container* container, size_t i, float* vector);
void set_coordinate(Container* container, size_t i,
        float x, float y, float z);

#endif /* __MINIMD_CONTAINER_H */
