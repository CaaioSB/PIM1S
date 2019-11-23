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
char senha[4];
int opcao;

void Login() {
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "MENU LOGIN - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "      LOGIN\n" WHITE);
	printf("DIGITE SEU USUÁRIO: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", &usuario);

	printf("DIGITE SEU PIN: ");
	setbuf(stdin, NULL);
	for (int i = 0; i < 4; i++) {
		senha[i] = getch();
		putchar('*');
	}
	
	if (LoginFuncionario(usuario, senha)) {
		menuPizzaria();
	}
	else {
		menuPrincipal();
	}
	system("pause >nul");
}

void esqueciMinhaSenha() {

}