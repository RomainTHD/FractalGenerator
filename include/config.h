// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#ifndef FRACTALGENERATOR_CONFIG_H
#define FRACTALGENERATOR_CONFIG_H

#include <stdint.h>

#include "types.h"

/**
 * Config
 */
typedef struct {
    /**
     * Position X
     */
    PreciseDouble x;

    /**
     * Position Y
     */
    PreciseDouble y;

    /**
     * Taille de la fenêtre
     */
    uint16_t windowSize;

    /**
     * Niveau de zoom
     */
    PreciseDouble zoom;

    /**
     * Nombre d'itérations
     */
    uint16_t nbIter;

    /**
     * Précision, valeur à atteindre avant de conclure à une divergence
     */
    PreciseDouble precision;

    /**
     * Titre de la fenêtre
     */
    char* title;

    /**
     * Type de fractale
     */
    FractalType fractalType;

    /**
     * Partie réelle Julia
     */
    PreciseDouble juliaRe;

    /**
     * Partie imaginaire Julia
     */
    PreciseDouble juliaIm;
} Config;

#endif //FRACTALGENERATOR_CONFIG_H
