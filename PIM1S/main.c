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
#include "menu_principal.h"

// MENSSAGEM DE ERRO
#define ERROR_INTERNAL "ERRO FATAL: Contate o desenvolvedor do sistema para mais explicações"

// CONSTANTES
static char title[25] = "SISTEMA DE PIZZARIA v1.0";

int i;

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
		menu_principal();
	}
	else {
		return 0;
	}

	system("pause >nul");
	return 1;
}