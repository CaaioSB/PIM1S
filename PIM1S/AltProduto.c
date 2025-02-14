#include "BibProduto.h"
#include "AltProduto.h"
#include <string.h>
#include "util.h"

void AltProduto() {
	char opcao;
	int alt;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "SELECIONE UM PRODUTO\n" WHITE);
	ListarProdutos();
	opcao = _getch();

	BuscarProduto(opcao);
opc:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}
	printf("O QUE VOC� DESEJA ALTERAR?");
	setbuf(stdin, NULL);
	printf(GREEN "\n1 " WHITE "NOME");
	printf(GREEN "\n2 " WHITE "TIPO");
	printf(GREEN "\n3 " WHITE "QUANTIDADE");
	printf(GREEN "\n4 " WHITE "PRE�O");
	printf(YELLOW "\n9 " WHITE "CONFIRMAR");
	printf(RED "\n0 " WHITE "CANCELAR\n");
	alt = _getch();

	switch (alt)
	{
	case '1':
		printf("DIGITE O NOVO NOME: " RED "(NOME ATUAL: %s%s", nomeProduto, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%[^\n]s", &nomeProduto);
		goto opc;
	case '2':
		printf("DIGITE O NOVO TIPO: " RED "(TIPO ATUAL: %s%s", tipoProduto, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%[^\n]s", &tipoProduto);
		goto opc;
	case '3':
		printf("DIGITE O NOVO QUANTIDADE: " RED "(QUANTIDADE ATUAL: %d%s", quantidadeProduto, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%d", &quantidadeProduto);
		goto opc;
	case '4':
		printf("DIGITE O NOVO PRE�O: " RED "(PRE�O ATUAL: %0.2f%s", precoProduto, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%f", &precoProduto);
		goto opc;
	case '9':
		// CHAMA O M�TODO PARA CONFIRMAR
		if (AlterarProduto(opcao, nomeProduto, tipoProduto, quantidadeProduto, precoProduto)) {
			centerText(GREEN "O PRODUTO FOI ALTERADO COM SUCESSO", cmd_dimension.columns - 6);
		}
		else {
			centerText(RED "OCORREU UM ERRO AO ALTERA O PRODUTO", cmd_dimension.columns - 4);
		}
		Sleep(3000);
		MenuProduto();
	case '0':
		centerText(RED "VOC� CANCELOU AS ALTERA��ES, VOLTANDO AO MENU" WHITE, cmd_dimension.columns + 10);
		MenuProduto();
	default:
		centerText(RED "SELECIONE UMA OP��O V�LIDA " YELLOW "(DE 1 A 0)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause >nul");
		goto opc;
	}
	system("pause > nul");
}