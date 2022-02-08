#include <stdbool.h>
#include <string.h>

#include "../headers/helpers.h"
#include "../headers/modules.h"

bool checkTokensForCommands(int size, int rows, char *tokens[rows]) {
    if(strcmp(tokens[0], "exit") == 0) {

        return true;
    }
    else
    {
        execute(rows, tokens);
    }
    return false;
}
