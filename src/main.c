// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "main.h"

extern Config config;

int main(int argc, char* argv[]) {
    setenv("DISPLAY", "127.0.0.1:0", true);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Quitte la SDL à la fin du programme
    atexit(SDL_Quit);

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_CreateWindowAndRenderer(config.windowSize, config.windowSize, 0, &window, &renderer);

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
    SDL_SetWindowTitle(window, config.title);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // calculateImage(config, )

    SDL_RenderPresent(renderer);


    SDL_Event event;

    do {
        SDL_PollEvent(&event);
        SDL_Delay(10);
    }
    while (event.type != SDL_QUIT);

    SDL_DestroyWindow(window);

    return EXIT_SUCCESS;
}
