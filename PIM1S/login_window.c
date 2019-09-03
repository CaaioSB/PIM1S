#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "login_window.h"
#include "util.h"
#include "funcionario_library.h"
#include "menu_principal.h"
#define SIZE 1024

char usuario[SIZE];
char senha[SIZE];
int opcao;

void login_window() {
	system(CLEAR_SCREEN_PROGRAM);
	topLines();
	printf("\n\n");
	centerText("REGISTRAR-SE - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE SEU USUÁRIO: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", &usuario);

	printf("DIGITE SUA SENHA: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", &senha);

	if (!LoginFuncionario(usuario, senha)) {
		(void)scanf("%i", &opcao);

		switch (opcao)
		{
		case 1:
			// alterar senha
			break;
		case 2:
			menu_principal();
			break;
		}
	}
	system("pause");
}