cmake_minimum_required(VERSION 3.20)
project(cs210_group_3_shell C)

set(CMAKE_C_STANDARD 11)

include_directories(dep)
include_directories(dep/headers)

add_executable(cs210_group_3_shell
        dep/headers/functionDefinitions.h
        src/helpers/helperFunctions.c
        src/modules/cd.c
        src/modules/execute.c
        src/modules/history.c
        src/modules/userInput.c
        src/main.c src/modules/alias.c)
