//
// Created by Ayushi Badiyani on 2/28/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../dep/headers/functionDefinitions.h"

#define HISTORY_SIZE 20
char *history[HISTORY_SIZE];

int sizeOfStringArray() {

    int size = 0;

    for(; history[size] != NULL; size++);

    return size;

}

bool isFull() {

    if(sizeOfStringArray() == HISTORY_SIZE) {

        return true;

    }

    return false;

}

bool isEmpty() {

    if(sizeOfStringArray(HISTORY_SIZE) == 0) {

        return true;

    }

    return false;

}

void deleteEarliestCommand() {
    free(history[0]);

    for(int i = 1; i < sizeOfStringArray(); i++) {

        history[i - 1] = history[i];

    }

    history[sizeOfStringArray() - 1] = NULL;

}

void addCommand(char *command) {

    if(isFull()) {

        deleteEarliestCommand();
        char *comm = malloc(sizeof(command));
        strcpy(comm,command);
        history[19] = comm;
    }

    else {
        char *comm =  malloc(sizeof (command));
        strcpy(comm,command);
        history[sizeOfStringArray()] = comm;
    }

}

char * getMostRecentCommand() {

    return history[sizeOfStringArray() - 1];

}

char *getCommandByIndex (int n) {
    return history[n-1];
}

void displayHistory() {

    for(int i = 0; i < HISTORY_SIZE; i++) {

        if(history[i] != NULL) {

            printf("%d: %s\n", i + 1, history[i]);

        }

    }

}





