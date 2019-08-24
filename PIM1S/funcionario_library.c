#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>
#include <stdbool.h>

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
	fprintf(arquivo, "%s|%s|%s|%s|%s|%s|%s\n", nome, email, rg, cpf, cep, usuario, senha);
	FecharArquivo(arquivo);
}

static bool LoginFuncionario(char usuario, char senha) {
	FILE* arquivo;
	arquivo = AbreArquivo('l', "C:\\SGP\\db\\tb_funcionario.txt");

	if (arquivo == NULL) {
		printf("BANCO DE DADOS NÃO ENCONTRADO.\n");
		exit(0);
	}

	char string[100];

	while (fgets(string, 100, arquivo) != NULL) {
		printf("%s", string);
	}

	FecharArquivo(arquivo);
}