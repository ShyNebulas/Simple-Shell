#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../headers/helpers.h"
#include "../headers/modules.h"

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

        printf("Buffer overflow! 512 characters is the limit\n");

        // Clean up whatever fgets() has left behind
        clearInputBuffer();

    }

    buffer[strcspn(buffer, "\r\n")] = 0;

    return false; 

}

// --------------------------------------------------
// Function splits a buffer into tokens based on white space and
// returns the number of tokens created,
// buffer = char array to store user input
// rows = token's rows
// columns = token's columns
// tokens = string array to stores tokens
// --------------------------------------------------
int tokenize(char * buffer, int rows, int columns, char tokens[rows][columns]) {

    char * token = strtok(buffer, " ");

    int counter = 0;  

    // Stops when token is NULL
    while(token) {

        // If token is not NULL
        if(token) {

            strcpy(tokens[counter], token);

            counter++;
                
        }

        // Next token
        token = strtok(NULL, " ");

    }

    return counter; 

}

