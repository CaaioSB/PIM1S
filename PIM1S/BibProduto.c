#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "cmd_resolution.h"
#include "util.h"
#include "MenuPizzaria.h"

struct PRODUTO {
	char nome[100];
	char* tipo;
	int quantidade;
	float preco;
};

static bool CadastrarProduto(char nome[100], char* tipo, int quantidade, double preco) {
	FILE* arquivo;
	arquivo = AbreArquivo('a', "C:\\SGP\\db\\tb_produto.txt");
	int id = (int)ContarProdutos() + 1;
	if (fprintf(arquivo, "%d;%s;%s;%d;%.2f;\n", id, nome, tipo, quantidade, preco)) {
		FecharArquivo(arquivo);
		printf("\n\n");
		centerText(GREEN "O PRODUTO FOI CADASTRADO COM SUCESSO!" RESET, cmd_dimension.columns + 12);
		Sleep(3000);
		return true;
	}
	else {
		FecharArquivo(arquivo);
		printf("\n\n");
		centerText(RED "O PRODUTO NÃO FOI CADASTRADO!" RESET, cmd_dimension.columns + 9);
		Sleep(3000);
		return false;
	}
}

static int ContarProdutos() {
	int numLinhas = 0;
	char line[1024];
	FILE* arquivo;
	arquivo = fopen("C:\\SGP\\db\\tb_produto.txt", "r");

	if (arquivo == NULL)
		return 0;

	while (fgets(line, sizeof line, arquivo) != NULL) {
		numLinhas++;
	}
	return numLinhas;
}