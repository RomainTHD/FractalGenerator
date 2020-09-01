// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#ifndef FRACTALGENERATOR_FRACTAL_H
#define FRACTALGENERATOR_FRACTAL_H

#include <stdint.h>

#include "complex.h"

/**
 * Type de fractale
 */
typedef enum {JULIA_SET, MANDELBROT_SET} FractalType;

/**
 * Séquence d'une fractale, i.e. nombre d'itérations nécessaires au module de z pour atteindre
 * <code>sequenceLimit</code> en suivant l'équation <code>z = z<sup>2</sup> + c</code>
 *
 * @param z Nombre de base
 * @param inc Incrément
 * @param iterMax Nombre d'itérations max
 * @param sequenceLimit Limite de la séquence
 *
 * @return Nombre d'itérations
 */
uint16_t sequence(Complex z, Complex inc, uint16_t iterMax, PreciseDouble sequenceLimit);

#endif //FRACTALGENERATOR_FRACTAL_H
