#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

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
    if (tokens[0] == NULL) {
        return false;

    }
    else if (strcmp(tokens[0], "exit") == 0) {

        return true;

    }
    else if (strcmp(tokens[0], "history") == 0) {

        displayHistory();
        return false;

    }
    else if (strcmp(tokens[0], "alias") == 0) {
        if (tokens[1] == NULL) {
            printAliases();
            return false;
        } else if (tokens[2] == NULL) {
            perror("[Error] Please give the command for the alias, alias takes two parameters <name> <command>");
            return false;
        } else {
            int counter = 2;
            char *comm = malloc(512);
            comm[0] = '\0';
            while (tokens[counter] != NULL) {
                strcat(comm, tokens[counter]);
                strcat(comm, " ");
                counter++;
            }
            char *name = malloc(512);
            strcpy(name,tokens[1]);
            createAlias(name, comm);
    }
        return false;
 }

    else if(strcmp(tokens[0],"unalias")==0) {
        if (tokens[1] == NULL) {
            perror("[Error] unalias requires the name of the alias you want to delete");
            return false;
        }
        else if (tokens[2] != NULL) {
            perror("[Error] unalias only takes one parameter, <name> of alias to delete");
            return false;
        }
        else {
            unAlias(tokens[1]);
            return false;
        }
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

        if (tokens[1] == NULL) {

            perror("[Error] No parameters provided");

            return false;

        }
        else if (tokens[2] == NULL) {

            int err = setPath(tokens[1]);

            if (err < 0) {

                perror("[Error] Could not execute command");
                return false;

            } else if (err == 0) {

                return false;

            }

        }
        else {
            perror("[Error] Setpath only takes 1 parameter, try again with a single path and no spaces.");
        }
    }

    else if(strcmp(tokens[0], "cd") == 0) {

        if (tokens[1] == NULL) {

            changeDir(getenv("HOME"));

            return false;

        }
        else if(tokens[2] != NULL) {
            perror("The command <cd> takes only 1 parameter, the <path> you want to cd into separated by / ");
            return false;
        }

        else {

            int err = changeDir(tokens[1]);

            return false;

        }

    }

    else if (strcspn(tokens[0],"!") == 0){

        if(tokens[1] != NULL) {
            perror("[Error] History invocations don't take parameters, try again with !<number>");
        }

        if(strlen(tokens[0]) == 1) {

            perror("History invocation requires a number\n");

            return false;

        }

        char subString[sizeOfCharArray(tokens[0])];

        memset(subString, '\0', sizeof(subString));
        strncpy(subString, tokens[0], sizeof(subString));

        if(isalpha(subString[1])) {

            perror("No letters allowed\n");

            return false;

        }

        int historyNum;

        sscanf(subString + 1,"%d\n",&historyNum);

        if(getMostRecentCommand() == NULL) {
            perror("No commands have been stored in History yet.\n");
            return false;
        }

        char *toExecuteAgain;

        if(subString[0] == '!' && subString[1] == '!') {

            toExecuteAgain = malloc(sizeof(char) * strlen(getMostRecentCommand()) + 1);
            strcpy(toExecuteAgain, getMostRecentCommand());
            tokenize(toExecuteAgain);
            checkAndReplaceAliases();
            return checkTokensForCommands();

        }

        else if (historyNum >=1 && historyNum <=20 ) {

            toExecuteAgain = malloc(sizeof(char) * strlen(getCommandByIndex(historyNum)) + 1);

            strcpy(toExecuteAgain, getCommandByIndex(historyNum));

            if (toExecuteAgain == NULL) {
                perror("This number has no command in history\n");
                return false;
            }
            else {
                tokenize(toExecuteAgain);
                checkAndReplaceAliases();
                return checkTokensForCommands();
            }
        }
        else {
            perror("That is not a valid number, history stores the last 20 commands only.\n");
            return false;
        }

    }

    else {
        execute(TOKENS_ROWS, tokens);
    }
    return false;
}

int checkForHistoryInvocation(char* buffer) {
    char *temp = malloc (512);
    strcpy(temp,buffer);
    char delimiter[] = "  \t \n ; & > < \r |";
    char *toCheck = strtok(temp, delimiter);

    if(toCheck == NULL || strcmp(toCheck, "history")==0 || toCheck[0] == '!' ) {
        return 0;
    }
    else {
        return 1;
    }
}

 void checkAndReplaceAliases() {
    int counter=0;  // this counter is for the while loop that goes through the current tokens array one by one to check for aliases
    int currentNewIndex=0; // this is the next free position in the new tokens array
    char *newTokens[100];  // new tokens array after replacing aliases
    while (tokens[counter] != NULL) {
        char *checkForCommand = getAliasCommand(tokens[counter]);  //gets command by name
        char *command = malloc(sizeof (char) * 100);
        char *tokenizedCommand[20];
        if (checkForCommand != NULL) {
            strcpy(command,checkForCommand);
            tokenizedCommand[0] = strtok(command," ");
            // we tokenise the stored command because it is a string
            int i = 0;
            while(tokenizedCommand[i]) {
                i++;
                tokenizedCommand[i] = strtok(NULL, " ");
            }
            int j=0;  // go through the tokenised command and add them back to the new tokens array in place of the alias
            while(tokenizedCommand[j]!= NULL) {
                newTokens[currentNewIndex] = tokenizedCommand[j];
                j++;
                currentNewIndex++;
            }
        }
        else {  // if the word is not an alias we just add it to the new tokens array and update the index.
            newTokens[currentNewIndex] = tokens[counter];
            currentNewIndex++;
        }
        newTokens[currentNewIndex] = NULL;
        counter ++;
    }
    // now we just replace the tokens array with the new tokens array post alias replacement.
    int index = 0;
     while (newTokens[index] != NULL) {
         tokens[index] = newTokens[index];
         index++;
     }
     tokens[index] = NULL;
}

int checkIfUserIsAliasing() {
    if (tokens[0] == NULL || strcmp(tokens[0],"alias")==0 ||  strcmp(tokens[0], "unalias") == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

