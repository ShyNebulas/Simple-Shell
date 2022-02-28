#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../dep/headers/functionDefinitions.h"

// --------------------------------------------------
// Function which returns the size of a char array,
// array = array of chars
// e.g. ['a', 'b', 'c'] returns 3
// --------------------------------------------------
int sizeOfCharArray(char *array) {

    int size = 0; 

    for(; array[size] != '\0'; size++);

    return size;

}

// --------------------------------------------------
// Function which clears the input buffer,
// i.e. anything that fgets() leaves behind
// --------------------------------------------------
void clearInputBuffer() {

    while((getchar()) != '\n');

}

// --------------------------------------------------
// Function which maps a commands name to its command,
// rows = array's rows
// tokens = array of strings
// --------------------------------------------------
bool checkTokensForCommands(int rows, char *tokens[rows]) {

    // If empty string exists
    if(tokens[0] == NULL) {

        return false;

    }

    else if(strcmp(tokens[0], "exit") == 0) {

        return true;

    }

    else if(strcmp(tokens[0], "getpath")== 0) {

        if(tokens[1] == NULL) {

            printf("%s %s", getPath(), "\n");

        }

        else {

            perror("[Error] Getpath does not take parameters");

        }

        return false;

    }

    else if(strcmp(tokens[0], "setpath")== 0) {

        if(tokens[1] == NULL) {

            perror("[Error] No parameters provided");

            return false;

        }

        int err = setPath(tokens[1]);

        if(err < 0){

            perror("[Error] Could not execute command");

        }

        else if(err == 0) {

            return false;

        }
        
    }

    else if(strcmp(tokens[0], "cd") == 0) {

        if (tokens[1] == NULL) {

            changeDir(getenv("HOME"));

            return false;

        }

        else {

            int err = changeDir(tokens[1]);

            return false;

        }

    }

    else {
 
        execute(rows, tokens);

    }

    return false;

}

// --------------------------------------------------
// Function which returns the enviromental PATH,
// --------------------------------------------------
char* getPath() {

    char *path;

    path = getenv("PATH");

    return getenv("PATH");

}


