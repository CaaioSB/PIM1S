#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "util.h"
#include "MenuPizzaria.h"
#include "main.h"


struct REGISTER {
	char nome_completo[1024];
	char email[1024];
	char rg[1024];
	char cpf[1024];
	char cep[1024];
	char usuario[1024];
	char senha[1024];
	char funcao[1024];
};

static bool CadastrarFuncionario(char nome[30], char email[100], char rg[20], char cpf[11], char cep[8], char usuario[10], char senha[10], char funcao[100]) {
	FILE* arquivo;
	arquivo = AbreArquivo('a', tb_funcionario);
	int id = (int)ContarFuncionarios() + 1;
	fprintf(arquivo, "%d;%s;%s;%s;%s;%s;%s;%s;%s;\n", id, nome, email, rg, cpf, cep, usuario, senha, funcao);
	printf("\n\n");
	Sleep(3000);
	FecharArquivo(arquivo);
	return true;
}


static bool LoginFuncionario(char usuario[], char senha[]) {
	int i = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	char delimiter[] = ";";
	char* values[1024];
	FILE* arquivo;

	arquivo = fopen(tb_funcionario, "r");

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

		if (strcmp(usuario, values[6]) == 0 && strcmp(senha, values[7]) == 0) {
			printf("\n\n");
			centerText(GREEN "LOGIN REALIZADO" RESET, cmd_dimension.columns + 10);
			strcpy(loggedNomeCompleto, values[1]);
			Sleep(3000);
			menuPizzaria();
			return true;
		}
		free(ptr);
	}
	return false;
}

static bool ListarFuncionarios() {
	int x = 0;
	int numLinhas2 = 0;
	char* palavras2[50];
	char line2[1024];
	char delimiter2[] = ";";
	FILE* arquivo2;
	arquivo2 = fopen(tb_funcionario, "r");

	if (arquivo2 == NULL)
		return EXIT_FAILURE;

	while (fgets(line2, sizeof line2, arquivo2) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras2[x] = strdup(line2);
		printf("%s\n", palavras2[x]);
		x++;

		//Conta a quantidade de linhas
		numLinhas2++;
	}
	return true;
}

static char AlterarFuncionario(char idFuncionario, char nomeFuncionario[100], char emailFuncionario[100], char rgFuncionario[20], char cpfFuncionario[11], char cepFuncionario[20], char userFuncionario[20], char passFuncionario[20], char funcaoFuncionario[50]) {
	/*  FAZER UMA STRING QUE SIMULA UMA LINDA DO BANCO DADOS
	*	DEPOIS DE DESENVOLVER ESSA STRING EU VOU TER QUE INSERIR
	*	ELA EM UM ARQUIVO COMO BACKUP E DEPOIS DELETAR O ARQUICO ORIGINAL
	*	APÓS DELETAR O ARQUIVO ORIGINAL, EU DEVO POR CADA QUE ESTAVA NO
	*/

	int numLinha = 0;
	char line[1024];
	char delimiter[] = ";";
	FILE* arquivo;
	FILE* newArquivo;
	char* palavras[50];
	int i = 0;
	char* values[9];
	char* fileLine[100];

	printf("%s", dadosFuncionario);
	arquivo = AbreArquivo('l', tb_funcionario);

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		if (i == (idFuncionario - 49)) {
			snprintf(line, sizeof line, "%c;%s;%s;%s;%s;%s;%s;%s;%s;", idFuncionario, nomeFuncionario, emailFuncionario, rgFuncionario, cpfFuncionario, cepFuncionario, userFuncionario, passFuncionario, funcaoFuncionario);
			fileLine[i] = strdup(line);

		}
		else {
			fileLine[i] = strdup(line);
		}
		i++;
	}

	FecharArquivo(arquivo);
	//arquivo = fopen(tb_funcionario, "w+");
	FILE* teste = fopen("C:\\SGP\\db\\arquivo.txt", "w");
	if (teste == NULL) {
		centerText(RED "\n\nOCORREU UM ARRO AO ALTERAR O FUNCIONÁRIO", cmd_dimension.columns + 4);
	}
	else {
		fprintf(teste, "%c", 'a');
		for (int x = 0; x < i; x++) {
			printf(*fileLine);
		}
		fclose(teste);
	}
}

static char BuscarFuncionario(char id) {
	int numLinha = 0;
	char line[1024];
	char delimiter[] = ";";
	FILE* arquivo;
	char* palavras[50];
	int i = 0;
	char* values[9];
	char* fileLine[100];

	arquivo = fopen("C:\\SGP\\db\\tb_funcionario.txt", "r");

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		fileLine[i] = strdup(line);
		i++;
	}

	/*
	* O NÚMERO DA LINHA É O MESMO QUE O CÓDIGO DO FUNCIONÁRIO
	* ENTÃO: SE LINHA É IGUAL A 15, O CÓDIGO DO FUNCIONÁRIO TAMBÉM SERÁ 15
	*/

	arquivo = fopen("C:\\SGP\\db\\tb_funcionario.txt", "r");

	if (arquivo == NULL)
		return EXIT_FAILURE;

	while (fgets(dadosFuncionario, sizeof dadosFuncionario, arquivo) != NULL)
	{
		palavras[numLinha] = strdup(dadosFuncionario);
		if (dadosFuncionario[0] == id)
		{
			int j = 0;
			while (j < 1) {
				char* ptr = strtok(palavras[numLinha], delimiter);
				values[j] = ptr;
				j++;
				while (ptr != NULL && j < 9)
				{
					// Imprime os dados lidos do documento de texto
					//printf("'%s'\n", ptr);
					ptr = strtok(NULL, delimiter);
					values[j] = ptr;
					j++;
				}
			}
			// PEGANDO OS DADOS DO FUNCIONÁRIO REQUERIDO
			idFuncionario = values[0];
			strcpy(nomeFuncionario, values[1]);
			strcpy(emailFuncionario, values[2]);
			strcpy(rgFuncionario, values[3]);
			strcpy(cpfFuncionario, values[4]);
			strcpy(cepFuncionario, values[5]);
			strcpy(userFuncionario, values[6]);
			strcpy(passFuncionario, values[7]);
			strcpy(funcaoFuncionario, values[8]);
			break;
		}
		numLinha++;
	}
}

static int ContarFuncionarios() {
	int numLinhas = 0;
	char line[1024];
	FILE* arquivo;
	arquivo = fopen("C:\\SGP\\db\\tb_funcionario.txt", "r");

	if (arquivo == NULL)
		return 0;

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		numLinhas++;
	}
	return numLinhas;
}

// static bool trocarSenha(char senha[]) {}

// static bool recuperarSenha(char email[], char usuario[]) {}