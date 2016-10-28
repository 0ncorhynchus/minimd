#include <math.h>
#include <stdlib.h>
#include "box.h"

size_t num_beads(Box* box) {
    return box->container->num_beads;
}

static inline float length(float* vector) {
    return sqrt(
            pow(vector[0], 2.0) +
            pow(vector[1], 2.0) +
            pow(vector[2], 2.0));
}

void calc_normal_direction(Container* container, size_t i, size_t j,
        float* vector) {
    for (int idx = 0; idx < 3; ++idx) {
        vector[idx] = container->coordinates[3*j + idx]
            - container->coordinates[3*i + idx];
    }
}

float calc_normal_length(Container* container, size_t i, size_t j) {
    float vector[3];
    calc_normal_direction(container, i, j, vector);
    return length(vector);
}

Box* alloc_normal_box(Container* container) {
    Box* box = (Box*)malloc(sizeof(Box));
    box->container = container;
    box->calc_direction = calc_normal_direction;
    box->calc_length = calc_normal_length;
    return box;
}

void get_direction(Box* box, size_t i, size_t j, float* vector) {
    box->calc_direction(box->container, i, j, vector);
}

float get_length(Box* box, size_t i, size_t j) {
    return box->calc_length(box->container, i, j);
}
