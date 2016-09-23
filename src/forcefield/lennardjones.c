#include <math.h>
#include "lennardjones.h"

inline float calc_unit_energy(
        const float epsilon, const float sigma, const float length) {
    const float ratio = sigma / length;
    return 4 * epsilon * (pow(ratio, 12.0) - pow(ratio, 6.0));
}

float calc_lj_energy(Box* box) {
    const float sigma = 1.0;
    const float epsilon = 1.0;
    float energy = 0.0;
    for (size_t i = 1; i < num_beads(box); ++i)
        for (size_t j = 0; j < i; ++j) {
            energy += calc_unit_energy(epsilon, sigma,
                    get_length(box, i, j));
        }
    return energy;
}
