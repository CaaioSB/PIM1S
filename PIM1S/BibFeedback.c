#include "main.h"
#include "util.h"

struct FEEDBACK {
	char nome_cliente[1024];
	char nota[1024];
};

static bool CadastarFeedback(char nome_cliente[30], int nota) {
	int id = (int)ContarFeedbacks() + 1;
	FILE* file;
	if (id == 1) {
		file = fopen(tb_feedback, "w");
		fprintf(file, "%d;%s;%d;\n", id, nome_cliente, nota);
		printf("\n\n");
		fclose(file);
		return true;
	}
	else {
		file = fopen(tb_feedback, "a");
		fprintf(file, "%d;%s;%d;\n", id, nome_cliente, nota);
		printf("\n\n");
		fclose(file);
		return true;
	}
}

static bool ListarFeedbacks() {
	int x = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	FILE* arquivo;

	arquivo = AbreArquivo('l', tb_feedback);

	if (arquivo == NULL)
		return EXIT_FAILURE;

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras[x] = _strdup(line);
		
		printf("%s\n", palavras[x]);
		x++;

		//Conta a quantidade de linhas
		numLinhas++;
	}
	FecharArquivo(arquivo);
	return true;
}

static int ContarFeedbacks() {
	int numLinhas = 0;
	char line[1024];
	FILE* file;
	file = fopen(tb_feedback, "r");

	if (file == NULL) {
		FecharArquivo(file);
		return 0;
	}

	while (fgets(line, sizeof line, file) != NULL) {
		numLinhas++;
	}
	fclose(file);
	return numLinhas;
}