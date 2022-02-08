#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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
    else
    {
        execute(rows, tokens);
    }
    return false;
}
