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
			fprintf(file, "%0.2f;\n", totalProdutoCarrinho + (totalProdutoCarrinho * 4.0) / 100);
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

static void ListarPedidos() {
	struct BibPedido Pedidos;
	int x = 0;
	int j = 0;
	int w = 0;
	int z = 3;
	int numLinhas = 0;
	char* palavras[50];
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

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		printf("\n__________________________________________________________________________\n");
		printf(GREEN "%-14s" WHITE "%-15s" WHITE "%-15s" WHITE "%+20s\n" WHITE, "ID PEDIDO", "ID CLIENTE", "QUANTIDADE DE PRODUTOS", "NOME DO PRODUTO");
		//Adiciona cada linha no vetor
		palavras[x] = _strdup(line);
		char* ptr = strtok(palavras[x], delimiter);
		values[j] = ptr;
		j++;
		while (ptr != NULL && j < 25) {
			ptr = strtok(NULL, delimiter);
			values[j] = ptr;
			j++;
		}
		Pedidos.idPedido = values[0];
		Pedidos.idClientePedido = values[1];
		Pedidos.qtdProdutoPedido = atoi(values[2]);
		for (z = 0; z < Pedidos.qtdProdutoPedido; z++) {
			Pedidos.nomeProdutoPedido[w] = values[z + 3];
			w++;
		}
		Pedidos.totalPedido = atoll(values[z++]);
		printf(GREEN "%-14s" WHITE "%-15s" WHITE "%-15i", Pedidos.idPedido, Pedidos.idClientePedido, Pedidos.qtdProdutoPedido);
		for (int g = 0; g < w; g++) {
			printf(WHITE "\n%+74s", Pedidos.nomeProdutoPedido[g]);
		}
		printf("\n__________________________________________________________________________\n");
		w = 0;
		j = 0;
		numLinhas++;
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