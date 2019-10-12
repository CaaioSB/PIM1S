#include "cmd_resolution.h"
#include "util.h"
#include "BibFeedback.h"

bool CadFeedback() {
	inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "CADASTRAR FEEDBACK - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE O NOME DO CLIENTE: ");
	setbuf(stdin, NULL);
	(void)scanf(" %[^\n]s", BFeedback.nome_cliente);

	/*
		RUIM: 1, 2 E 3,
		MÉDIO: 4, 5 E 6,
		BOM: 7, 8, 9 E 10.
	*/

	printf("DIGITE UMA NOTA DE 0 A 10 SENDO QUE: ");
	printf(RED "1" RESET " HORRÍVEL, O PEDIDO NÃO VEIO DE ACORDO COM MINHAS EXPECTATIVAS!\n");
	printf(RED "2" RESET " O PEDIDO\n");
	printf(RED "3" RESET " \n");
	printf(YELLOW "4" RESET " \n");
	printf(YELLOW "5" RESET " \n");
	printf(YELLOW "6" RESET " \n");
	printf(GREEN "7" RESET " \n");
	printf(GREEN "8" RESET " \n");
	printf(GREEN "9" RESET " \n");
	printf(BOLDGREEN "10" RESET " \n");
	setbuf(stdin, NULL);
	(void)scanf("%i", BFeedback.nota);

	if (BFeedback.nota > 10 || BFeedback.nota < 0) {
		centerText(RED "A NOTA DEVE SER MAIOR QUE 0 E MENOR QUE 10, RETORNANDO AO CADASTRO..." RESET, cmd_dimension.columns + 10);
		Sleep(2000);
		goto inicio;
	}
	else if (sizeof(BFeedback.feedback) > 1024)
	{
		centerText(RED "O FEEDBACK DEVE CONTER NO MÁXIMO 1024 LETRAS, RETORNANDO AO CADASTRO..." RESET, cmd_dimension.columns + 10);
		Sleep(2000);
		goto inicio;
	}
	else {
		if (CadFeedback(BFeedback.nome_cliente, BFeedback.feedback, BFeedback.nota)) {

		}
		else {

		}
	}
}