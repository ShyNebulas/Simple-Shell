#include <stdbool.h>
#include <string.h>

#include "../headers/helpers.h"
#include "../headers/modules.h"

bool checkTokensForCommands(int size, int rows, int columns, char tokens[rows][columns]) {

    if(strcmp(tokens[0], "exit") == 0) {

        return true;

    }

    return false; 

}