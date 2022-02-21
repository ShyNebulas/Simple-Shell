//
// Created by Ayushi Badiyani on 2/8/22.
//

#ifndef CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
#define CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
#include <stdbool.h>
int sizeOfCharArray(char * array);
// --------------------------------------------------
// input.c
void clearInputBuffer();
// --------------------------------------------------
// checkCommands.c
bool checkTokensForCommands(int rows, char *tokens[rows]);
// --------------------------------------------------
bool getUserInput(char * buffer, int size);
int tokenize(char * buffer, int rows,  char *tokens[rows]);
int stage1Loop();
void execute(int rows, char *tokens[rows]);
// --------------------------------------------------
char *getPath();
int changeDir(char *newDir);
int setPath(char *newPath);
void giveErr(char *errorMessage);

#endif //CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
