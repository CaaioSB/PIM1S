#include "MenuGerenciamento.h"
#include "util.h"

void MenuGerenciamento() {
	int opcao;
	inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "GERENCIAMENTO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 11);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1" RESET " FUNCIONARIO\n");
	printf(GREEN "2" RESET " CLIENTE\n");
	printf(GREEN "3" RESET " PRODUTO\n");
	printf(GREEN "4" RESET " PEDIDOS\n");
	printf(GREEN "6" RESET " FINANCEIRO\n");
	printf(YELLOW "9" RESET " VOLTAR\n");
	printf(RED "0" RESET " SAIR\n");
	opcao = _getch();

	switch (opcao)
	{
	case '1':
		MenuFuncionario();
		break;
	case '2':
		break;
	case '3':
		MenuProduto();
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '9':
		menuPizzaria();
	case '0':
		centerText(RED "\nVOCÊ ESCOLHEU SAIR...", cmd_dimension.columns + 4);
		Sleep(2000);
		exit(0);
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW "(DE 1 A 5)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" RESET, cmd_dimension.columns + 12);
		Sleep(2000);
		goto inicio;
		system("pause > nul");
	}
}