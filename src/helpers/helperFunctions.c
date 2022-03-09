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
// Function which returns the enviromental PATH,
// --------------------------------------------------
char* getPath() {

    char *path;

    path = getenv("PATH");

    return getenv("PATH");

}




