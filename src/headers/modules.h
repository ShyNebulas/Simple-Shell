// --------------------------------------------------
// Header guards, do not remove!
#ifndef MODULES_H
#define MODULES_H
// --------------------------------------------------

// --------------------------------------------------
// userInput.c
bool getUserInput(char * buffer, int size);
int tokenize(char * buffer, int rows,  char *tokens[rows]);
void execute(int rows, char *tokens[rows]);
// --------------------------------------------------
// checkCommands.c
bool checkTokensForCommands(int size, int rows, char *tokens[rows]);
// --------------------------------------------------

#endif
