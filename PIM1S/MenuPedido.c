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

	printf(GREEN "1 " WHITE "VISUALIZAR PEDIDOS\n");
	printf(GREEN "2 " WHITE "LISTAR PEDIDOS\n");
	printf(GREEN "3 " WHITE "REMOVER PEDIDO\n");
	printf(YELLOW "9 " WHITE "VOLTAR\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		//CadProduto();
		break;
	case '2':
		ListarPedidos();
		break;
	case '3':
		//RemProduto();
		break;
	case '9':
		menuPizzaria();
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW "(DE 1 a 5)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU", WHITE, cmd_dimension.columns + 12);
		system("pause");
		goto inicio;
	}
}
