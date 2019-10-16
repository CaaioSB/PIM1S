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

struct PRODUTO {
	char* id;
	char nome[100];
	char tipo[50];
	int* quantidade;
	float preco;
};

static bool CadastrarProduto(char nome[100], char* tipo, int quantidade, double preco) {
	FILE* file;
	int id = (int)ContarProdutos() + 1;
	if (id == 1) {
		file = fopen(tb_produto, "w");
		if (fprintf(file, "%d;%s;%s;%d;%.2f;\n", id, nome, tipo, quantidade, preco)) {
			FecharArquivo(file);
			printf("\n\n");
			centerText(GREEN "O PRODUTO FOI CADASTRADO COM SUCESSO!" RESET, cmd_dimension.columns + 12);
			Sleep(3000);
			return true;
		}
		else {
			FecharArquivo(file);
			printf("\n\n");
			centerText(RED "O PRODUTO NÃO FOI CADASTRADO!" RESET, cmd_dimension.columns + 9);
			Sleep(3000);
			return false;
		}
	}
	else {
		file = fopen(tb_produto, "a");
		if (fprintf(file, "%d;%s;%s;%d;%.2f;\n", id, nome, tipo, quantidade, preco)) {
			FecharArquivo(file);
			printf("\n\n");
			centerText(GREEN "O PRODUTO FOI CADASTRADO COM SUCESSO!" RESET, cmd_dimension.columns + 12);
			Sleep(3000);
			return true;
		}
		else {
			FecharArquivo(file);
			printf("\n\n");
			centerText(RED "O PRODUTO NÃO FOI CADASTRADO!" RESET, cmd_dimension.columns + 9);
			Sleep(3000);
			return false;
		}
	}
}

static bool ListarPizzas() {
	struct PRODUTO Pizzas;
	int j = 0;
	int x = 0;
	int numLinhas = 0;
	char delimiter[] = ";";
	char* palavras[50];
	char line[1024];
	FILE* arquivo;
	char* values[9];

	arquivo = AbreArquivo('l', tb_produto);

	if (arquivo == NULL)
		return EXIT_FAILURE;

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras[x] = _strdup(line);
		if (strstr(palavras[x], "PIZZA") != NULL) {
			printf("%s\n", palavras[x]);
			while (j < 1) {
				char* ptr = strtok(palavras[x], delimiter);
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
				Pizzas.id = values[0];
				strcpy(Pizzas.nome, values[1]);
				strcpy(Pizzas.tipo, values[2]);
				Pizzas.quantidade = atoi(values[3]);
				Pizzas.preco = atoll(values[4]);
				printf(GREEN "%p " RESET "%s", Pizzas.id, Pizzas.nome);
			}
		}

		x++;
		//Conta a quantidade de linhas
		numLinhas++;
	}
	FecharArquivo(arquivo);
	return true;
}

static bool ListarBebidas() {
	int x = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	FILE* arquivo;

	arquivo = AbreArquivo('l', tb_produto);

	if (arquivo == NULL)
		return EXIT_FAILURE;

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras[x] = _strdup(line);
		if (strstr(palavras[x], "BEBIDA") != NULL) {
			printf("%s\n", palavras[x]);
		}

		x++;
		//Conta a quantidade de linhas
		numLinhas++;
	}
	FecharArquivo(arquivo);
	return true;
}

static int ContarProdutos() {
	int numLinhas = 0;
	char line[1024];
	FILE* arquivo;
	arquivo = fopen(tb_produto, "r");

	if (arquivo == NULL)
		return 0;

	while (fgets(line, sizeof line, arquivo) != NULL) {
		numLinhas++;
	}
	return numLinhas;
}