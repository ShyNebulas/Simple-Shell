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
        return 1;
    }
    else {
        return 0;
    }
}


int setPath(char *newPath) {
    int code = setenv("PATH", newPath, 1);
    return code;
}