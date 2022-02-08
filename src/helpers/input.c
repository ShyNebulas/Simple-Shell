#include <stdio.h>

#include "../headers/helpers.h"

// --------------------------------------------------
// Function which clears the input buffer, 
// i.e. anything that fgets() leaves behind
// --------------------------------------------------
void clearInputBuffer() {

    while((getchar()) != '\n');
     
}
