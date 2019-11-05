#include "BibFeedback.h"
#include "util.h"

void LisFeedback() {
	int nota = 0;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "CADASTRAR FEEDBACK - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "FEEDBACKS CADASTRADOS " WHITE);
	printf(BLUE "SENDO QUE: " WHITE);
	printf(BOLDRED "1" WHITE " MUITO INSATISFEITO ");
	printf(RED "2" WHITE " INSATISFEITO ");
	printf(YELLOW "3" WHITE " INDIFERENTE ");
	printf(GREEN "4" WHITE " SATISFEITO ");
	printf(BOLDGREEN "5" WHITE " MUITO SATISFEITO\n\n");
	ListarFeedbacks();

	system("pause >nul");
	menuFeedback();
}