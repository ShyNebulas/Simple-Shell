#ifndef CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
#define CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H

// --------------------------------------------------
// helperFunctions.c
int sizeOfCharArray(char * array);
void clearInputBuffer();
bool checkTokensForCommands(int rows, char *tokens[]);
char* getPath();

// --------------------------------------------------
// userInput.c
bool getUserInput(char * buffer, int size);
int tokenize(char * buffer, int rows,  char *tokens[]);

// --------------------------------------------------
// execute.c
void execute(int rows, char *tokens[]);

// --------------------------------------------------
// cd.c
int changeDir(char *newDir);
int setPath(char *newPath);

#endif //CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
