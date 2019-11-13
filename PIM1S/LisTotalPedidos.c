#include "BibFinanceiro.h"
#include "util.h"

void LisTotalPedidos() {
	int nota = 0;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "LISTAR TOTAL DE PEDIDOS - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(WHITE "ATÉ O MOMENTO FOI ARRECADADO " WHITE);
	ListarTotalPedido();
	centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
	system("pause >nul");
	menuFinanceiro();
}