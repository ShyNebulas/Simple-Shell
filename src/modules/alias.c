
//
// Created by Ayushi Badiyani on 3/14/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../dep/headers/functionDefinitions.h"
#define ALIAS_LIMIT 10
alias AliasArray[ALIAS_LIMIT];

int getNextIndex() {
    int count=0;
    while(AliasArray[count].name !=NULL){
        count++;
    }
    return count;
}

int checkIfAliasesFull() {
    int counter = 0;
    while(AliasArray[counter].name != NULL)    {
        counter++;
    }
    if(counter==ALIAS_LIMIT) {
        return 0;
    }
    else {
        return -1;
    }
}

int checkHowManyAliases() {
    int counter = 0;
    for (int i =0; i<10; i++) {
        if(AliasArray[i].name != NULL) {
            counter ++;
        }
    }
    return counter;
}

int checkIfAliasExists(char *name) {
    //this function returns the index of the alias if it exists, or -1 if it does not
    if(checkHowManyAliases()!=0) {
        for (int i = 0; i < ALIAS_LIMIT; i++) {
            if (AliasArray[i].name != NULL) {
                if (strcmp(AliasArray[i].name, name) == 0) {
                    return i;
                }
            }
        }
    }
    return -1;
}


int createAlias(char *name, char *command) {
    int dupeAliasIndex = checkIfAliasExists(name);
    if(dupeAliasIndex!=-1) {
        if (strcmp(AliasArray[dupeAliasIndex].name,name)==0) {
            char *comm = malloc(512);
            strcpy(comm,command);
            AliasArray[dupeAliasIndex].command = comm;
            printf("%s %s\n","This alias name already exists, the command has been overwritten to -> ",AliasArray[dupeAliasIndex].command);
        }
        return 0;
    }
    else if (checkIfAliasesFull()==0) {
        perror("No more aliases can be set, delete some.");
        return -1;
    }
    else {
        alias *newAlias = malloc(sizeof *newAlias);
        char *comm = malloc(512);
        strcpy(comm,command);
        char *tempName = malloc(512);
        strcpy(tempName,name);
        newAlias->command = comm;
        newAlias->name= tempName;
        AliasArray[getNextIndex()] = *newAlias;
        return 0;
    }
}

int unAlias(char *name) {
    int toDeleteIndex =  checkIfAliasExists(name);
    if (toDeleteIndex == -1) {
        perror("Alias does not exist cannot delete, use the name of the alias you would like to delete");
        return -1;
    }
    else {
        alias *todelete = &AliasArray[toDeleteIndex];
        todelete->name = NULL;
        todelete->command = NULL;
        todelete = NULL;
        free(todelete);
        return 0;
    }
}

char *getAliasCommand(char *name) {
    int ind = checkIfAliasExists(name);
    if (ind == -1) {
        return NULL;
    }
    else {
        return AliasArray[ind].command;
    }
}


void printAliases() {
    if(checkHowManyAliases()==0) {
        printf("No aliases set yet,aliases empty! Add some by typing 'alias' <name> <command>\n");
    }
    else {
        for (int i = 0; i < ALIAS_LIMIT; i++) {
            if (AliasArray[i].name != NULL) {
                printf("%s %s\n", AliasArray[i].name, AliasArray[i].command);
            }
        }
    }
}

int saveAliases() {
    char *filename = ".aliases";
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "\nError opening aliases file\n");
        return 0;
    }
    else {
        for (int i =0; i<ALIAS_LIMIT; i++) {
            if (AliasArray[i].name != NULL) {
               fprintf(file, "%s %s\n", AliasArray[i].name,AliasArray[i].command);
            }
        }
        fclose(file);
        return 1;
    }
}


int loadAliases() {
    FILE *file = fopen(".aliases", "r");
    char *buffer = malloc(512);
    if (!file) {
        fopen(".aliases", "w");
        return 0;
    }
    while (fgets(buffer, 512, file) != NULL) {
        char delimiter[] = "  \t \n ; & > < \r |";
        char *command = malloc(512);
        command[0] = '\0';
        char *name = strtok(buffer, delimiter);
        char *comm = strtok(NULL, delimiter);

        while(comm!=NULL) {
            strcat(command, comm);
            strcat(command, " ");
            comm = strtok(NULL,delimiter);
        }
            createAlias(name, command);
    }
    fclose(file);
    free(buffer);
    return 1;
}

