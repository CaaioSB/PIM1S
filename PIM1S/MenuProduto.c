#include "MenuProduto.h"
#include "util.h"

void MenuProduto() {
	int opcao;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText("MENU PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1 " RESET "CADASTRAR PRODUTO\n");
	printf(GREEN "2 " RESET "ALTERAR PRODUTO\n");
	printf(GREEN "3 " RESET "REMOVER PRODUTO\n");
	printf(YELLOW "4 " RESET "VOLTAR\n");
	printf(RED "5 " RESET "SAIR\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		setbuf(stdin, NULL);
		CadProduto();
		break;
	case '2':
		//AltProduto();
		break;
	case '3':
		//RemProduto();
		break;
	case '4':
		MenuGerenciamento();
		break;
	case '5':
		centerText("\nVOCÊ ESCOLHEU SAIR...", cmd_dimension.columns);
		Sleep(2000);
		exit(0);
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW "(DE 1 a 5)" RESET, cmd_dimension.columns);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU", RESET, cmd_dimension.columns);
		system("pause");
		goto inicio;
	}
}