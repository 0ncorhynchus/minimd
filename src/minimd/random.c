#include <stdlib.h>
#include "random.h"

void set_seed(unsigned int seed) {
    srand(seed);
}

float uniform() {
    return rand() / (RAND_MAX + 1.0);
}

int uniform_int(unsigned int max) {
    return rand() % (max+1);
}
