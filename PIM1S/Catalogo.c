#include "NovoPedido.h"
#include "util.h"

void MostrarCatalogo() {
	system(CLEAR_SCREEN_PROGRAM);
	printf("\n\n");
	centerText(BOLDMAGENTA "CATÁLOGO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}
}