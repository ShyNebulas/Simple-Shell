#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "../../dep/headers/functionDefinitions.h"
#define TOKENS_ROWS 100
char *tokens[TOKENS_ROWS];
// --------------------------------------------------
// Function which reads input from the input buffer, 
// buffer = char array to store user input
// size = size of buffer
// --------------------------------------------------
bool getUserInput(char * buffer, int size) {

    if(fgets(buffer, size, stdin) == 0) {

        return true;

    }

    // If buffer overflow?
    if(sizeOfCharArray(buffer) == 511) {

        printf("[Error] Buffer overflow! 512 characters is the limit\n");

        // Clean up whatever fgets() has left behind
        clearInputBuffer();

    }

    return false;
}

// --------------------------------------------------
// Function splits a buffer into tokens based on white space and returns the number of tokens created,
// buffer = char array to store user input
// rows = token's rows
// tokens = string array to stores tokens
// --------------------------------------------------
int tokenize(char * buffer) {

    char delimiter[] = "  \t \n ; & > < \r |";

    tokens[0] = strtok(buffer, delimiter);

    int counter = 0;

    // Stops when token is NULL
    while(tokens[counter]) {

        counter++;
        tokens[counter]= strtok(NULL, delimiter);

    }

    tokens[counter] = NULL;

    return counter;

}

// --------------------------------------------------
// Function which maps a commands name to its command,
// rows = array's rows
// tokens = array of strings
// --------------------------------------------------

bool checkTokensForCommands() {

    // If empty string exists
    if(tokens[0] == NULL) {

        return false;

    }

    else if(strcmp(tokens[0], "exit") == 0) {

        return true;

    }

    else if(strcmp(tokens[0], "getpath")== 0) {

        if(tokens[1] == NULL) {

            printf("%s %s", getPath(), "\n");
            return false;

        }

        else {

            perror("[Error] Getpath does not take parameters");
            return false;

        }

        return false;

    }

    else if(strcmp(tokens[0], "setpath")== 0) {

        if(tokens[1] == NULL) {

            perror("[Error] No parameters provided");

            return false;

        }

        int err = setPath(tokens[1]);

        if(err < 0){

            perror("[Error] Could not execute command");
            return false;

        }

        else if(err == 0) {

            return false;

        }

    }

    else if(strcmp(tokens[0], "cd") == 0) {

        if (tokens[1] == NULL) {

            changeDir(getenv("HOME"));

            return false;

        }

        else {

            int err = changeDir(tokens[1]);

            return false;

        }

    }

    else if (strcspn(tokens[0],"!") == 0){

        char subString [2];
        strncpy(subString, tokens[0]+1, sizeof(subString));
        int historyNum = sscanf(subString,"!-%d",&historyNum);

        char *toExecuteAgain;

        if (strcspn(subString,"!") == 0) {

             toExecuteAgain= getMostRecentCommand();
             if(toExecuteAgain == NULL) {
                 perror("No commands have been stored in History yet.");
                 return false;
             }
             else {
                 tokenize(toExecuteAgain);
                 checkTokensForCommands();
                 return false;
             }
        }

        else if (historyNum >=1 && historyNum <=20 ) {
            toExecuteAgain = getCommandByIndex(historyNum);
            if (toExecuteAgain == NULL) {
                perror("This number has no command in history");
            }
            else {
                tokenize(toExecuteAgain);
                checkTokensForCommands();
                return false;
            }
        }
        else {
            perror("That is not a valid number, history stores the last 20 commands only.");
            return false;
        }

    }

    else {

        execute(TOKENS_ROWS, tokens);

    }

    return false;

}

int checkForHistoryInvocation() {
    if (strcspn(tokens[0],"!")) {
        return 1;

    }
    else {
        return 0;
    }
}
