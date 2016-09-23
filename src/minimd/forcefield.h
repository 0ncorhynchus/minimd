#ifndef __MINIMD_FORCEFIELD_H
#define __MINIMD_FORCEFIELD_H

#include "box.h"

typedef struct {
    float (*calc_energy)(Box*);
} ForceField;

#endif
