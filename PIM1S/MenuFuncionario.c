#include "MenuFuncionario.h"
#include "util.h"

void MenuFuncionario() {
	int opcao;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU DO FUNCIONARIO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 11);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1" RESET " CADASTRAR FUNCION�RIO\n");
	printf(GREEN "2" RESET " ALTERAR FUNCION�RIO\n");
	printf(GREEN "3" RESET " DESLIGAR FUNCION�RIO\n");
	printf(YELLOW "9" RESET " VOLTAR\n");
	printf(RED "0" RESET " SAIR\n");
	opcao = _getch();

	switch (opcao)
	{
	case '1':
		CadFuncionario();
		goto inicio;
	case '2':
		AltFuncionario();
		break;
	case '3':
		break;
	case '9':
		MenuGerenciamento();
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
