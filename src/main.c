#include <stdio.h>
#include <stdbool.h>

#include "../dep/headers/functionDefinitions.h"

#define BUFFER_SIZE 512
#define TOKENS_ROWS 100

int main() {

    bool quit = false;

    char buffer[BUFFER_SIZE];
    char *tokens[TOKENS_ROWS];
    char *path = getPath();

    changeDir(getenv("HOME"));

    do {

        printf("£ ");

        if (getUserInput(buffer, BUFFER_SIZE)) {

            printf("\n");

            break;

        }

        tokenize(buffer, TOKENS_ROWS, tokens);

        quit = checkTokensForCommands(TOKENS_ROWS, tokens);

    } while (!quit);

    setPath(path);
    
    printf("%s\n", getPath());

    return 0;

}

