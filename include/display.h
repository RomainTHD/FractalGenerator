// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/09/2020.

#ifndef FRACTALGENERATOR_DISPLAY_H
#define FRACTALGENERATOR_DISPLAY_H

#include <stdint.h>
#include <SDL.h>

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
 * Affichage
 *
 * @param config Config
 * @param renderer Renderer
 */
void display(Config* config, Renderer* renderer);

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
