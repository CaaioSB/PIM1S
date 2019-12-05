#include "BibProduto.h"
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
	printf(GREEN "3 " WHITE "LISTAR PRODUTOS\n");
	printf(RED "4 " RED "REMOVER PRODUTO\n");
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
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "CATÁLOGO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
		{
			printf("\n");
		}
		if (ListarProdutosCategoria()) {
			centerText(GREEN "APERTE QUALQUER TECLA PARA VOLTAR AO MENU DA PIZZARIA" WHITE, cmd_dimension.columns + 12);
			system("pause >nul");
			goto inicio;
		}
		else {
			centerText(RED "\nHOUVE UM PROBLEMA AO MOSTRAR O CATÁLOGO, VOLTANDO AO MENU..." WHITE, cmd_dimension.columns + 10);
			Sleep(2000);
			goto inicio; 
		}
	case '9': // Voltar
		MenuGerenciamento();
		break;
	case '0': // Sair
		centerText(RED "\nVOCÊ ESCOLHEU SAIR...", cmd_dimension.columns + 4);
		Sleep(2000);
		exit(0);
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW "(DE 1 a 2, 9 ou 0)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU", WHITE, cmd_dimension.columns + 12);
		system("pause");
		goto inicio;
	}
}