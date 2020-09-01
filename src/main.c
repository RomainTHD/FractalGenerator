// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include <stdio.h>
#include <stdbool.h>

#include "main.h"

extern Config config;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* argv[]) {
    Window* window;
    Renderer* renderer;

    if (initDisplay(&config, &window, &renderer) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    resetDisplay(renderer);
    calculateImage(&config, renderer);
    printf("Finished\n");
    updateDisplay(renderer);
    processEvents();
    exitDisplay(window);

    return EXIT_SUCCESS;
}
