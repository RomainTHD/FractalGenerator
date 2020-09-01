// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/08/2020.

#include <stdio.h>
#include <stdbool.h>

#include "main.h"

extern Config config;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* argv[]) {
    Window* window;
    Renderer* renderer;

    if (initDisplay(&config, &window, &renderer) == EXIT_SUCCESS) {
        display(&config, renderer);
        processEvents();
        exitDisplay(window);
    }
    else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
