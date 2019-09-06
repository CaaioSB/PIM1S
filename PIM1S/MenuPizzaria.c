#include "MenuPizzaria.h"
#include "util.h"

void mostrarMenuPrincipal() {
	system(CLEAR_SCREEN_PROGRAM);
	topLines();
	printf("\n\n");
	centerText("MENU PRINCIPAL - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

		
	printf("1 - Novo Pedido");
	printf("\n2 - Cadastrar Cliente");
	printf("\n3 - ");
	printf("\n4 - Gerenciamento");
	printf("\n5 - ");

	bottomLines();
}