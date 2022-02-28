#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "../../dep/headers/functionDefinitions.h"

// --------------------------------------------------
// Function which reads input from the input buffer, 
// buffer = char array to store user input
// size = size of buffer
// --------------------------------------------------
bool getUserInput(char * buffer, int size) {

    if(fgets(buffer, size, stdin) == 0) {

        return true;

    }

    // If buffer overflow?
    if(sizeOfCharArray(buffer) == 511) {

        printf("[Error] Buffer overflow! 512 characters is the limit\n");

        // Clean up whatever fgets() has left behind
        clearInputBuffer();

    }

    return false;
}

// --------------------------------------------------
// Function splits a buffer into tokens based on white space and returns the number of tokens created,
// buffer = char array to store user input
// rows = token's rows
// tokens = string array to stores tokens
// --------------------------------------------------
int tokenize(char * buffer, int rows, char* tokens[rows]) {

    char delimiter[] = "  \t \n ; & > < \r |";

    tokens[0] = strtok(buffer, delimiter);

    int counter = 0;

    // Stops when token is NULL
    while(tokens[counter]) {

        counter++;
        tokens[counter]= strtok(NULL, delimiter);

    }

    tokens[counter] = NULL;

    return counter;

}
