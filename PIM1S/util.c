#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>
#include <time.h>

#include "util.h"
#include "cmd_resolution.h"

int i = 0;

// FUNÇÕES PARA ALTERAR AS CORES
static void red() {
	printf("\033[1;31m");
}

static void yellow() {
	printf("\033[1;33m");
}

static void reset() {
	printf("\033[0m");
}

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

FILE *arquivo = NULL;
FILE *AbreArquivo(char modo, char caminho[30]) {
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
	}
	if (arquivo == NULL) {
		printf("Não foi possivel abrir o arquivo");
		exit(0);
	}
	return arquivo;
}

void FecharArquivo(FILE* arquivo) {
	fclose(arquivo);
}