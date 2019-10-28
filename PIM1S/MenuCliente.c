#include "MenuCliente.h"
#include "util.h"

void MenuCliente() {
	int opcao;
	inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU CLIENTE - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 11);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(GREEN "1" WHITE " CADASTRAR CLIENTE\n");
	printf(GREEN "2" WHITE " ALTERAR CLIENTE\n");
	printf(GREEN "3" WHITE " REMOVER CLIENTE\n");
	printf(YELLOW "9" WHITE " VOLTAR\n");
	printf(RED "0" WHITE "SAIR\n");
	opcao = _getch();

	switch (opcao)
	{
	case '1':
		CadCliente();
		goto inicio;
	case '2':
		goto inicio;
	case '3':
		goto inicio;
	case '9':
		MenuGerenciamento();
		break;
	case '0':
		centerText(RED "VOCÊ ESCOLHEU SAIR...", cmd_dimension.columns + 4);
		Sleep(2000);
		exit(0);
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 5)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto inicio;
	}
}