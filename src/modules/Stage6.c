//*****************************
// Callums doing, on 28/02/2022.
//*****************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/functionDefinitions.h"

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

void saveHistory(char ** array){
    char * filename = ".hist_list";
    FILE* file;
    file = fopen(filename, "w+");
    int counter = 0;
    while (counter < 20 && array[counter] != NULL) {
        fprintf(file,"%d %s\n", counter, array[counter]);
        counter++;
    }
    fclose(file);
}

void loadHistory(){
    int HIST_LENGTH = 20;
    char * filename = ".hist_list";
    int MAX_CHARS = 512;
    char buffer[MAX_CHARS];
//    char ** list = malloc(sizeof(char*) * 20);

    FILE* file;
    file = fopen(filename, "r");
//    if (file == NULL){
//        return list;
//    }
    int i = 0;
    while(fgets(buffer, MAX_CHARS, file) != NULL) {
        char * command;
        command = strchr(buffer, ' ') + 1;
        if (command == NULL)
            continue;
//        char *newvalue = malloc(sizeof(char) * (strlen(command)));
//        strcpy(newvalue, command);
//        *(newvalue+strlen(newvalue)-1) = '\0';
//        history[i] = newvalue;
        addCommand(command);
        i++;
        if (i > HIST_LENGTH-1)
            break;
    }
    fclose(file);
}

int main() {
    for (int i = 0; i < 20; ++i) {
        addCommand("B");
    }
    saveHistory(history);
    loadHistory();
    for (int i = 0; i < 20; ++i) {
        printf("%d %s", i ,history[i]);
    }
    return 0;
}