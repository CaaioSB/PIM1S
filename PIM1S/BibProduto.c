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
	int quantidade;
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
			centerText(RED "O PRODUTO N�O FOI CADASTRADO!" RESET, cmd_dimension.columns + 9);
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
			centerText(RED "O PRODUTO N�O FOI CADASTRADO!" RESET, cmd_dimension.columns + 9);
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
			//printf("%s\n", palavras[x]);
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
				//int quantidade = atoi(values[3]);
				Pizzas.quantidade = atoi(values[3]);
				Pizzas.preco = atoll(values[4]);
				printf(GREEN "%s " RESET "%s", Pizzas.id, Pizzas.nome);
			}
		}

		x++;
		//Conta a quantidade de linhas
		numLinhas++;
	}
	FecharArquivo(arquivo);
	printf("\n");
	return true;
}

static bool ListarBebidas() {
	struct PRODUTO Bebidas;
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
		if (strstr(palavras[x], "BEBIDA") != NULL) {
			//printf("%s\n", palavras[x]);
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
				Bebidas.id = values[0];
				strcpy(Bebidas.nome, values[1]);
				strcpy(Bebidas.tipo, values[2]);
				//int quantidade = atoi(values[3]);
				Bebidas.quantidade = atoi(values[3]);
				Bebidas.preco = atoll(values[4]);
				printf(GREEN "%s " RESET "%s", Bebidas.id, Bebidas.nome);
			}
		}

		x++;
		//Conta a quantidade de linhas
		numLinhas++;
	}
	FecharArquivo(arquivo);
	printf("\n");
	return true;
}

static bool ListarProdutos() {
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
		printf("%s\n", palavras[x]);
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

static bool AlterarProduto(char idProduto, char nomeProduto[100], char tipoProduto[100], int qntProduto, float precoProduto) {
	/*
	*	FAZER UMA STRING QUE SIMULA UMA LINDA DO BANCO DADOS
	*	DEPOIS DE DESENVOLVER ESSA STRING EU VOU TER QUE INSERIR
	*	ELA EM UM ARQUIVO COMO BACKUP E DEPOIS DELETAR O ARQUICO ORIGINAL
	*	AP�S DELETAR O ARQUIVO ORIGINAL, EU DEVO POR CADA QUE ESTAVA NO
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
	arquivo = AbreArquivo('l', tb_produto);

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		if (i == (idProduto - 49)) {
			snprintf(line, sizeof line, "%c;%s;%s;%d;%0.2f;", idProduto, nomeProduto, tipoProduto, qntProduto, precoProduto);
			fileLine[i] = _strdup(line);
		}
		else {
			fileLine[i] = _strdup(line);
		}
		i++;
	}

	FecharArquivo(arquivo);

	FILE* newFile = AbreArquivo('g', tb_produto2);
	if (newFile == NULL) {
		centerText(RED "\n\nOCORREU UM ARRO AO ALTERAR O PRODUTO", cmd_dimension.columns + 4);
	}
	else {
		for (int x = 0; x < i; x++) {
			fprintf(newFile, "%s\n", fileLine[x]);
		}
	}
	FecharArquivo(newFile);

	if (remove(tb_produto) == 0) {
		if (rename(tb_produto2, tb_produto) == 0) {
			return true;
		}
	}
	else {
		perror("remove");
		return false;
	}
}

static bool AdicionarCarrinho(char id) {
	int numLinha = 0;
	char line[1024];
	char delimiter[] = ";";
	FILE* arquivo;
	FILE* arquivo2;
	char* palavras[50];
	int i = 0;
	char* values[9];
	char* fileLine[100];

	arquivo = AbreArquivo('l', tb_produto);

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		fileLine[i] = _strdup(line);
		i++;
	}

	FecharArquivo(arquivo);
	/*
	* O N�MERO DA LINHA � O MESMO QUE O C�DIGO DO FUNCION�RIO
	* ENT�O: SE LINHA � IGUAL A 15, O C�DIGO DO FUNCION�RIO TAMB�M SER� 15
	*/

	arquivo2 = AbreArquivo('l', tb_produto);

	if (arquivo2 == NULL)
		return EXIT_FAILURE;

	while (fgets(carrinhoCompras, sizeof carrinhoCompras, arquivo2) != NULL)
	{
		palavras[numLinha] = _strdup(carrinhoCompras);
		if (carrinhoCompras[0] == id)
		{
			qntProdutoCarrinho++;
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
			// PEGANDO OS DADOS DO FUNCION�RIO REQUERIDO
			idProdutoCarrinho[qntProdutoCarrinho] = values[0];
			nomeProdutoCarrinho[qntProdutoCarrinho] = values[1];
			precoProdutoCarrinho[qntProdutoCarrinho] = atoll(values[4]);
			totalProdutoCarrinho += atoll(values[4]);
			FecharArquivo(arquivo2);
			return true;
		}
		numLinha++;
	}
	FecharArquivo(arquivo2);
}

static char BuscarProduto(char id) {
	int numLinha = 0;
	char line[1024];
	char delimiter[] = ";";
	FILE* arquivo;
	FILE* arquivo2;
	char* palavras[50];
	int i = 0;
	char* values[9];
	char* fileLine[100];

	arquivo = AbreArquivo('l', tb_produto);

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		fileLine[i] = _strdup(line);
		i++;
	}

	FecharArquivo(arquivo);
	/*
	* O N�MERO DA LINHA � O MESMO QUE O C�DIGO DO FUNCION�RIO
	* ENT�O: SE LINHA � IGUAL A 15, O C�DIGO DO FUNCION�RIO TAMB�M SER� 15
	*/

	arquivo2 = AbreArquivo('l', tb_produto);

	if (arquivo2 == NULL)
		return EXIT_FAILURE;

	while (fgets(dadosProduto, sizeof dadosProduto, arquivo2) != NULL)
	{
		palavras[numLinha] = _strdup(dadosProduto);
		if (dadosProduto[0] == id)
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
			// PEGANDO OS DADOS DO FUNCION�RIO REQUERIDO
			idProduto = values[0];
			strcpy(nomeProduto, values[1]);
			strcpy(tipoProduto, values[2]);
			quantidadeProduto = atoi(values[3]);
			precoProduto = atoll(values[4]);
			FecharArquivo(arquivo2);
			break;
		}
		numLinha++;
	}
	FecharArquivo(arquivo2);
}