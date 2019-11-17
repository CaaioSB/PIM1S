#include "BibPedido.h"
#include "MenuPedido.h"
#include "util.h"

void MenuPedido() {
	int opcao;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 11);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1 " WHITE "LISTAR PEDIDOS\n");
	printf(GREEN "2 " WHITE "VISUALIZAR PEDIDO\n");
	printf(RED "3 " RED "REMOVER PEDIDO\n");
	printf(YELLOW "9 " WHITE "VOLTAR\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		//CadProduto();
		break;
	case '2':
		VisualizarPedido();
		printf("\n\n");
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause >nul");
		goto inicio;
	case '3':
		centerText(RED "ESSA FUNÇÃO NÃO ESTA DISPONÍVEL NESTA VERSÃO DO SISTEMA, SELECIONE UMA OPÇÃO VÁLIDA " YELLOW "(DE 1 a 2 ou 9)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU", WHITE, cmd_dimension.columns + 12);
		system("pause");
		goto inicio;
		break;
	case '9':
		menuPizzaria();
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA! " YELLOW "(DE 1 a 2 ou 9)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU", WHITE, cmd_dimension.columns + 12);
		system("pause");
		goto inicio;
	}
}
