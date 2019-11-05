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
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	char* values[50];
	char delimiter[] = ";";
	FILE* arquivo;

	arquivo = fopen(tb_pedido, "rt");

	if (arquivo == NULL) {
		return EXIT_FAILURE;
	}

	printf(GREEN "%-15s" GREEN "%-32s" GREEN "%-0s\n" GREEN, "ID", "NOME DO CLIENTE", "TELEFONE CELULAR");
	while (fgets(line, sizeof line, arquivo) != NULL)
	{
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
		for (int z = 3; z <= Pedidos.qtdProdutoPedido * 2; z++) {
			for (int w = 0; w < Pedidos.qtdProdutoPedido; w++) {
				Pedidos.nomeProdutoPedido[w], values[z];
			}
		}
	}
	Pedidos.totalPedido = atoll(values[5]);
	printf(WHITE "%-14s " WHITE "%-32s" WHITE "%-0i\n" WHITE, Pedidos.idPedido, Pedidos.idClientePedido, Pedidos.qtdProdutoPedido);
	j = 0;
	x++;
	//Conta a quantidade de linhas
	numLinhas++;
	fclose(arquivo);
	return true;
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