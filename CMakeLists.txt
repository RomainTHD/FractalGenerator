cmake_minimum_required(VERSION 3.10)

project(FractalGenerator C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(./include)

set(HEADER_FILES
        include/complex.h
        include/config.h
        include/display.h
        include/fractal.h
        include/main.h
        include/types.h
        )

set(SOURCE_FILES
        src/complex.c
        src/config.c
        src/display.c
        src/fractal.c
        src/main.c
        )

add_executable(FractalGenerator ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(FractalGenerator ${SDL2_LIBRARIES})
target_link_libraries(FractalGenerator m)
