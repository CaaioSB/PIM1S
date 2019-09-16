#include "MenuPizzaria.h"
#include "util.h"
#include "conio.h"
#include "BibFuncionario.h""

void menuPizzaria() {
	char opcao;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText("MENU PRINCIPAL - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);
	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1" RESET " NOVO PEDIDO\n");
	printf(GREEN "2" RESET " CAT�LOGO\n");
	printf(GREEN "3" RESET " FEEDBACK\n");
	printf(GREEN "4" RESET " GERENCIAMENTO\n");
	printf(YELLOW "9" RESET " DESLOGAR\n");
	printf(RED "0" RESET " SAIR\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		NovoPedido();
		break;
	case '2':
		menuCliente();
		break;
	case '3':
		// FEEDBACK
		break;
	case '4':
		MenuGerenciamento();
		break;
	case '9':
		// DESLOGAR
		menuPrincipal();
		break;
	case '0':
		// SAIR
		exit(0);
		break;
	default:
		centerText(RED "VOC� DEVE SELECIONAR UMA OP��O V�LIDA!" YELLOW "(DE 1 A 5)" RESET, cmd_dimension.columns);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" RESET, cmd_dimension.columns);
		system("pause");
		goto inicio;

	}
}