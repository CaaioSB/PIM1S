#include "cmd_resolution.h"

#define CLEAR_SCREEN_PROGRAM "cls"

extern void centerText(char *text, int fieldWidth);

extern void topLines();

extern void bottomLines();

extern FILE* AbreArquivo(char modo, char caminho[30]);

extern void FecharArquivo(FILE *arquivoo);

extern void SetSleep(float s);