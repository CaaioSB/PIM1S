#include "MenuProduto.h"
#include "util.h"

void MenuProduto() {
	int opcao;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 11);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1 " WHITE "CADASTRAR PRODUTO\n");
	printf(GREEN "2 " WHITE "ALTERAR PRODUTO\n");
	printf(GREEN "3 " WHITE "REMOVER PRODUTO\n");
	printf(YELLOW "9 " WHITE "VOLTAR\n");
	printf(RED "0 " WHITE "SAIR\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		CadProduto();
		break;
	case '2':
		AltProduto();
		break;
	case '3':
		//RemProduto();
		break;
	case '9': // Voltar
		MenuGerenciamento();
		break;
	case '0': // Sair
		centerText(RED "\nVOCÊ ESCOLHEU SAIR...", cmd_dimension.columns + 4);
		Sleep(2000);
		exit(0);
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW "(DE 1 a 5)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU", WHITE, cmd_dimension.columns + 12);
		system("pause");
		goto inicio;
	}
}