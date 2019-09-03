#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>
#include <stdbool.h>
#include <string.h>

#include "util.h"

struct REGISTER {
	char nome_completo[1024];
	char email[1024];
	char rg[1024];
	char cpf[1024];
	char cep[1024];
	char usuario[1024];
	char senha[1024];
};

static void CadastrarFuncionario(char nome[30], char email[100], char rg[20], char cpf[11], char cep[8], char usuario[10], char senha[10]) {
	FILE* arquivo;
	arquivo = AbreArquivo('a', "C:\\SGP\\db\\tb_funcionario.txt");
	fprintf(arquivo, "%s|%s|%s|%s|%s|%s|%s|", nome, email, rg, cpf, cep, usuario, senha);
	FecharArquivo(arquivo);
}

static bool LoginFuncionario(char usuario[], char senha[]) {
	FILE* arquivo;
	arquivo = AbreArquivo('l', "C:\\SGP\\db\\tb_funcionario.txt");

	if (arquivo == NULL) {
		printf(RED "BANCO DE DADOS NÃO ENCONTRADO.\n" RESET);
		exit(0);
	}

	char* string[100];
	char* array[1024];
	int i = 0;
	char* msg[12];
	array[5] = "x";
	array[6] = "x";
	msg[1] = "x";
	msg[2] = "x";

	while (fgets(string, 100, arquivo) != NULL) {
		array[i] = strtok(string, "|");

		while (array[i] != NULL) {
			printf(array[i]);
			if (strcmp(array[i], usuario) == 0) {
				msg[1] = "U";
			}
			if (strcmp(array[i], senha) == 0) {
				msg[2] = "S";
			}
			array[++i] = strtok(NULL, "|");
		}

		if (strcmp(msg[1], "U") && strcmp(msg[2], "S") == 0) {
			printf("login feito");
			return true;
		}
		/*if (strcmp(array[5], usuario) == 0 && strcmp(array[6], senha) == 0) {
			centerText(GREEN "LOGIN REALIZADO COM SUCESSO!" RESET, cmd_dimension.columns);
			Sleep(3000);
			FecharArquivo(arquivo);
			return true;
		}*/
		int i = 0;
	}
}

// static bool trocarSenha(char senha[]) {}

// static bool recuperarSenha(char email[], char usuario[]) {}