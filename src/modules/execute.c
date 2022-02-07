//
// Created by syeda shah on 07/02/2022.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include  <sys/wait.h>

#include "../headers/helpers.h"
#include "../headers/modules.h"

void execute(int rows, int columns, char tokens[rows][columns])
{
    int err = 0;

    pid_t pid;

    pid=fork();

    if(pid<0)
    {
        fprintf(stderr,"Fork child process Failed");
        err=-1;
    }
    else if(pid == 0) //child process
    {
        if (execvp(tokens[0][0], tokens) < 0) {
            printf("\nCould not execute command..");
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
        printf("child complete");
    }

    if(err==-1){
        printf("Error Command not found.");
    }


}
