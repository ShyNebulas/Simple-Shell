#include <stdio.h>
#include <stdbool.h>

#include "headers/functionDefinitions.h"

int main() {
    stage1Loop();

    return 0;
}

// we need ask about exit, does not work right after an error message
// we need to ask about enter, gives segfault after adding stage 3 and 4
