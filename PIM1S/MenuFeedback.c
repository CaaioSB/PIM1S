#include "MenuFeedback.h"
#include "util.h"

void menuFeedback() {
	int opcao;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU DE FEEDBACK - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 10);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1" RESET " CADASTRAR FEEDBACK\n");
	printf(GREEN "2" RESET " LISTAR FEEDBACKS\n");
	printf(YELLOW "9" RESET " VOLTAR\n");
	printf(RED "0" RESET " SAIR\n");
	opcao = _getch();

	switch (opcao)
	{
	case '1':
		CadFeedback();
		goto inicio;
	case '2':
		LisFeedback();
		goto inicio;
	case '9':
		menuPizzaria();
		break;
	case '0':
		centerText(RED "VOC� ESCOLHEU SAIR", cmd_dimension.columns + 4);
		Sleep(2000);
		exit(0);
		break;
	default:
		centerText(RED "VOC� DEVE SELECIONAR UMA OP��O V�LIDA!" YELLOW " (DE 1 A 5)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" RESET, cmd_dimension.columns + 12);
		system("pause > nul");
		goto inicio;
	}
}