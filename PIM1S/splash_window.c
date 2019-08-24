
#include "splash_window.h"
#include "cmd_resolution.h"
#include "util.h"

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

	centerText("SISTEMA GERENCIADOR DE PIZZARIA v1.0", cmd_dimension.columns);
	char message[65] = "PRESSIONE A TECLA \033[1;31mESPAÇO\033[0m PARA INICIAR UM NOVO TURNO";
	centerText(message, cmd_dimension.columns + 10);

	for (i = 0; i < (cmd_dimension.rows / 2 - 3); i++) {
		printf("\n");
	}

	bottomLines();

	system("pause >nul");
}