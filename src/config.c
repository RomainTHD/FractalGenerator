// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include "config.h"

Config config = {
        .x = 0.,
        .y = 0.,

        .windowSize = 600,
        .zoom = 10e4,
        .nbIter = 200,
        .precision = 10e5,

        .title = "Fractal generator",

        .fractalType = JULIA_SET,

        .juliaRe = -0.55,
        .juliaIm = 0.55
};
