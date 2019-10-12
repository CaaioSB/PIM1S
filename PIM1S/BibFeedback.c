#include <stdbool.h>
//#include "BibFeedback.h"
#include "stdio.h"
#include "main.h"


struct FEEDBACK {
	char nome_cliente[1024];
	char feedback[1024];
	int nota[1024];
};

static bool CadastarFeedback(char nome_cliente[30], char feedback[1024], int nota) {
	FILE* arquivo;
	arquivo = AbreArquivo('g', tb_feedback);
	fprintf(arquivo, "%s;%s;%i", nome_cliente, feedback, nota);
	printf("\n\n");
	FecharArquivo(arquivo);
	return true;
}