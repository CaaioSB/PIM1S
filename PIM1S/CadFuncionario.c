#include "cmd_resolution.h"
#include "util.h"
#include "BibFuncionario.h"
#include "MenuInicial.h"

bool CadFuncionario() {
	int i = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "CADASTRAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE O NOME COMPLETO: ");
	setbuf(stdin, NULL);
	(void)scanf(" %[^\n]s", BFuncionario.nome_completo);

	printf("DIGITE SEU E-MAIL: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", BFuncionario.email);

	setbuf(stdin, NULL);
	printf("DIGITE SEU RG: ");
	(void)scanf("%s", BFuncionario.rg);

	printf("DIGITE SEU CPF: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", BFuncionario.cpf);

	printf("DIGITE SEU CEP: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", BFuncionario.cep);

	printf("DIGITE SEU USUÁRIO DE LOGIN: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", BFuncionario.usuario);

	printf("DIGITE SUA SENHA DE LOGIN: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", BFuncionario.senha);

	printf("\n\n");

	printf("DIGITE A FUNÇÃO DO FUNCIONARIO: ");
	setbuf(stdin, NULL);
	(void)scanf("%s", BFuncionario.funcao);

	if (CadastrarFuncionario(BFuncionario.nome_completo, BFuncionario.email, BFuncionario.rg, BFuncionario.cpf, BFuncionario.cep, BFuncionario.usuario, BFuncionario.senha, BFuncionario.funcao)) {
		centerText(GREEN "O FUNCIONÁRIO FOI CADASTRADO COM SUCESSO!" RESET, cmd_dimension.columns + 12);
		Sleep(2000);
		return true;
	}
	else {
		centerText(RED "O FUNCIONÁRIO NÃO FOI CADASTRADO!" RESET, cmd_dimension.columns + 10);
		Sleep(2000);
		return false;
	}
}