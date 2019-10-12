#include "MenuFeedback.h"
#include "util.h"

void MenuFeedback() {
	int opcao;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU DE FEEDBACK - SISTEMA GERENCIADOR DE PIZZARIA" RESET);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1" RESET " CADASTRAR FEEDBACK");
	printf(GREEN "2" RESET " LISTAR FEEDBACKS");
	printf(YELLOW "9" RESET " VOLTAR\n");
	printf(RED "0" RESET " SAIR\n");
	opcao = _getch();

	switch (opcao)
	{
	case '1':
		goto inicio;
	case '2':
		goto inicio;
	case '9':
		MenuPizzaria();
		break;
	case '0':
		centerText(RED "VOCÊ ESCOLHEU SAIR", cmd_dimension.columns + 4);
		Sleep(2000);
		exit(0);
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 5)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" RESET, cmd_dimension.columns + 12);
		system("pause > nul");
		goto inicio;
	}
}