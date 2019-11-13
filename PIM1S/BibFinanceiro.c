#include "util.h"
#include <string.h>
#include <stdio.h>

struct Financeiro {
	int quantidadePedidos;
	float totalLucro;
	float totalPedido;
};

static void ListarTotalPedido() {
	struct Financeiro Pedidos;
	Pedidos.totalPedido = 0;
	int x = 0;
	int w = 0;
	int z = 3;
	int numLinha = 0;
	char* palavras[50];
	char line[1024];
	char* values[50];
	char delimiter[] = ";";
	FILE* arquivo;
	float totalLucrado = 0;

	arquivo = fopen("C:\\SGP\\db\\tb_pedido.txt", "rt");

	if (arquivo == NULL) {
		return EXIT_FAILURE;
	}

	while (fgets(line, sizeof line, arquivo) != NULL) {
		numLinha++;
	}

	fclose(arquivo);

	arquivo = fopen("C:\\SGP\\db\\tb_pedido.txt", "rt");

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		palavras[numLinha] = _strdup(line);
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
		Pedidos.quantidadePedidos = atoi(values[2]);
		/*for (z = 0; z < Pedidos.quantidadePedidos; z++) {
			Pedidos.nomeProdutoPedido[w] = values[z + 3];
			w++;
		}*/
		z = (Pedidos.quantidadePedidos + 3);
		totalLucrado += atoll(values[z]);
		Pedidos.totalPedido = totalLucrado;
		w = 0;
		numLinha++;
		x++;
	}
	printf(GREEN "R$ %0.2f" WHITE " %s " GREEN "%i" WHITE " %s \n", Pedidos.totalPedido, "COM", ContarPedidos(), "PEDIDOS.");
	fclose(arquivo);
}

static int ContarPedidos() {
	int numLinhas = 0;
	char line[1024];
	FILE* arquivo;
	arquivo = fopen("C:\\SGP\\db\\tb_pedido.txt", "r");

	if (arquivo == NULL)
		return 0;

	while (fgets(line, sizeof line, arquivo) != NULL) {
		numLinhas++;
	}

	fclose(arquivo);
	return numLinhas;
}