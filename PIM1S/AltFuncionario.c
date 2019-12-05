#include "BibFuncionario.h"
#include "AltFuncionario.h"
#include "util.h"

void AltFuncionario() {
	char opcao;
	int alt;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "SELECIONE UM FUNCIONÁRIO\n" WHITE);
	ListarFuncionarios();
	opcao = _getch();

	BuscarFuncionario(opcao);
opc:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}
	printf("O QUE VOCÊ DESEJA ALTERAR?");
	setbuf(stdin, NULL);
	printf(GREEN "\n1 " WHITE "NOME");
	printf(GREEN "\n2 " WHITE "EMAIL");
	printf(GREEN "\n3 " WHITE "RG");
	printf(GREEN "\n4 " WHITE "CPF");
	printf(GREEN "\n5 " WHITE "CEP");
	printf(GREEN "\n6 " WHITE "USUÁRIO");
	printf(GREEN "\n7 " WHITE "SENHA");
	printf(GREEN "\n8 " WHITE "CARGO");
	printf(YELLOW "\n9 " WHITE "CONFIRMAR");
	printf(RED "\n0 " WHITE "CANCELAR\n");
	alt = _getch();

	switch (alt)
	{
	case '1':
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
			printf("\n");
		}
		printf("DIGITE O NOVO NOME: " RED "(NOME ATUAL: %s%s", nomeFuncionario, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%[^\n]s", nomeFuncionario);
		goto opc;
	case '2':
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
			printf("\n");
		}
		printf("DIGITE O NOVO EMAIL: " RED "(EMAIL ATUAL: %s%s", emailFuncionario, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%s", emailFuncionario);
		goto opc;
	case '3':
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
			printf("\n");
		}
		printf("DIGITE O NOVO RG: " RED "(RG ATUAL: %s%s", rgFuncionario, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%s", rgFuncionario);
		goto opc;
	case '4':
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
			printf("\n");
		}
		printf("DIGITE O NOVO CPF: " RED "(CPF ATUAL: %s%s", cpfFuncionario, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%s", cpfFuncionario);
		goto opc;
	case '5':
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
			printf("\n");
		}
		printf("DIGITE O NOVO CEP: " RED "(CEP ATUAL: %s%s", cepFuncionario, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%s", cepFuncionario);
		goto opc;
	case '6':
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
			printf("\n");
		}
		printf("DIGITE O NOVO USUÁRIO: " RED "USUÁRIO ATUAL: %s%s", userFuncionario, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%s", userFuncionario);
		goto opc;
	case '7':
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
			printf("\n");
		}
		printf("DIGITE A NOVA SENHA:" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%s", passFuncionario);
		goto opc;
	case '8':
		system(CLEAR_SCREEN_PROGRAM);
		centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

		for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
			printf("\n");
		}
		printf("DIGITE A NOVA FUNÇÃO: " RED "FUNÇÃO ATUAL: %s%s", funcaoFuncionario, ")\n" WHITE);
		setbuf(stdin, NULL);
		(void)scanf("%s", funcaoFuncionario);
		goto opc;
	case '9':
		// CHAMA O MÉTODO PARA CONFIRMAR
		if (AlterarFuncionario(opcao, nomeFuncionario, emailFuncionario, rgFuncionario, cpfFuncionario, cepFuncionario, userFuncionario, passFuncionario, funcaoFuncionario)) {
			centerText(GREEN "O FUNCIONÁRIO FOI ALTERADO COM SUCESSO", cmd_dimension.columns - 6);

		}
		else {
			centerText(RED "OCORREU UM ERRO AO ALTERA O FUNCIONÁRIO", cmd_dimension.columns - 4);
		}
		Sleep(3000);
		MenuFuncionario();
	case '0':
		centerText(RED "VOCÊ CANCELOU AS ALTERAÇÕES, VOLTANDO AO MENU" WHITE, cmd_dimension.columns + 10);
		MenuFuncionario();
	default:
		centerText(RED "SELECIONE UMA OPÇÃO VÁLIDA " YELLOW "(DE 1 A 0)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause >nul");
		goto opc;
	}
	system("pause > nul");
}