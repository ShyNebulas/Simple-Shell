#ifndef CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
#define CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
#include <stdbool.h>
// --------------------------------------------------
// helperFunctions.c
int sizeOfCharArray(char * array);
void clearInputBuffer();
bool checkTokensForCommands();
char* getPath();

// --------------------------------------------------
// userInput.c
bool getUserInput(char * buffer, int size);
int tokenize(char * buffer);

// --------------------------------------------------
// execute.c
void execute(int rows, char *tokens[]);

// --------------------------------------------------
// cd.c
int changeDir(char *newDir);
int setPath(char *newPath);

//---------------------------------------------------
int sizeOfStringArray();
bool isFull();
bool isEmpty();
void deleteEarliestCommand();
void addCommand(char *command);
void displayHistory();
char * getMostRecentCommand();
char *getCommandByIndex (int n);
int checkForHistoryInvocation();
#endif //CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
