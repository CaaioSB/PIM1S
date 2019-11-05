#include "main.h"
#include "util.h"

struct FEEDBACK {
	char* id;
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
	struct FEEDBACK Feedback;
	int x = 0;
	int j = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	char* values[5];
	char delimiter[] = ";";
	FILE* arquivo;

	arquivo = AbreArquivo('l', tb_feedback);

	if (arquivo == NULL)
		return EXIT_FAILURE;

	printf(GREEN "%-14s " WHITE "%-32s" YELLOW "%-0s\n" WHITE, "ID", "NOME DO CLIENTE", "NOTA");
	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras[x] = _strdup(line);
		char* ptr = strtok(palavras[x], delimiter);
		values[j] = ptr;
		j++;
		while (ptr != NULL && j < 5) {
			ptr = strtok(NULL, delimiter);
			values[j] = ptr;
			j++;
		}
		Feedback.id = values[0];
		strcpy(Feedback.nome_cliente, values[1]);
		strcpy(Feedback.nota, values[2]);
		printf(GREEN "%-14s " WHITE "%-32s" YELLOW "%-0s\n" WHITE, Feedback.id, Feedback.nome_cliente, Feedback.nota);
		j = 0;
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

	return numLinhas;
}