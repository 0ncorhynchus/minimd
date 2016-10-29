#include <stdlib.h>
#include "memory.h"
#include "container.h"

void get_coordinate(Container* container, size_t i, float* vector) {
    for (size_t idx = 0; idx < 3; ++idx) {
        vector[idx] = container->coordinates[3*i + idx];
    }
}

void set_coordinate(Container* container, size_t i,
        float x, float y, float z) {
    container->coordinates[3*i + 0] = x;
    container->coordinates[3*i + 1] = y;
    container->coordinates[3*i + 2] = z;
}

Container* alloc_cont(const int num_beads) {
    Container* container = (Container*)malloc(sizeof(Container));
    container->num_beads = num_beads;
    container->mass = alloc_float(num_beads);
    container->coordinates = alloc_float(3*num_beads);
    container->velocities = alloc_float(3*num_beads);
    return container;
}

void dealloc_cont(Container* container) {
    if (container == NULL) return;
    free(container->velocities);
    free(container->coordinates);
    free(container->mass);
    free(container);
}
