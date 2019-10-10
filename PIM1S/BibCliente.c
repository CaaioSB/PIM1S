//#include "BibCliente.h"
//#include "main.h"
//#include "util.h"
//
//struct Cliente {
//	char nome_completo[1024];
//	char email[1024];
//	char cpf[1024];
//};
//
//static bool CadastrarCliente(char nome[100], char email[100], char cpf[11]) {
//	FILE* arquivo;
//	arquivo = AbreArquivo('g', tb_cliente);
//	int id = (int)ContarClientes() + 1;
//	fprintf(arquivo, "%d;%s;%s;%s", id, nome, email, cpf);
//	printf("\n\n");
//	FecharArquivo(arquivo);
//	Sleep(2000);
//	return true;
//}
//
//static int ContarClientes() {
//	int numLinhas = 0;
//	char line[1024];
//	FILE* arquivo;
//	arquivo = AbreArquivo('l', tb_cliente);
//
//	if (arquivo == NULL)
//		FecharArquivo(arquivo);
//	return 0;
//
//	while (fgets(line, sizeof line, arquivo) != NULL) {
//		numLinhas++;
//	}
//	FecharArquivo(arquivo);
//	return numLinhas;
//}