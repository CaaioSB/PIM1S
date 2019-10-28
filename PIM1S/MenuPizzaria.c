#include "MenuPizzaria.h"
#include "util.h"
#include "conio.h"
#include "BibFuncionario.h""

void menuPizzaria() {
	char opcao;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU PRINCIPAL - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 11);
	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1" WHITE " NOVO PEDIDO\n");
	printf(GREEN "2" WHITE " CATÁLOGO\n");
	printf(GREEN "3" WHITE " FEEDBACK\n");
	printf(GREEN "4" WHITE " GERENCIAMENTO\n");
	printf(YELLOW "9" WHITE " DESLOGAR\n");
	printf(RED "0" WHITE " SAIR\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		NovoPedido();
		break;
	case '2':
		MostrarCatalogo();
		break;
	case '3':
		menuFeedback();
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
		centerText(RED "\nVOCÊ ESCOLHEU SAIR...", cmd_dimension.columns + 4);
		Sleep(2000);
		exit(0);
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA" YELLOW " (DE 1 A 5)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto inicio;
	}
}