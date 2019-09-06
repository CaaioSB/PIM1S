#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>
#include <stdbool.h>
#include <string.h>

#include "util.h"
#include "MenuPizzaria.h"

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
	int i = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	char delimiter[] = ";";
	char* values[1024];
	FILE* arquivo;
	arquivo = fopen("C:\\SGP\\db\\tb_funcionario.txt", "r");

	if (arquivo == NULL)
		return EXIT_FAILURE;

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras[i] = strdup(line);

		i++;

		//Conta a quantidade de linhas
		numLinhas++;
	}

	for (int x = 0; x < numLinhas; x++) {
		int j = 0;
		char* ptr = strtok(palavras[x], delimiter);
		values[j] = ptr;
		j++;
		while (ptr != NULL)
		{
			// Imprime os dados lidos do documento de texto
			//printf("'%s'\n", ptr);

			ptr = strtok(NULL, delimiter);
			values[j] = ptr;
			j++;

		}

		if (strcmp(usuario, values[5]) == 0 && strcmp(senha, values[6]) == 0) {
			centerText(GREEN "LOGIN REALIZADO" RESET, cmd_dimension.columns);

			Sleep(3000);
			mostrarMenuPrincipal();
			return true;
		}
		free(ptr);
	}
	return false;
}

// static bool trocarSenha(char senha[]) {}

// static bool recuperarSenha(char email[], char usuario[]) {}