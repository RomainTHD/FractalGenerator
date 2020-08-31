// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include "config.h"

Config config = {
        .x = 1.0,
        .y = 1.0,

        .windowSize = 600,
        .zoom = 1.0,
        .nbIter = 10,

        .title = "Fractal generator",

        .fractalType = MANDELBROT_SET
};
