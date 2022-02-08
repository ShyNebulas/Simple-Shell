#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../headers/functionDefinitions.h"

// --------------------------------------------------
// Function which returns the size of a char array, 
// e.g. ['a', 'b', 'c'] returns 3
// --------------------------------------------------
int sizeOfCharArray(char * array) {

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

bool checkTokensForCommands(int rows, char *tokens[rows]) {
    if(strcmp(tokens[0], "exit") == 0) {

        return true;
    }
    else if (strcmp(tokens[0], "getpath")==0) {
        getAndPrintCurrentPath();
        printf("hi567");
        return false;
    }

    else if (strcmp(tokens[0], "setpath")==0) {
        int err = setPath(tokens[1]);
        if (err < 0) {
            perror("path not found");
            return true;
        }
        else if (err == 0) {
            printf("hi123");
        }
        // printf("%s\n", getPath());
        return false;
    }
    else
    {
        execute(rows, tokens);
    }
    return false;
}

char* getPath() {
    char *path;
    path = getenv("PATH");
    return path;
}