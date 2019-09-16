#include "RegCliente.h"
#include "util.h"

void RegCiente() {
	system(CLEAR_SCREEN_PROGRAM);
	topLines();
	centerText("SISTEMA GERENCIADOR DE PIZZARIA - CADASTRAR CLIENTE", cmd_dimension.columns);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	int op = 0;

	while (op <> 4) {
		printf("----MENU----");
		printf("1 - Cadastrar Cliente\n2- Buscar Cliente\n3- Voltar\n4-Sair");
		(void)scanf("%d", op);

		switch (op) {
		case 1:
			cadastrarWindow();
			break;
		case 2:
			buscarWindow();
			break;
		case 3:
			menuPizaria();
		case 4:
			continue;
		}
	}

	if (op == 4) {
		exit(0);
	}
}

void cadastrarWindow() {

}

void buscarWindow() {
}