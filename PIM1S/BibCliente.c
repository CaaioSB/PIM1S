#include "main.h"
#include "util.h"

struct Cliente {
	char nome_completo[1024];
	char telres[1024];
	char telcel[1024];
	char cpf[1024];
	char cep[1024];
};

static bool CadastrarCliente(char nome_completo[100], char telres[15], char telcel[16], char cpf[11], char cep[10]) {
	int id = (int)ContarClientes() + 1;
	FILE* file;
	if (id == 1) {
		file = fopen(tb_cliente, "w");
		fprintf(file, "%d;%s;%s;%s;%s;%s;\n", id, nome_completo, telres, telcel, cpf, cep);
		fclose(file);
		return true;
	}
	else {
		file = fopen(tb_cliente, "a");
		fprintf(file, "%d;%s;%s;%s;%s;%s;\n", id, nome_completo, telres, telcel, cpf, cep);
		fclose(file);
		return true;
	}
}

static int ContarClientes() {
	int numLinhas = 0;
	char line[1024];
	FILE* file;
	file = fopen(tb_cliente, "r");

	if (file == NULL) {
		return 0;
	}

	while (fgets(line, sizeof line, file) != NULL) {
		numLinhas++;
	}
	fclose(file);
	return numLinhas;
}