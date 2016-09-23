#ifndef __MINIMD_CONTAINER_H
#define __MINIMD_CONTAINER_H

typedef struct Container {
    int num_beads;
    float* mass;
    float* coordinates;
    float* velocities;
} Container;

void set_coordinate(Container* container, size_t i,
        float x, float y, float z);
Container* alloc_cont(const int num_beads);
void dealloc_cont(Container* container);

#endif /* __MINIMD_CONTAINER_H */
