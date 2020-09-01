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

void calculateImage(Config* config, Renderer* renderer) {
    PreciseDouble width = (PreciseDouble) config->windowSize / config->zoom;
    PreciseDouble height = (PreciseDouble) config->windowSize / config->zoom;

    PreciseDouble x0 = config->x - width / 2.;
    PreciseDouble y0 = config->y - height / 2.;

    printf("x0: %.15Lf\n", x0);
    printf("y0: %.15Lf\n", y0);
    printf("x1: %.15Lf\n", x0 + width);
    printf("y1: %.15Lf\n", y0 + height);
    printf("w: %.15Lf\n", width);
    printf("h: %.15Lf\n", height);

    /*
    const Complex inc = createComplex(
            width / (PreciseDouble) config->windowSize,
            height / (PreciseDouble) config->windowSize
            );
    */

    for (uint16_t x = 0; x < config->windowSize; x++) {
        for (uint16_t y = 0; y < config->windowSize; y++) {
            const Complex z = createComplex(
                    x0 + (width * x) / (PreciseDouble) config->windowSize,
                    y0 + (height * y) / (PreciseDouble) config->windowSize
                    );

            uint16_t s = sequence(
                    createComplex(0, 0),
                    z,
                    config->nbIter,
                    config->precision
                    );

            if (s != config->nbIter) {
                setPixel(renderer, x, y, getColor(s, config->nbIter));
            }
        }
    }
}
