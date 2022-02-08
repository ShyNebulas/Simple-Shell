cmake_minimum_required(VERSION 3.20)
project(cs210_group_3_shell2 C)

set(CMAKE_C_STANDARD 11)

include_directories(src/headers)

add_executable(cs210_group_3_shell2
        src/helpers/helperFunctions.c
        src/modules/Stage2execute.c
        src/modules/Stage1userInput.c
        src/main.c src/headers/functionDefinitions.h)
