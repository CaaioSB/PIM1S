#include "util.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

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