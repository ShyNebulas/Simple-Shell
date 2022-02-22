//
// Created by syeda shah on 07/02/2022.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include  <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>

#include "../headers/functionDefinitions.h"

void execute(int rows, char *tokens[rows])
{
    int err = 0;

    pid_t pid;

    pid=fork();
        if (pid == 0) //child process
        {
            if (execvp(tokens[0], tokens) < 0) {
                perror("\nCould not execute command..");
            }
            exit(0);
            //gives the user option to specify the filename and
            // the program is searched in directories that are listed the current PATH environment variable.
        } else if (pid < 0) {
            perror("Fork child process Failed\n");
            err = -1;
        } else {
            //parent process
            //parent will wait for the child to complete
            int returnStatus;
            waitpid(pid, &returnStatus, 0);  // Parent process waits here for child to terminate.

            if (returnStatus == 0)  // Verify child process terminated without error.
            {
                printf("\n");
            }

            if (returnStatus == 1) {
                printf("\n");
            }
        }

        if (err == -1) {
            printf("Error Command not found.\n");
        }
}
