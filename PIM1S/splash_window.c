
#include "splash_window.h"
#include "cmd_resolution.h"
#include "util.h"

int i;
// FUNÇÃO PARA MOSTRAR A TELA DE SPLASH (INTRODUÇÃO)
void splash_window()
{

	// LIMPA O CONSOLE
	system(CLEAR_SCREEN_PROGRAM);

	//topLines();

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	centerText(RED "SISTEMA GERENCIADOR DE PIZZARIA v1.0", cmd_dimension.columns);
	char message[79] = YELLOW "PRESSIONE A TECLA " WHITE "ESPAÇO " YELLOW "PARA INICIAR UM NOVO TURNO" RESET;
	centerText(message, cmd_dimension.columns + 19);

	for (i = 0; i < (cmd_dimension.rows / 2 - 3); i++) {
		printf("\n");
	}

	//bottomLines();

	system("pause >nul");
}