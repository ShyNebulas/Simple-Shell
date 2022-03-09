cmake_minimum_required(VERSION 3.21)
project(cs210_group_3_shell)

set(CMAKE_CXX_STANDARD 14)

include_directories(build)
include_directories(dep)
include_directories(dep/headers)
include_directories(src)

add_executable(cs210_group_3_shell
        build/main
        build/Makefile
        dep/headers/functionDefinitions.h
        src/helpers/helperFunctions.c
        src/modules/cd.c
        src/modules/execute.c
        src/modules/userInput.c
        src/modules/history.c
        src/main.c)
