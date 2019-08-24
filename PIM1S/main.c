#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>

#include "util.h"
#include "funcionario_library.h"
#include "splash_window.h"
#include "register_window.h"

// MENSSAGEM DE ERRO
#define ERROR_INTERNAL "ERRO FATAL: Contate o desenvolvedor do sistema para mais explicações"

// CONSTANTES
static char title[25] = "SISTEMA DE PIZZARIA v1.0";

struct LOGIN {
	char usuario[1024];
	char senha[1024];
};

int i;

void principal_menu() {
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
	printf("ESCOLHA UMA OPÇÃO DESEJADA: \n");

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

int main() {
	setlocale(LC_ALL, "Portuguese");

	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);

	// Primeiro obtém o tamanho da janela CMD - será utilizada para construir os menus 
	if (!get_cmd_dimension()) {
		printf(ERROR_INTERNAL);
		return 0;
	}
	splash_window();

	if (GetKeyState(VK_SPACE) && 0x8000) {
		principal_menu();
	}
	else {
		return 0;
	}

	system("pause >nul");
	return 1;
}

struct LOGIN login;

static void login_window() {
	printf("Usuário: ");
	(void)scanf("%s", login.usuario);

	printf("Senha: ");
	(void)scanf("%s", login.senha);
}