#include <math.h>
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


void get_direction(Box* box, size_t i, size_t j,
        float* vector) {
    for (int idx = 0; idx < 3; ++idx) {
        vector[idx] = box->container->coordinates[3*j + idx]
            - box->container->coordinates[3*i + idx];
    }
}

float get_length(Box* box, size_t i, size_t j) {
    float vector[3];
    get_direction(box, i, j, vector);
    return length(vector);
}
