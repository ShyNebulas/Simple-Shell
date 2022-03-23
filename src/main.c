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
    loadAliases();

    do {
        printf("£ ");

        if(getUserInput(buffer, BUFFER_SIZE)) {

            printf("\n");

            break;

        }
        if((checkForHistoryInvocation(buffer)==1)) {
            addCommand(buffer);
        }

        tokenize(buffer);

        if(checkIfUserIsSettingAlias()==0){
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
