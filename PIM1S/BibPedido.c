#include "util.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

struct BibPedido {
	char* idPedido;
	char* idClientePedido;
	int qtdProdutoPedido;
	char* nomeProdutoPedido[25];
	float totalPedido;
};

static bool FinalizarPedido(int formaPagamento) {
	FILE* file;
	int id = (int)ContarPedidos() + 1;
	char line[1024];

	if (id == 1) {
		file = fopen(tb_pedido, "w");
	}
	else {
		file = fopen(tb_pedido, "a");
	}

	switch (formaPagamento)
	{
	case 1:
		if (fprintf(file, "%d;%s;%d;", id, idCliente, qntProdutoCarrinho)) {
			for (int i = 1; i <= qntProdutoCarrinho; i++) {
				fprintf(file, "%s;", nomeProdutoCarrinho[i]);
			}
			fprintf(file, "%0.2f;\n", totalProdutoCarrinho);
		}
		fclose(file);
		return true;
	case 2:
		if (fprintf(file, "%d;%s;%d;", id, idCliente, qntProdutoCarrinho)) {
			for (int i = 1; i <= qntProdutoCarrinho; i++) {
				fprintf(file, "%s;", nomeProdutoCarrinho[i]);
			}
			fprintf(file, "%0.2f;\n", (totalProdutoCarrinho + (totalProdutoCarrinho * 4.00) / 100));
		}
		fclose(file);
		return true;
	case 3:
		if (fprintf(file, "%d;%s;%d;", id, idCliente, qntProdutoCarrinho)) {
			for (int i = 1; i <= qntProdutoCarrinho; i++) {
				fprintf(file, "%s;", nomeProdutoCarrinho[i]);
			}
			fprintf(file, "%0.2f;\n", totalProdutoCarrinho + (totalProdutoCarrinho * 3.5) / 100);
		}
		fclose(file);
		return true;
	}
	return false;
}

static bool BaixaEstoque() {
	int x = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	FILE* arquivo;

	arquivo = AbreArquivo('l', tb_funcionario);

	if (arquivo == NULL)
		return EXIT_FAILURE;

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras[x] = _strdup(line);

		x++;
		//Conta a quantidade de linhas
		numLinhas++;
	}
	FecharArquivo(arquivo);
	return true;
}

static void VisualizarPedido() {
	struct BibPedido Pedidos;
	int x = 0;
	int w = 0;
	int z = 3;
	int numLinha = 0;
	char* palavras[1024];
	char* palavrass[900];
	char line[1024];
	char* values[50];
	char delimiter[] = ";";
	FILE* arquivo;

	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 11);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	arquivo = fopen(tb_pedido, "rt");

	if (arquivo == NULL) {
		return EXIT_FAILURE;
	}

	while (fgets(line, sizeof line, arquivo) != NULL) {
		numLinha++;
	}

	fclose(arquivo);

	arquivo = fopen(tb_pedido, "rt");
	printf(YELLOW "SELECIONE QUAL PEDIDO DESEJA LISTAR\n\n" WHITE);
	for (int j = 1; j <= numLinha; j++) {
		if (j % 10) {
			printf("%-5i ", j);
		}
		else {
			printf("%-5i \n", j);
		}
	}
	printf("\n");
	int id = 0;
	setbuf(stdin, NULL);
	(void)scanf("%i", &id);

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		palavras[numLinha] = NULL;
		palavrass[numLinha] = NULL;
		palavras[numLinha] = _strdup(line);
		palavrass[numLinha] = _strdup(line);
		char* ptrr = strtok(palavrass[numLinha], delimiter);
		int v = atoi(ptrr);
		if (v == id) {
			int j = 0;
			while (j < 1) {
				char* ptr = strtok(palavras[numLinha], delimiter);
				values[j] = ptr;
				j++;
				while (ptr != NULL && j < 25)
				{
					// Imprime os dados lidos do documento de texto
					//printf("'%s'\n", ptr);
					ptr = strtok(NULL, delimiter);
					values[j] = ptr;
					j++;
				}
			}
			Pedidos.idPedido = values[0];
			Pedidos.idClientePedido = values[1];
			Pedidos.qtdProdutoPedido = atoi(values[2]);
			for (z = 0; z < Pedidos.qtdProdutoPedido; z++) {
				Pedidos.nomeProdutoPedido[w] = values[z + 3];
				w++;
			}
			Pedidos.totalPedido = atof(values[z + 3]);

			printf("\n__________________________________________________________________________________________________\n");
			printf(GREEN "%-14s" WHITE "%-15s" WHITE "%-27s" WHITE "%-30s" WHITE "%-25s\n", "ID PEDIDO", "ID CLIENTE", "QUANTIDADE DE PRODUTOS", "NOME DO PRODUTO", "PREÇO TOTAL");
			printf(GREEN "%-14s" WHITE "%-15s" WHITE "%-27i" WHITE "%-20s\n", Pedidos.idPedido, Pedidos.idClientePedido, Pedidos.qtdProdutoPedido, Pedidos.nomeProdutoPedido[0]);
			//Adiciona cada linha no vetor
			for (int g = 1; g < w; g++) {
				printf(GREEN "%-14s" WHITE "%-15s" WHITE "%-27s" WHITE "%-30s\n", " ", " ", " ", Pedidos.nomeProdutoPedido[g]);
			}
			printf(WHITE "%+88s %.2f", "R$", Pedidos.totalPedido);
			printf("\n__________________________________________________________________________________________________\n");
			break;
		}
		palavras[numLinha] = NULL;
		palavrass[numLinha] = NULL;
		w = 0;
		numLinha++;
		x++;
	}
	fclose(arquivo);
}

static int ContarPedidos() {
	int numLinhas = 0;
	char line[1024];
	FILE* arquivo;
	arquivo = fopen(tb_pedido, "r");

	if (arquivo == NULL)
		return 0;

	while (fgets(line, sizeof line, arquivo) != NULL) {
		numLinhas++;
	}

	fclose(arquivo);
	return numLinhas;
}