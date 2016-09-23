#ifndef __MINIMD_BOX_H
#define __MINIMD_BOX_H

#include "container.h"

typedef struct Box {
    Container* container;
} Box;

size_t num_beads(Box* box);
void get_direction(Box* box, size_t i, size_t j,
        float* vector);
float get_length(Box* box, size_t i, size_t j);

#endif
