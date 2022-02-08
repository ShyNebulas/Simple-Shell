//
// Created by Ayushi Badiyani on 2/8/22.
//

#ifndef CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
#define CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H

int sizeOfCharArray(char * array);
// --------------------------------------------------
// input.c
void clearInputBuffer();
// --------------------------------------------------
bool getUserInput(char * buffer, int size);
int tokenize(char * buffer, int rows,  char *tokens[rows]);
void execute(int rows, char *tokens[rows]);
// --------------------------------------------------
// checkCommands.c
bool checkTokensForCommands(int rows, char *tokens[rows]);
// --------------------------------------------------
int stage1Loop();

#endif //CS210_GROUP_3_SHELL2_FUNCTIONDEFINITIONS_H
