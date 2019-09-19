#include "BibFuncionario.h"
#include "AltFuncionario.h"
#include "util.h"

void AltFuncionario() {
	int opcao;
	//inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText("ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(YELLOW "SELECIONE UM FUNCIONÁRIO\n" RESET);
	ListarFuncionarios();
	opcao = _getch();

	char* teste = {""};

	teste[0] = BuscarFuncionario(1);

	printf("%s", teste[0]);
	system("pause > nul");
}

