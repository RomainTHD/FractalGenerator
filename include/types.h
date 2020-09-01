// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/09/2020.

#ifndef FRACTALGENERATOR_TYPES_H
#define FRACTALGENERATOR_TYPES_H

/**
 * Double plus précis.
 * Au pire, utilisation du type double classique (64 bits), min = 2.3e-308
 * Au mieux, utilisation de 80 bits (x86 extended precision format), min = 3.4e-4932
 */
typedef long double PreciseDouble;

/**
 * Type de fractale
 */
typedef enum {JULIA_SET, MANDELBROT_SET} FractalType;

#endif //FRACTALGENERATOR_TYPES_H
