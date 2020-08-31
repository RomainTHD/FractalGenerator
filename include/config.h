// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#ifndef FRACTALGENERATOR_CONFIG_H
#define FRACTALGENERATOR_CONFIG_H

#include "fractal.h"

/**
 * Config
 */
typedef struct {
    /**
     * Position X
     */
    double x;

    /**
     * Position Y
     */
    double y;

    /**
     * Taille de la fenêtre
     */
    int windowSize;

    /**
     * Niveau de zoom
     */
    double zoom;

    /**
     * Nombre d'itérations
     */
    int nbIter;

    /**
     * Titre de la fenêtre
     */
    char* title;

    /**
     * Type de fractale
     */
    FractalType fractalType;
} Config;

#endif //FRACTALGENERATOR_CONFIG_H
