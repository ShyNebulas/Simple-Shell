#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../dep/headers/functionDefinitions.h"

#define BUFFER_SIZE 512



int main() {

    bool quit = false;
    char buffer[BUFFER_SIZE];
    char *path = getPath();

    changeDir(getenv("HOME"));
    loadAliases();
    loadHistory();

    do {
        printf("£ ");

        if(getUserInput(buffer, BUFFER_SIZE)) {

            printf("\n");

            break;

        }
        if((checkForHistoryInvocation(buffer)==1)) {

            char * temp = malloc(sizeof(char) * strlen(buffer));
            strcpy(temp, buffer);
            addCommand(temp);
        }

        tokenize(buffer);

        if(checkIfUserIsAliasing()==0){
            checkAndReplaceAliases();
        }

        quit = checkTokensForCommands();

    } while (!quit);

    changeDir(getenv("HOME"));
    setPath(path);
    saveAliases();
    saveHistory();
    printf("%s\n", getPath());
    return 0;
}

