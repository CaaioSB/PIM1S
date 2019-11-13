#include "BibProduto.h"
#include "NovoPedido.h"
#include "util.h"

void MostrarCatalogo() {
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "CATÁLOGO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	if (ListarProdutosCategoria()) {
		centerText(GREEN "APERTE QUALQUER TECLA PARA VOLTAR AO MENU DA PIZZARIA" WHITE, cmd_dimension.columns + 12);
		system("pause >nul");
		menuPizzaria();
	}
	else {
		centerText(RED "\nHOUVE UM PROBLEMA AO MOSTRAR O CATÁLOGO, VOLTANDO AO MENU..." WHITE, cmd_dimension.columns + 10);
		Sleep(2000);
		menuPizzaria();
	}
}