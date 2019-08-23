#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>

// MENSSAGEM DE ERRO
#define ERROR_INTERNAL "ERRO FATAL: Contate o desenvolvedor do sistema para mais explicações"

// LIMPAR A TELA
#define CLEAR_SCREEN_PROGRAM "cls"

// FUNÇÃO PARA ARMAZENAR O TAMANHO DO MS-Windows
struct CMD_DIMENSION {
	int rows;
	int columns;
};

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