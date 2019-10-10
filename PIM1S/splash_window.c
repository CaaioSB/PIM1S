#include "splash_window.h"
#include "cmd_resolution.h"
#include "util.h"

int i;
// FUN��O PARA MOSTRAR A TELA DE SPLASH (INTRODU��O)
void splash_window()
{

	// LIMPA O CONSOLE
	system(CLEAR_SCREEN_PROGRAM);

	//topLines();

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	centerText(BLUE "PIZZABUG GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 10);
	centerText("PRESSIONE A TECLA" BOLDMAGENTA " ESPA�O " RESET "PARA INICIAR UM NOVO TURNO", cmd_dimension.columns + 11);

	for (i = 0; i < (cmd_dimension.rows / 2 - 3); i++) {
		printf("\n");
	}

	//bottomLines();

	system("pause >nul");
}