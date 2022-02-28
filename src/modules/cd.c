#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../dep/headers/functionDefinitions.h"

// --------------------------------------------------
// Function changes the current directory to the new given directory,
// newDirectory = new directory
// --------------------------------------------------
int changeDir(char *newDirectory) {

    int val = chdir(newDirectory);

    if (val < 0) {

        perror("[Error] Couldn't change directory, does not exist\n");

        return 1;

    }

    return 0;

}

// --------------------------------------------------
// Function changes the current path to the new given directory,
// newPath = new path
// --------------------------------------------------
int setPath(char *newPath) {

    return setenv("PATH", newPath, 1);

}

