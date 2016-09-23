#include <stdlib.h>
#include "memory.h"
#include "container.h"

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
