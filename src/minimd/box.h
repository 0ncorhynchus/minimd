#ifndef __MINIMD_BOX_H
#define __MINIMD_BOX_H

#include "container.h"

typedef struct Box {
    Container* container;
    void (*calc_direction)(Container*, size_t, size_t, float*);
    float (*calc_length)(Container*, size_t, size_t);
} Box;

Box* alloc_normal_box(Container* container);
void dealloc_box(Box* box);

size_t num_beads(Box* box);

void get_direction(Box* box, size_t i, size_t j, float* vector);
float get_length(Box* box, size_t i, size_t j);

#endif
