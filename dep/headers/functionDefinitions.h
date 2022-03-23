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
void checkAndReplaceAliases();
int checkIfUserIsSettingAlias();
int checkForHistoryInvocation(char *buffer);

// --------------------------------------------------
// execute.c
void execute(int rows, char *tokens[]);

// --------------------------------------------------
// cd.c
int changeDir(char *newDir);
int setPath(char *newPath);

//---------------------------------------------------
int sizeOfStringArray();
int isFull();
void deleteEarliestCommand();
void addCommand(char *command);
void displayHistory();
char *getMostRecentCommand();
char *getCommandByIndex (int n);
int loadHistory();
void saveHistory();

//----------------------------------------------------
typedef struct ALIAS {
    char *name;
    char *command;
} alias;
int getNextIndex();
int checkIfAliasesFull();
int checkHowManyAliases();
int checkIfAliasExists(char *name);
int createAlias(char *name, char *command);
int unAlias(char *name);
char *getAliasCommand(char *name);
void printAliases();
int saveAliases();
int loadAliases();
#endif //CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H

