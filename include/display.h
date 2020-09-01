// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/09/2020.

#ifndef FRACTALGENERATOR_DISPLAY_H
#define FRACTALGENERATOR_DISPLAY_H

#include <stdint.h>
#include <SDL.h>
#include <stdbool.h>

#include "config.h"

/**
 * Fenêtre, abstraction de la SDL
 */
typedef SDL_Window Window;

/**
 * Renderer, abstraction de la SDL
 */
typedef SDL_Renderer Renderer;

/**
 * Type couleur
 */
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} Color;

/**
 * Initialise l'affichage
 *
 * @param config Config
 * @param window Fenêtre
 * @param renderer Renderer
 *
 * @return Code d'erreur
 */
uint8_t initDisplay(Config* config, Window** window, Renderer** renderer);

/**
 * Reset l'affichage
 *
 * @param renderer Renderer
 */
void resetDisplay(Renderer* renderer);

/**
 * Met à jour l'affichage
 *
 * @param renderer Renderer0
 */
void updateDisplay(Renderer* renderer);

/**
 * Set un pixel
 *
 * @param renderer
 */
void setPixel(Renderer* renderer, uint16_t x, uint16_t y, Color c);

/**
 * Gestion des évènements
 */
void processEvents();

/**
 * Quitte l'affichage
 *
 * @param window Fenêtre
 */
void exitDisplay(Window* window);

#endif //FRACTALGENERATOR_DISPLAY_H
