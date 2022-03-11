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

    if(sizeOfStringArray() == 0) {

        return true;

    }

    return false;

}

void deleteEarliestCommand() {
    history[0] = NULL;
    free(history[0]);

    for(int i = 1; i < sizeOfStringArray(); i++) {

        history[i - 1] = history[i];

    }
    history[sizeOfStringArray()-1] = NULL;
}

void addCommand(char *command) {

    if(isFull()) {

        deleteEarliestCommand();
        char *comm = malloc(sizeof(char) * (strlen(command)));
        strcpy(comm,command);
        history[19] = comm;
    }

    else {
            char *comm = malloc(sizeof(char) * (strlen(command)));
            strcpy(comm, command);
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

void saveHistory(){
    char * filename = ".hist_list";
    FILE* file;
    file = fopen(filename, "w+");
    int counter = 0;
    while (counter < HISTORY_SIZE && history[counter] != NULL) {
        fprintf(file,"%d %s\n", counter, history[counter]);
        counter++;
    }
    fclose(file);
}



void loadHistory(){
    char * filename = ".hist_list";
    int MAX_CHARS = 512;
    char buffer[MAX_CHARS];

    FILE* file;
    file = fopen(filename, "r");
    int i = 0;
    while(fgets(buffer, MAX_CHARS, file) != NULL) {
        char * command;
        command = strchr(buffer, ' ') + 1;
        if (command == NULL)
            continue;

        addCommand(command);
        i++;
        if (i > HISTORY_SIZE-1)
            break;
    }
    fclose(file);
}

