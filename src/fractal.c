// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include "fractal.h"

static int sequence(Complex z, Complex c, int iterMax, double sequenceLimit) {
    for (int i = 0; i < iterMax; i++) {
        z = addComplex(multComplex(z, z), c);

        if (modulusComplex(z) > sequenceLimit) {
            return i;
        }
    }

    return iterMax;
}
