#include "cmd_resolution.h"
#include "util.h"
#include "BibCliente.h"
#include "MenuInicial.h"

bool CadCliente() {
	int i = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "CADASTRAR CLIENTE - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE O NOME COMPLETO: ");
	setbuf(stdin, NULL);
	(void)scanf(" %[^\n]s", BCliente.nome_completo);

	printf("DIGITE O TELEFONE RESIDENCIAL: ");
	setbuf(stdin, NULL);
	(void)scanf(" %[^\n]s", BCliente.telres);

	printf("DIGITE O TELEFONE CELULAR: ");
	setbuf(stdin, NULL);
	(void)scanf(" %[^\n]s", BCliente.telres);

	printf("DIGITE SEU CPF: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", BCliente.cpf);

	printf("DIGITE SEU CEP: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", BCliente.cep);

	if (CadastrarCliente(BCliente.nome_completo, BCliente.telres, BCliente.telcel, BCliente.cpf, BCliente.cep))
	{
		centerText(GREEN "O CLIENTE FOI CADASTRADO COM SUCESSO!" RESET, cmd_dimension.columns + 12);
		Sleep(2000);
		return true;
	}
	else
	{
		centerText(RED "O CLIENTE NÃO FOI CADASTRADO!" RESET, cmd_dimension.columns + 10);
		Sleep(2000);
		return false;
	}
}