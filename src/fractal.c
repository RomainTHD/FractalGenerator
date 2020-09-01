// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include "fractal.h"

uint16_t sequence(Complex z, Complex inc, uint16_t iterMax, PreciseDouble sequenceLimit) {
    for (uint16_t i = 0; i < iterMax; i++) {
        z = addComplex(multComplex(z, z), inc);

        if (modulusComplex(z) > sequenceLimit) {
            return i;
        }
    }

    return iterMax;
}
