#include "BibFeedback.h"
#include "util.h"

void LisFeedback() {
	int nota = 0;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "CADASTRAR FEEDBACK - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "FEEDBACKS CADASTRADOS " RESET);
	printf(BLUE "SENDO QUE: " RESET);
	printf(BOLDRED "1" RESET " MUITO INSATISFEITO ");
	printf(RED "2" RESET " INSATISFEITO ");
	printf(YELLOW "3" RESET " INDIFERENTE ");
	printf(GREEN "4" RESET " SATISFEITO ");
	printf(BOLDGREEN "5" RESET " MUITO SATISFEITO\n");
	ListarFeedbacks();

	system("pause >nul");
	menuFeedback();
}