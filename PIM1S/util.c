#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>
#include <time.h>

#include "util.h"
#include "cmd_resolution.h"
#include <stdbool.h>

i = 0;

// FUN��ES PARA ALTERAR AS CORES

void centerText(char* text, int fieldWidth) {
	int padlen = (fieldWidth - strlen(text)) / 2;
	printf("% *s % s % *s\n", padlen, "", text, padlen, "");
}

//void topLines()
//{
//	for (i = 0; i < cmd_dimension.columns; i++) {
//		printf(RED "_" WHITE );2
//		printf(YELLOW "_" WHITE );
//	}
//}

//void bottomLines()
//{
//	for (i = 0; i < cmd_dimension.columns; i++) {
//		printf(YELLOW "_" WHITE);
//		printf(RED "_" WHITE);
//	}
//}

FILE* arquivo = NULL;
FILE* AbreArquivo(char modo, char caminho[30]) {
	switch (modo) {
	case 'g':
		arquivo = fopen(caminho, "wt");
		break;
	case 'l':
		arquivo = fopen(caminho, "rt");
		break;
	case 'a':
		arquivo = fopen(caminho, "a");
		break;
	case 'r':
		arquivo = fopen(caminho, "r");
		break;
	}
	if (arquivo == NULL) {
		printf("N�o foi possivel abrir o arquivo");
		exit(0);
	}
	return arquivo;
}

void FecharArquivo(FILE* arquivo) {
	fclose(arquivo);
}