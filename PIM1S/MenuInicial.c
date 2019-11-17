#include "MenuInicial.h"
#include "util.h"
#include "Login.h"
#include "BibFuncionario.h"

void menuPrincipal() {
	int i;
	char op;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BLUE "MENU INICIAL - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 11);

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(YELLOW "      MENU\n" WHITE);
	printf(GREEN "1" WHITE " FAZER LOGIN\n");
	printf(GREEN"2" WHITE " REGISTRAR-SE\n");
	printf(RED "3" RED " ESQUECI MINHA SENHA\n");
	printf(RED "0" WHITE " SAIR\n");
	op = _getch();

	switch (op)
	{
	case '1':
		Login();
		break;
	case '2':
		if (ContarFuncionarios() >= 1) {
			printf("\n\n");
			centerText(RED "VOCÊ NÃO PODE REGISTRAR UM NOVO FUNCIONÁRIO, JÁ EXISTE UM GERENTE CADASTRADO." WHITE, cmd_dimension.columns + 10);
			centerText(YELLOW "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 13);
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
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA" YELLOW " (DE 1 A 3 ou 0)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto inicio;
	}
	system("pause > nul");
}