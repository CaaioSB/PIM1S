#include "MenuInicial.h"
#include "util.h"
#include "Login.h"
#include "BibFuncionario.h"

int i;

void menuPrincipal() {
	char op;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(YELLOW "MENU - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns + 8);

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
			centerText(RED "VOCÊ NÃO PODE REGISTRAR UM NOVO FUNCIONÁRIO, JÁ EXISTE UM GERENTE CADASTRADO." RESET, cmd_dimension.columns + 10);
			centerText(YELLOW "PRESSIONE QUALQUER TECLA PARA VOLTAR" RESET, cmd_dimension.columns + 12);
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
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW "(DE 1 A 5)" RESET, cmd_dimension.columns);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" RESET, cmd_dimension.columns);
		system("pause > nul");
		goto inicio;
	}

	system("pause > nul");
}