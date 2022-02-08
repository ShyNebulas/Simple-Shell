cmake_minimum_required(VERSION 3.20)
project(cs210_group_3_shell2 C)

set(CMAKE_C_STANDARD 11)

include_directories(src/headers)

add_executable(cs210_group_3_shell2
        src/headers/helpers.h
        src/headers/modules.h
        src/helpers/array.c
        src/helpers/input.c
        src/modules/checkCommands.c
        src/modules/execute.c
        src/modules/userInput.c
        src/main.c)
