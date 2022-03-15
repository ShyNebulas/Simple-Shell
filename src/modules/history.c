//
// Created by Ayushi Badiyani on 2/28/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../dep/headers/functionDefinitions.h"

#define HISTORY_SIZE 20
char *history[HISTORY_SIZE];
int lastIndex = 0;

int isFull() {
    return lastIndex == HISTORY_SIZE;
}

void deleteEarliestCommand() {
    free(history[0]);
    for(int i = 1; i < lastIndex + 1; i++) {
        history[i - 1] = history[i];
    }
    history[lastIndex] = NULL;
}

void addCommand(char *command) {
    if(isFull()) {
        deleteEarliestCommand();
        char *comm = malloc(sizeof(char) * (strlen(command)));
        strcpy(comm,command);
        history[HISTORY_SIZE - 1] = comm;
    }
    else {
        char *comm = malloc(sizeof(char) * (strlen(command)));
        strcpy(comm, command);
        history[lastIndex] = comm;
        lastIndex++;
        printf("[Index] %d\n", lastIndex);
    }
}

char * getMostRecentCommand() {
    return history[lastIndex];
}

char *getCommandByIndex (int n) {
    return history[n-1];
}

void displayHistory() {
    for(int i = 0; i < HISTORY_SIZE; i++) {
        if(history[i]) {
            printf("%d: %s", i + 1, history[i]);
        }
    }
}

void saveHistory() {

    char * filename = ".hist_list";
    FILE * file = fopen(filename, "w");

    int index = 0;

    for(int i = 0; i < HISTORY_SIZE; i++) {

        if(history[index]) {

            printf("[History] %d %s", index, history[index]);

            fprintf(file, "%d %s", index, history[index]);

        }

        index++;

    }

    fclose(file);

}

void loadHistory() {

    FILE * file = fopen(".hist_list", "r");
    char * buffer;

    if(!file) {

        fopen(".hist_list", "w");
        return;

    }

    while(fgets(buffer, 255, file)) {

        char * command = strchr(buffer, ' ') + 1;

        printf("[loadHistory] %s", command);

        addCommand(command);
        
    }

    fclose(file);

}




