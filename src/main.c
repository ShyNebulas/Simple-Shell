#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../dep/headers/functionDefinitions.h"

#define BUFFER_SIZE 512



int main() {

    bool quit = false;
    char buffer[BUFFER_SIZE];
    char *path = getPath();

    loadHistory();

    changeDir(getenv("HOME"));

    do {

        printf("£ ");

        if(getUserInput(buffer, BUFFER_SIZE)) {

            printf("\n");

            break;

        }
        tokenize(buffer);

        if (!(checkForHistoryInvocation()==1)) {
            addCommand(buffer);
        }

        quit = checkTokensForCommands();

    } while (!quit);


    setPath(path);
    printf("%s\n", getPath());
    saveHistory();

    return 0;

}
