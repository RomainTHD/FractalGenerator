// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/09/2020.

#include "display.h"

uint8_t initDisplay(Config* config, Window** window, Renderer** renderer) {
    setenv("DISPLAY", "127.0.0.1:0", true);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Quitte la SDL à la fin du programme
    atexit(SDL_Quit);

    SDL_CreateWindowAndRenderer(
            config->windowSize,
            config->windowSize,
            0,
            window,
            renderer
            );

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    else {
        SDL_SetWindowTitle(*window, config->title);
        SDL_SetRenderDrawBlendMode(*renderer, SDL_BLENDMODE_ADD);
        return EXIT_SUCCESS;
    }

}

void resetDisplay(Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    updateDisplay(renderer);
}

void updateDisplay(Renderer* renderer) {
    SDL_RenderPresent(renderer);
}

void processEvents() {
    SDL_Event event;

    do {
        SDL_PollEvent(&event);
        SDL_Delay(10);
    }
    while (event.type != SDL_QUIT);
}

void exitDisplay(Window* window) {
    SDL_DestroyWindow(window);
}

void setPixel(Renderer* renderer, uint16_t x, uint16_t y, Color c) {
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderDrawPoint(renderer, x, y);
}
