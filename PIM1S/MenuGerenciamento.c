#include "MenuGerenciamento.h"
#include "util.h"

void MenuGerenciamento() {
	int opcao;
	inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "GERENCIAMENTO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 11);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(GREEN "1" WHITE " FUNCIONARIO\n");
	printf(GREEN "2" WHITE " CLIENTE\n");
	printf(GREEN "3" WHITE " PRODUTO\n");
	printf(GREEN "4" WHITE " PEDIDOS\n");
	printf(GREEN "5" WHITE " FINANCEIRO\n");
	printf(GREEN "7" WHITE " PROMOÇÃO\n");
	printf(YELLOW "9" WHITE " VOLTAR\n");
	printf(RED "0" WHITE " SAIR\n");
	opcao = _getch();

	switch (opcao)
	{
	case '1':
		MenuFuncionario();
		break;
	case '2':
		MenuCliente();
		break;
	case '3':
		MenuProduto();
		break;
	case '4':
		MenuPedido();
		break;
	case '5':
		menuFinanceiro();
		break;
	case '7':
		menuDesconto();
		centerText(GREEN "PROMOÇÃO CADASTRADA!" WHITE, cmd_dimension.columns + 12);
		Sleep(3000);
		goto inicio;
	case '9':
		menuPizzaria();
	case '0':
		centerText(RED "\nVOCÊ ESCOLHEU SAIR...", cmd_dimension.columns + 4);
		Sleep(2000);
		exit(0);
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW "(DE 1 A 5)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" WHITE, cmd_dimension.columns + 12);
		Sleep(2000);
		goto inicio;
		system("pause > nul");
	}
}