#include "BibProduto.h"
#include "CadProduto.h"
#include "util.h"

void CadProduto() {
	system(CLEAR_SCREEN_PROGRAM);
	setbuf(stdin, NULL);
	char op;
	int opcao;
inicio:
	centerText(MAGENTA "CADASTRAR PRODUTO - PIZZABUG GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 15);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE O NOME DO PRODUTO: ");
	setbuf(stdin, NULL);
	(void)scanf("%[^\n]s", newProduto.nome);
	printf("SELECIONE O TIPO DO PRODUTO: ");
	printf(GREEN "\n1 " RESET "PIZZA SALGADA");
	printf(GREEN "\n2 " RESET "PIZZA DOCE");
	printf(GREEN "\n3 " RESET "POÇÃO");
	printf(GREEN "\n4 " RESET "BEBIDA\n");
	printf("OPÇÃO: ");
	tipoProduto:
	op = _getch();

	switch (op)
	{
	case '1':
		newProduto.tipo = "PIZZA SALGADA";
		break;
	case '2':
		newProduto.tipo = "PIZZA DOCE";
		break;
	case '3':
		newProduto.tipo = "POÇÃO";
		break;
	case '4':
		newProduto.tipo = "BEBIDA";
		break;
	default:
		printf(RED "SELECIONE UMA OPÇÃO VÁLIDA " YELLOW "(DE 1 A 4)" RESET);
		goto tipoProduto;
	}

	printf("\nDIGITE A QUANTIDADE: ");
	setbuf(stdin, NULL);
	(void)scanf("%d", &newProduto.quantidade);

	printf("DIGITE O PREÇO: ");
	setbuf(stdin, NULL);
	(void)scanf("%lf", &newProduto.preco);

	if (CadastrarProduto(newProduto.nome, newProduto.tipo, newProduto.quantidade, newProduto.preco)) {
		MenuProduto();
		setbuf(stdin, NULL);
	}
	else {
		goto inicio;
		setbuf(stdin, NULL);
	}
}