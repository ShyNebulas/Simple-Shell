#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "../headers/functionDefinitions.h"

#define BUFFER_SIZE 512
#define TOKENS_ROWS 100
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
        printf("Buffer overflow! 512 characters is the limit\n");
        // Clean up whatever fgets() has left behind
        clearInputBuffer();
    }

    return false;
}
// --------------------------------------------------
// Function splits a buffer into tokens based on white space and
// returns the number of tokens created,
// buffer = char array to store user input
// rows = token's rows
// columns = token's columns
// tokens = string array to stores tokens
// --------------------------------------------------
int tokenize(char * buffer, int rows, char* tokens[rows]) {
    char Delimit[] = "  \t \n ; & > < \r |";
    tokens[0] = strtok(buffer, Delimit);
    int counter = 0;
    // Stops when token is NULL
    while(tokens[counter]) {
        counter++;
        tokens[counter]= strtok(NULL, Delimit);

    }
    tokens[counter] = NULL;
    return counter;
}

int stage1Loop() {

    bool quit = false;
// Standard Input buffer for gets()

    char buffer[BUFFER_SIZE];
    char *tokens[TOKENS_ROWS];
    char *path = getPath();
    changeDir(getenv("HOME"));

    do {
// Shell character
        printf("£ ");
// quits program if EOF (ctrl-D) detected
        if (getUserInput(buffer, BUFFER_SIZE)) {
// We always need to print a newline when quitting as some shells try to add a trailing \n
            printf("\n");
            break;
        }
// Stores tokens in tokens and returns the amount of tokens
        tokenize(buffer, TOKENS_ROWS, tokens);

        quit = checkTokensForCommands(TOKENS_ROWS, tokens);

    } while (!quit);

    setPath(path);
    printf("%s\n", getPath());
    return 0;
}
