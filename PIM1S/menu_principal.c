#include "menu_principal.h"
#include "util.h"

int i;

void menu_principal() {
	int op;

	system(CLEAR_SCREEN_PROGRAM);
	topLines();
	printf("\n\n");
	centerText("MENU - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("1 - FAZER LOGIN\n");
	printf("2 - REGISTRAR-SE\n");
	printf("3 - ESQUECI MINHA SENHA\n");
	printf("4 - SAIR\n");
	printf("ESCOLHA UMA OP��O DESEJADA: \n");

	scanf_s("%d", &op);

	switch (op)
	{
	case 1:
		break;
	case 2:
		register_window();
		break;
	case 3:
		break;
	case 4:
		exit(0);
		break;
	}
	system("pause >nul");
}