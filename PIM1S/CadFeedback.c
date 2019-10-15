#include <string.h>

#include "BibFeedback.h"
#include "cmd_resolution.h"
#include "util.h"

bool CadFeedback() {
	int nota = 0;
	inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "CADASTRAR FEEDBACK - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE O NOME DO CLIENTE: ");
	setbuf(stdin, NULL);
	(void)scanf(" %[^\n]s", BFeedback.nome_cliente);

	printf("DIGITE UMA NOTA DE 0 A 5 SENDO QUE:\n");
	printf(BOLDRED "1" RESET " MUITO INSATISFEITO\n");
	printf(RED "2" RESET " INSATISFEITO\n");
	printf(YELLOW "3" RESET " INDIFERENTE\n");
	printf(GREEN "4" RESET " SATISFEITO\n");
	printf(BOLDGREEN "5" RESET " MUITO SATISFEITO\n");
	nota = _getch() - 48;
	if (nota < 1 || nota > 5) {
		centerText(RED "A NOTA DEVE SER MAIOR QUE 0 E MENOR QUE 5, RETORNANDO AO CADASTRO..." RESET, cmd_dimension.columns + 10);
		Sleep(2000);
		goto inicio;
	}
	else {
		if (CadastarFeedback(BFeedback.nome_cliente, nota)) {
			centerText(GREEN "O FEEDBACK FOI CADASTRADO COM SUCESSO!" RESET, cmd_dimension.columns + 12);
			Sleep(2000);
		}
		else {
			centerText(RED "O FEEDBACK NÃO FOI CADASTRADO!" RESET, cmd_dimension.columns + 10);
			Sleep(2000);
		}
	}
	menuPizzaria();
}