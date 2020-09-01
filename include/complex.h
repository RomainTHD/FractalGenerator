// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#ifndef FRACTALGENERATOR_COMPLEX_H
#define FRACTALGENERATOR_COMPLEX_H

#include <stdbool.h>
#include <math.h>

#include "types.h"

/**
 * Nombre complexe
 */
typedef struct {
    PreciseDouble re;
    PreciseDouble im;
} Complex;

/**
 * Clone un complexe
 *
 * @param c Complexe à cloner
 *
 * @return Copie
 */
Complex cloneComplex(Complex c);

/**
 * Crée un complexe
 *
 * @param re Partie réelle
 * @param im Partie imaginaire
 *
 * @return Complexe
 */
Complex createComplex(PreciseDouble re, PreciseDouble im);

/**
 * Complexe égaux ou non
 *
 * @param c1 Complexe 1
 * @param c2 Complexe 2
 *
 * @return Égaux ou non
 */
bool equalComplex(Complex c1, Complex c2);

/**
 * Set la partie réelle
 *
 * @param c Complexe
 * @param re Partie réelle
 */
void setRe(Complex* c, PreciseDouble re);

/**
 * Set la partie imaginaire
 *
 * @param c Complexe
 * @param re Partie imaginaire
 */
void setIm(Complex* c, PreciseDouble im);

/**
 * Calcule le module d'un complexe, i.e. <code>sqrt(re<sup>2</sup> + im<sup>2</sup>)</code>
 *
 * @param c Complexe
 *
 * @return Module
 */
PreciseDouble modulusComplex(Complex c);

/**
 * Calcule le carré du module d'un complexe, i.e. <code>re<sup>2</sup> + im<sup>2</sup></code>
 *
 * @param c Complexe
 *
 * @return Module au carré
 */
PreciseDouble modulusComplexSq(Complex c);

/**
 * Somme deux complexes
 *
 * @param c1 Complexe 1
 * @param c2 Complexe 2
 *
 * @return Somme des complexes
 */
Complex addComplex(Complex c1, Complex c2);

/**
 * Multiplie deux complexes, i.e. <code>(a + i.b) * (c + i.d) = (a*c - b*d) + i.(a*d + b*c)</code>
 *
 * @param c1 Complexe 1
 * @param c2 Complexe 2
 *
 * @return Produit des complexes
 */
Complex multComplex(Complex c1, Complex c2);

#endif //FRACTALGENERATOR_COMPLEX_H
