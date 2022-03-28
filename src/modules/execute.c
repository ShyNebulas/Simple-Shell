#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

#include "../../dep/headers/functionDefinitions.h"

// --------------------------------------------------
// Function which forks itself and attempts to execute a system call, 
// rows = token's rows
// tokens = string array that stores tokens
// --------------------------------------------------
void execute(int rows, char *tokens[rows]) {

    int error = 0;
    pid_t pid = fork();

    // Child process
    if(pid == 0) {

        if(execvp(tokens[0], tokens) < 0) {

            perror("\n[Error] Could not execute command");

        }

        exit(0);

    }
        
    else if(pid < 0) {

        perror("[Error] Fork child process Failed\n");

        error = -1;

    } 
        
    else {

        // Parent process
        // Parent will wait for the child to complete
        int returnStatus;

        // Parent process waits here for child to terminate
        waitpid(pid, &returnStatus, 0);  

        // Verify child process terminated without error
        if (returnStatus == 0 || returnStatus == 1) {  
    
            printf("\n");

        }

    }

    if(error == -1) {

        perror("[Error] Command not found\n");

    }

}

