#include "BibProduto.h"
#include "CadProduto.h"
#include "util.h"

void CadProduto() {
	system(CLEAR_SCREEN_PROGRAM);
	setbuf(stdin, NULL);
	char op;
	int opcao;
inicio:
	centerText(RED "CADASTRAR PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 10);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE O NOME DO PRODUTO: ");
	setbuf(stdin, NULL);
	(void)scanf("%[^\n]s", &BProduto.nome);
	printf("SELECIONE O TIPO DO PRODUTO: ");
	printf(GREEN "\n1 " RESET "PIZZA SALGADA");
	printf(GREEN "\n2 " RESET "PIZZA DOCE");
	printf(GREEN "\n3 " RESET "POÇÃO");
	printf(GREEN "\n4 " RESET "BEBIDA\n");
	printf("OPÇÃO: ");
tipoProduto:
	setbuf(stdin, NULL);
	op = _getch();

	switch (op)
	{
	case '1':
		BProduto.tipo = "PIZZA SALGADA";
		break;
	case '2':
		BProduto.tipo = "PIZZA DOCE";
		break;
	case '3':
		BProduto.tipo = "POÇÃO";
		break;
	case '4':
		BProduto.tipo = "BEBIDA";
		break;
	default:
		printf(RED "SELECIONE UMA OPÇÃO VÁLIDA " YELLOW "(DE 1 A 4)" RESET);
		goto tipoProduto;
	}

	printf("\nDIGITE A QUANTIDADE: ");
	setbuf(stdin, NULL);
	(void)scanf("%d", &BProduto.quantidade);

	printf("DIGITE O PREÇO: ");
	setbuf(stdin, NULL);
	(void)scanf("%f", &BProduto.preco);

	if (CadastrarProduto(BProduto.nome, BProduto.tipo, BProduto.quantidade, BProduto.preco)) {
		MenuProduto();
		setbuf(stdin, NULL);
	}
	else {
		goto inicio;
		setbuf(stdin, NULL);
	}
}