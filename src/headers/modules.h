// --------------------------------------------------
// Header guards, do not remove!
#ifndef MODULES_H
#define MODULES_H
// --------------------------------------------------

// --------------------------------------------------
// userInput.c
bool getUserInput(char * buffer, int size);
int tokenize(char * buffer, int rows, int columns, char tokens[rows][columns]);
// --------------------------------------------------
// checkCommands.c
bool checkTokensForCommands(int size, int rows, int columns, char tokens[rows][columns]);
// --------------------------------------------------

#endif
