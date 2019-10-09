#include "MenuInicial.h"
#include "util.h"
#include "Login.h"
#include "BibFuncionario.h"

int i;

void menuPrincipal() {
	char op;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU INICIAL - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 11);

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(YELLOW "      MENU\n" RESET);
	printf(GREEN "1" RESET " FAZER LOGIN\n");
	printf(GREEN"2" RESET " REGISTRAR-SE\n");
	printf(GREEN"3" RESET " ESQUECI MINHA SENHA\n");
	printf(RED "0" RESET " SAIR\n");
	op = _getch();

	switch (op)
	{
	case '1':
		Login();
		break;
	case '2':
		if (ContarFuncionarios() >= 1) {
			printf("\n\n");
			centerText(RED "VOC� N�O PODE REGISTRAR UM NOVO FUNCION�RIO, J� EXISTE UM GERENTE CADASTRADO." RESET, cmd_dimension.columns + 10);
			centerText(YELLOW "PRESSIONE QUALQUER TECLA PARA VOLTAR" RESET, cmd_dimension.columns + 13);
			system("pause > nul");
			goto inicio;
		}
		else {
			CadFuncionario();
		}
		goto inicio;
	case '3':
		esqueciMinhaSenha();
	case '0':
		exit(0);
		break;
	default:
		centerText(RED "VOC� DEVE SELECIONAR UMA OP��O V�LIDA" YELLOW " (DE 1 A 3 ou 0)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" RESET, cmd_dimension.columns + 12);
		system("pause > nul");
		goto inicio;
	}
	system("pause > nul");
}