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
    }
}

char * getMostRecentCommand() {
    return history[lastIndex - 1];
}

char *getCommandByIndex (int n) {

    if(history[n - 1] == NULL) {

        return NULL;

    }

    char * temp = malloc(sizeof(char) * strlen(history[n - 1]));
    strcpy(temp, history[n - 1]);
    return temp;
}

void displayHistory() {
    if(lastIndex == 0) {
        perror("History has no commands yet, execute some commands first.");
    }
    for(int i = 0; i < HISTORY_SIZE; i++) {
        if(history[i]) {
            printf("[History] %d: %s", i + 1, history[i]);
        }
    }
}

void saveHistory() {

    char * filename = ".hist_list";
    FILE * file = fopen(filename, "w");

    int index = 0;

    for(int i = 0; i < HISTORY_SIZE; i++) {

        if(history[index]) {

            fprintf(file, "%d %s", index, history[index]);

        }

        index++;

    }

    fclose(file);

}


int loadHistory() {

    FILE * file = fopen(".hist_list", "r");
    char * buffer = malloc(512);

    if(!file) {
        fopen(".hist_list", "w");
        return 0;
    }

    while(fgets(buffer, 512, file)!= NULL) {
        char *command = strchr(buffer, ' ') + 1;
        addCommand(command);
    }
    fclose(file);
    free(buffer);
    return 1;
}

