//
// Created by syeda shah on 07/02/2022.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include  <sys/wait.h>
#include <stdbool.h>

#include "../headers/functionDefinitions.h"

void execute(int rows, char *tokens[rows])
{
    int err = 0;

    pid_t pid;

    pid=fork();

    if(pid<0)
    {
        fprintf(stderr,"Fork child process Failed\n");
        err=-1;
    }
    else if(pid == 0) //child process
    {
      //  printf("we're here\n");

        if (execvp(tokens[0], tokens) < 0) {
            perror("\nCould not execute command..");
        }

       // err = execvp(tokenss[0], tokenss);
        //gives the user option to specify the filename and
        // the program is searched in directories that are listed the current PATH environment variable.
    }
    else
    {
        //parent process
        //parent will wait for the child to complete
        wait(NULL);

    }

    if(err==-1){
        printf("Error Command not found.\n");
    }
}
