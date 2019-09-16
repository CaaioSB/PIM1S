#include "cmd_resolution.h"

#define CLEAR_SCREEN_PROGRAM "cls"

#define RESET   "\033[1;0m"
#define BLACK   "\033[1;30m"      /* Black */
#define RED     "\033[1;31m"      /* Red */
#define GREEN   "\033[1;32m"      /* Green */
#define YELLOW  "\033[1;33m"      /* Yellow */
#define BLUE    "\033[1;34m"      /* Blue */
#define MAGENTA "\033[1;35m"      /* Magenta */
#define CYAN    "\033[1;36m"      /* Cyan */
#define WHITE   "\033[1;37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

extern void centerText(char *text, int fieldWidth);

extern FILE* AbreArquivo(char modo, char caminho[30]);

extern void FecharArquivo(FILE *arquivoo);

char* replaceWord(const char* s, const char* oldW, const char* newW);