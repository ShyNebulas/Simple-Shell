#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

            break;

        }

        // Check for empty string
        if(buffer[0] == '\n') {

            continue;

        }

        if (!checkForHistoryInvocation(buffer)) {
            addCommand(buffer);
        }

        tokenize(buffer);

        quit = checkTokensForCommands();

    } while (!quit);

    displayHistory();


    setPath(path);
    printf("%s\n", getPath());
    saveHistory();

    return 0;

}
