#include "main.h"
#include "util.h"

struct Cliente {
	char* id;
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

static char BuscarCliente(char id) {
	int numLinha = 0;
	char line[1024];
	char delimiter[] = ";";
	FILE* arquivo;
	FILE* arquivo2;
	char* palavras[50];
	int i = 0;
	char* values[9];
	char* fileLine[100];

	arquivo = fopen(tb_cliente, "r");
	//arquivo = AbreArquivo('l', tb_cliente);

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		fileLine[i] = _strdup(line);
		i++;
	}

	fclose(arquivo);
	/*
	* O NÚMERO DA LINHA É O MESMO QUE O CÓDIGO DO FUNCIONÁRIO
	* ENTÃO: SE LINHA É IGUAL A 15, O CÓDIGO DO FUNCIONÁRIO TAMBÉM SERÁ 15
	*/

	arquivo2 = fopen(tb_cliente, "r");
	//arquivo2 = AbreArquivo('l', tb_cliente);

	if (arquivo2 == NULL)
		return EXIT_FAILURE;

	while (fgets(dadosCliente, sizeof dadosCliente, arquivo2) != NULL)
	{
		palavras[numLinha] = _strdup(dadosCliente);
		if (dadosCliente[0] == id)
		{
			int j = 0;
			while (j < 1) {
				char* ptr = strtok(palavras[numLinha], delimiter);
				values[j] = ptr;
				j++;
				while (ptr != NULL && j < 9)
				{
					// Imprime os dados lidos do documento de texto
					//printf("'%s'\n", ptr);
					ptr = strtok(NULL, delimiter);
					values[j] = ptr;
					j++;
				}
			}
			// PEGANDO OS DADOS DO FUNCIONÁRIO REQUERIDO
			idCliente = values[0];
			strcpy(nomeCliente, values[1]);
			strcpy(telresCliente, values[2]);
			strcpy(telcelCliente, values[3]);
			strcpy(cpfCliente, values[4]);
			strcpy(cepCliente, values[5]);
			FecharArquivo(arquivo2);
			break;
		}
		numLinha++;
	}
	FecharArquivo(arquivo2);
}

static bool ListarClientes() {
	struct Cliente Clientes;
	int x = 0;
	int j = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	char* values[5];
	char delimiter[] = ";";
	FILE* arquivo;

	arquivo = fopen(tb_cliente, "rt");

	if (arquivo == NULL) {
		return EXIT_FAILURE;
	}

	printf(GREEN "%-15s" GREEN "%-32s" GREEN "%-0s\n" GREEN, "ID", "NOME DO CLIENTE", "TELEFONE CELULAR");
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
		Clientes.id = values[0];
		strcpy(Clientes.nome_completo, values[1]);
		strcpy(Clientes.telcel, values[2]);
		printf(WHITE "%-14s " WHITE "%-32s" WHITE "%-0s\n" RESET, Clientes.id, Clientes.nome_completo, Clientes.telcel);
		j = 0;
		x++;
		//Conta a quantidade de linhas
		numLinhas++;
	}
	fclose(arquivo);
	return true;
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