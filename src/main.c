// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include "main.h"

extern Config config;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* argv[]) {
    Window* window;
    Renderer* renderer;

    if (initDisplay(&config, &window, &renderer) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    resetDisplay(renderer);

    clock_t start, end;

    printf("Started\n");
    start = clock();

    calculateImage(&config, renderer);

    end = clock();
    printf("Finished\n");

    double timeTaken = (double) (end - start) / (double) CLOCKS_PER_SEC;

    printf("Time: %f seconds\n", timeTaken);

    updateDisplay(renderer);
    processEvents();
    exitDisplay(window);

    return EXIT_SUCCESS;
}
