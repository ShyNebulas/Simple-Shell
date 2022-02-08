#include <stdio.h>
#include <string.h>

#include "../headers/helpers.h"

// --------------------------------------------------
// Function which returns the size of a char array, 
// e.g. ['a', 'b', 'c'] returns 3
// --------------------------------------------------
int sizeOfCharArray(char * array) {

    int size = 0; 

    for(; array[size] != '\0'; size++);

    return size;

}
