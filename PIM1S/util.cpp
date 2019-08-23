#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>

#include "util.h"

void centerText(char* text, int fieldWidth) {
	int padlen = (fieldWidth - strlen(text)) / 2;
	printf("% *s % s % *s\n", padlen, "", text, padlen, "");
}

void topLines()
{
	for (i = 0; i < cmd_dimension.columns; i++) {
		red();
		printf("_");
		yellow();
		printf("_");
		reset();
	}
}

void bottomLines()
{
	for (i = 0; i < cmd_dimension.columns; i++) {
		yellow();
		printf("_");
		red();
		printf("_");
		reset();
	}
}
