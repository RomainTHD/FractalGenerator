// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include "fractal.h"

uint16_t sequence(Complex z, Complex inc, uint16_t iterMax, PreciseDouble sequenceLimitSq) {
    for (uint16_t i = 0; i < iterMax; i++) {
        z = addComplex(multComplex(z, z), inc);

        if (modulusComplexSq(z) > sequenceLimitSq) {
            return i;
        }
    }

    return iterMax;
}

Color getColor(uint16_t val, uint16_t max) {
    val = ((double) val / (double) max) * 255. * 2.;

    Color c = (Color) {
        .r = 0,
        .g = 0,
        .b = 0,
        .a = 255
    };

    if (val <= 255) {
        c.r = 255; // c.b
        c.g = 255 - val;
    }

    if (val > 255 && val <= 255 * 2) {
        c.r = 2*255 - val; // c.b
        c.b = val - 255; // c.g
    }

    return c;
}

void calculateImage(const Config* const config, Renderer* renderer) {
    const PreciseDouble width = (PreciseDouble) config->windowSize / config->zoom;
    const PreciseDouble height = (PreciseDouble) config->windowSize / config->zoom;

    const PreciseDouble x0 = config->x - width / 2.;
    const PreciseDouble y0 = config->y - height / 2.;

    const Complex juliaInc = createComplex(config->juliaRe, config->juliaIm);

    const Complex zero = createComplex(0, 0);

    const PreciseDouble precisionSq = config->precision * config->precision;

    for (uint16_t x = 0; x < config->windowSize; x++) {
        for (uint16_t y = 0; y < config->windowSize; y++) {
            const Complex z = createComplex(
                    x0 + (width * x) / (PreciseDouble) config->windowSize,
                    y0 + (height * y) / (PreciseDouble) config->windowSize
                    );

            uint16_t seq;

            if (config->fractalType == JULIA_SET) {
                seq = sequence(
                        z,
                        juliaInc,
                        config->nbIter,
                        precisionSq
                );
            }
            else {
                 seq = sequence(
                         zero,
                         z,
                         config->nbIter,
                         precisionSq
                );
            }

            if (seq != config->nbIter) {
                setPixel(renderer, x, y, getColor(seq, config->nbIter));
            }
        }
    }
}
