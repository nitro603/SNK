cmake_minimum_required(VERSION 4.3)
project(Snake C)

set(CMAKE_C_STANDARD 11)

add_library(Snake STATIC library.c
        main.c
        learning.c)
