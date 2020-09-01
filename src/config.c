// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include "config.h"

Config config = {
        .x = -1.,
        .y = 0.,

        .windowSize = 600,
        .zoom = 250.,
        .nbIter = 40,
        .precision = 10.,

        .title = "Fractal generator",

        .fractalType = MANDELBROT_SET
};
