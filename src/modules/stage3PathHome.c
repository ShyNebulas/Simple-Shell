//
// Created by Ayushi Badiyani on 2/8/22.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../headers/functionDefinitions.h"

int changeDirToHome () {
    char *home = getenv("HOME");
    int val = chdir(home);
    if (val <0 ) {
        perror("Couldn't change directory to home\n");
    }
    else {
        return 0;
    }
}


int getAndPrintCurrentPath () {
    printf("hi");
    printf("%s %s", getPath(), "\n");
    return 0;
}

int setPath(char *newPath) {
    int code = setenv("PATH", newPath, 0);
    return code;
}