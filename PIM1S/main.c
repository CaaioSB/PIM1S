#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include "main.h"

// LIMPAR A TELA
#define CLEAR_SCREEN_PROGRAM "cls"

// MENSSAGEM DE ERRO
#define ERROR_INTERNAL "ERRO FATAL: Contate o desenvolvedor do sistema para mais explicações"

// FUNÇÕES PARA ALTERAR AS CORES
void red() {
	printf("\033[1;31m");
}

void yellow() {
	printf("\033[1;33m");
}

void reset() {
	printf("\033[0m");
}

// CONSTANTES
char title[25] = "SISTEMA DE PIZZARIA v1.0";

// FUNÇÃO PARA ARMAZENAR O TAMANHO DO MS-Windows
struct CMD_DIMENSION {
	int rows;
	int columns;
};

struct CMD_DIMENSION cmd_dimension;

// FUNÇÃO PARA OBTER AS DIMENSÕES DA JANELA CMD
// API DO MS-Windows
int get_cmd_dimension() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	BOOL status;

	DWORD error_code;

	LPVOID message;

	status = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (!status) { // CASO O RETORNO FOR IGUAL A 0, A FUNÇÃO NÃO FOI EXECUTADA CORRETAMENTE
		error_code = GetLastError();
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			status,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)& message,
			0,
			NULL);
		//log((LPSTR)message);
		LocalFree(message);

		return 0;
	}

	cmd_dimension.columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	cmd_dimension.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return 1;
}

void centerText(char* text, int fieldWidth) {
	int padlen = (fieldWidth - strlen(text)) / 2;
	printf("% *s % s % *s\n", padlen, "", text, padlen, "");
}

int i;
// FUNÇÃO PARA MOSTRAR A TELA DE SPLASH (INTRODUÇÃO)
void splash_window()
{

	// LIMPA O CONSOLE
	system(CLEAR_SCREEN_PROGRAM);

	topLines();

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}
	
	centerText("SISTEMA DE PIZZARIA v1.0", cmd_dimension.columns);
	char message[65] = "PRESSIONE A TECLA \033[1;31mESPAÇO\033[0m PARA INICIAR UM NOVO TURNO";
	centerText(message, cmd_dimension.columns + 10);

	for (i = 0; i < (cmd_dimension.rows / 2 - 3); i++) {
		printf("\n");
	}

	bottomLines();

	system("pause >nul");
}

// FUNÇÃO PARA FAZER LINHAS COLORIDAS SUPERIORES
void topLines()
{
	for (i = 0; i < cmd_dimension.columns; i++) {
		red();
		printf("_");
		yellow();
		printf("_");
		reset();
	}
}

// FUNÇÃO PARA FAZER LINHAS COLORIDAS INFERIORES
void bottomLines()
{
	for (i = 0; i < cmd_dimension.columns; i++) {
		yellow();
		printf("_");
		red();
		printf("_");
		reset();
	}
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

	system("pause >nul");
	return 1;
}
