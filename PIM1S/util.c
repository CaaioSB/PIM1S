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

// FUNÇÕES PARA ALTERAR AS CORES

void centerText(char* text, int fieldWidth) {
	int padlen = (fieldWidth - strlen(text)) / 2;
	printf("% *s % s % *s\n", padlen, "", text, padlen, "");
}

//void topLines()
//{
//	for (i = 0; i < cmd_dimension.columns; i++) {
//		printf(RED "_" RESET );
//		printf(YELLOW "_" RESET );
//	}
//}
//
//void bottomLines()
//{
//	for (i = 0; i < cmd_dimension.columns; i++) {
//		printf(YELLOW "_" RESET);
//		printf(RED "_" RESET);
//	}
//}

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

//char* replaceWord(const char* s, const char* oldW, const char* newW)
//{
//	char* result;
//	int i, cnt = 0;
//	int newWlen = strlen(newW);
//	int oldWlen = strlen(oldW);
//
//	// Counting the number of times old word 
//	// occur in the string 
//	for (i = 0; s[i] != '\0'; i++)
//	{
//		if (strstr(&s[i], oldW) == &s[i])
//		{
//			cnt++;
//
//			// Jumping to index after the old word. 
//			i += oldWlen - 1;
//		}
//	}
//
//	// Making new string of enough length 
//	result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
//
//	i = 0;
//	while (*s)
//	{
//		// compare the substring with the result 
//		if (strstr(s, oldW) == s)
//		{
//			strcpy(&result[i], newW);
//			i += newWlen;
//			s += oldWlen;
//		}
//		else
//			result[i++] = *s++;
//	}
//
//	result[i] = '\0';
//	return result;
//}