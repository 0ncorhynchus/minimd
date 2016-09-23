#ifndef __MINIMD_CONTAINER_H
#define __MINIMD_CONTAINER_H

typedef struct Container {
    int num_beads;
    float* mass;
    float* coordinates;
    float* velocities;
} Container;

void alloc_cont(const int num_beads, Container* container);
void dealloc_cont(Container* container);

#endif /* __MINIMD_CONTAINER_H */
