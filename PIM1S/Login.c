#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Login.h"
#include "util.h"
#include "BibFuncionario.h"
#include "MenuPrincipal.h"
#define SIZE 1024

char usuario[SIZE];
char senha[SIZE];
int opcao;

void Login() {
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
		centerText(RED "ESTE LOGIN NÃO É VALIDO" RESET, cmd_dimension.columns);
		Sleep(3000);

		(void)scanf("%i", &opcao);

		switch (opcao)
		{
		case 1:
			// alterar senha
			break;
		case 2:
			MenuPrincipal();
			break;
		}
	}
	system("pause");
}