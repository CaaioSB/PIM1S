#include "BibFuncionario.h"
#include "AltFuncionario.h"
#include "util.h"

void AltFuncionario() {
	int opcao;
	//inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(YELLOW "ALTERAR FUNCION�RIO - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(YELLOW "SELECIONE UM FUNCION�RIO\n" RESET);
	ListarFuncionarios();
	opcao = _getch();

	BuscarFuncionario(opcao);

	system("pause > nul");
}

// FAZER A FUN��O QUE POSSIBILITA O USU�RIO A ESCOLHER O QUE ELE DESEJA ALTERARH

