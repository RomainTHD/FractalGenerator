cmake_minimum_required(VERSION 3.10)

project(FractalGenerator C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(./include)

set(SOURCE_FILES
        src/main.c
        src/config.c
        src/complex.c src/fractal.c)

set(HEADER_FILES
        include/main.h
        include/config.h
        include/fractal.h
        include/complex.h)

add_executable(FractalGenerator ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(FractalGenerator ${SDL2_LIBRARIES})
target_link_libraries(FractalGenerator m)
