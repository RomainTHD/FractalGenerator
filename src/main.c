// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "main.h"

int main(int argc, char* argv[]) {
    setenv("DISPLAY", "127.0.0.1:0", true);

    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
            "Fractal Generator",
            SDL_WINDOWPOS_UNDEFINED, // Pos X
            SDL_WINDOWPOS_UNDEFINED, // Pos Y
            640, // Width
            480, // Height
            SDL_WINDOW_OPENGL // flags
    );

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Pause de 3000 ms
    SDL_Delay(3000);

    SDL_DestroyWindow(window);

    SDL_Quit();
    return EXIT_SUCCESS;
}
