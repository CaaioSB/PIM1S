#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Login.h"
#include "util.h"
#include "BibFuncionario.h"
#include "MenuInicial.h"
//#include "main.h"

#define SIZE 1024

char usuario[SIZE];
char senha[SIZE];
int opcao;

void Login() {
	system(CLEAR_SCREEN_PROGRAM);
	centerText(YELLOW "REGISTRAR-SE - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns + 8);
	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(YELLOW "      LOGIN\n" RESET);
	printf("DIGITE SEU USUÁRIO: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", &usuario);

	printf("DIGITE SUA SENHA: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", &senha);
	
	if (LoginFuncionario(usuario, senha)) {
		menuPizzaria();
	}
	else {
		printf("\n\n");
		centerText(RED "ESTE LOGIN NÃO É VALIDO" RESET, cmd_dimension.columns + 4);
		Sleep(2000);
		menuPrincipal();
	}
	system("pause");
}

void esqueciMinhaSenha() {

}