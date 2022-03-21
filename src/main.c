#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../dep/headers/functionDefinitions.h"

#define BUFFER_SIZE 512



int main() {

    bool quit = false;
    char buffer[BUFFER_SIZE];
    char *path = getPath();
    changeDir(getenv("HOME"));

    loadHistory();

    do {

        printf("£ ");

        if(getUserInput(buffer, BUFFER_SIZE)) {

            printf("\n");

            break;

        }

        if (!(checkForHistoryInvocation(buffer)==1)) {
            addCommand(buffer);
        }

        tokenize(buffer);
        checkAndReplaceAliases();

        quit = checkTokensForCommands();

    } while (!quit);
    
    setPath(path);
    changeDir(getenv("HOME"));
    printf("%s\n", getPath());
    saveHistory();
    return 0;
}
