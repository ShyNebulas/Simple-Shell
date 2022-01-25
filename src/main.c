#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

    bool quit = false;

    // Standard Input buffer for gets()
    char buffer[512];

    do {

        // Shell character
        printf("£ ");

        // Gets a full line from the shell, and if ctrl-d (EOF) is pressed then it exits
        if(gets(buffer) == 0) {

            quit = true;

        }

        int BufferLength = sizeof buffer / sizeof * buffer;

        // If buffer overflow?
        if(BufferLength > 512) {

            printf("Buffer overflow! 512 characters is the limit");

            exit(0);

        }

        // Gets the first token from the buffer
        char * token = strtok(buffer, " ");

        // Stops when token is NULL
        while(token) {

            // If token is not NULL
            if(token) {

                // Compare token to "exit", if 0
                if((strcmp(token, "exit") == 0)) {

                    quit = true;

                }
                
            }

            // Displays each token
            printf("\"%s\"\n", token);

            // Next token
            token = strtok(NULL, " ");

        }

    } while(!quit);
   
    return 0;

}