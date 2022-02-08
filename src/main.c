#include <stdio.h>
#include <stdbool.h>

#include "headers/helpers.h"
#include "headers/modules.h"

#define BUFFER_SIZE 512
#define TOKENS_ROWS 100

int main() {

    bool quit = false;
    // Standard Input buffer for gets()
    char buffer[BUFFER_SIZE];
    char *tokens[TOKENS_ROWS];
    do {
        // Shell character
        printf("£ ");
        // quits program if EOF (ctrl-D) detected
        if(getUserInput(buffer, BUFFER_SIZE)) {
            // We always need to print a newline when quitting as some shells try to add a trailing \n
            printf("\n");
            break;
        }
        // Stores tokens in tokens and returns the amount of tokens
        int size = tokenize(buffer, TOKENS_ROWS, tokens);

//        for(int index = 0; index < size; index++) {
//            printf("\"%s\"\n", tokens[index]);
//        }
//       printf("%s\n", buffer);

        quit = checkTokensForCommands(size, TOKENS_ROWS, tokens);
        // Printing each token
    } while(!quit);
    return 0;
}
