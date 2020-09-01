// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include "complex.h"

Complex cloneComplex(Complex c) {
    return (Complex) {
        .re = c.re,
        .im = c.im
    };
}

Complex createComplex(PreciseDouble re, PreciseDouble im) {
    return (Complex) {
        .re = re,
        .im = im
    };
}

bool equalComplex(Complex c1, Complex c2) {
    return (c1.re == c2.re && c1.im == c2.im);
}

void setRe(Complex* c, PreciseDouble re) {
    c->re = re;
}

void setIm(Complex* c, PreciseDouble im) {
    c->im = im;
}

double modulusComplex(Complex c) {
    return sqrt(c.re*c.re + c.im*c.im);
}

Complex addComplex(Complex c1, Complex c2) {
    return createComplex(c1.re + c2.re, c1.im + c2.im);
}

Complex multComplex(Complex c1, Complex c2) {
    return createComplex(
            c1.re * c2.re - c1.im * c2.im,
            c1.re * c2.im + c1.im * c2.re
            );
}
