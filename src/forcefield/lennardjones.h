#ifndef __MINIMD_LENNARDJONES_H
#define __MINIMD_LENNARDJONES_H

#include "../minimd/forcefield.h"

float calc_lj_energy(Box* box);
ForceField lennardjones = {
    /* calc_energy = */ calc_lj_energy
};

#endif
