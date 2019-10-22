#include "BibProduto.h"
#include "AltProduto.h"
#include <string.h>
#include "util.h"

void AltProduto() {
	char opcao;
	int alt;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "SELECIONE UM PRODUTO\n" RESET);
	ListarProdutos();
	opcao = _getch();

	BuscarProduto(opcao);
opc:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}
	printf("O QUE VOCÊ DESEJA ALTERAR?");
	setbuf(stdin, NULL);
	printf(GREEN "\n1 " RESET "NOME");
	printf(GREEN "\n2 " RESET "TIPO");
	printf(GREEN "\n3 " RESET "QUANTIDADE");
	printf(GREEN "\n4 " RESET "PREÇO");
	printf(YELLOW "\n9 " RESET "CONFIRMAR");
	printf(RED "\n0 " RESET "CANCELAR\n");
	alt = _getch();

	switch (alt)
	{
	case '1':
		printf("DIGITE O NOVO NOME: " RED "(NOME ATUAL: %s%s", nomeProduto, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%[^\n]s", &nomeProduto);
		goto opc;
	case '2':
		printf("DIGITE O NOVO TIPO: " RED "(TIPO ATUAL: %s%s", tipoProduto, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%[^\n]s", &tipoProduto);
		goto opc;
	case '3':
		printf("DIGITE O NOVO QUANTIDADE: " RED "(QUANTIDADE ATUAL: %d%s", quantidadeProduto, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%d", &quantidadeProduto);
		goto opc;
	case '4':
		printf("DIGITE O NOVO PREÇO: " RED "(PREÇO ATUAL: %0.2f%s", precoProduto, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%f", &precoProduto);
		goto opc;
	case '9':
		// CHAMA O MÉTODO PARA CONFIRMAR
		if (AlterarProduto(opcao, nomeProduto, tipoProduto, quantidadeProduto, precoProduto)) {
			centerText(GREEN "O PRODUTO FOI ALTERADO COM SUCESSO", cmd_dimension.columns - 6);
		}
		else {
			centerText(RED "OCORREU UM ERRO AO ALTERA O PRODUTO", cmd_dimension.columns - 4);
		}
		Sleep(3000);
		MenuProduto();
	case '0':
		centerText(RED "VOCÊ CANCELOU AS ALTERAÇÕES, VOLTANDO AO MENU" RESET, cmd_dimension.columns + 10);
		MenuProduto();
	default:
		centerText(RED "SELECIONE UMA OPÇÃO VÁLIDA " YELLOW "(DE 1 A 0)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" RESET, cmd_dimension.columns + 12);
		system("pause >nul");
		goto opc;
	}
	system("pause > nul");
}