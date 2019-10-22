#include "BibFuncionario.h"
#include "AltFuncionario.h"
#include "util.h"

void AltFuncionario() {
	char opcao;
	int alt;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR FUNCION�RIO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "SELECIONE UM FUNCION�RIO\n" RESET);
	ListarFuncionarios();
	opcao = _getch();

	BuscarFuncionario(opcao);
opc:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR FUNCION�RIO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}
	printf("O QUE VOC� DESEJA ALTERAR?");
	setbuf(stdin, NULL);
	printf(GREEN "\n1 " RESET "NOME");
	printf(GREEN "\n2 " RESET "EMAIL");
	printf(GREEN "\n3 " RESET "RG");
	printf(GREEN "\n4 " RESET "CPF");
	printf(GREEN "\n5 " RESET "CEP");
	printf(GREEN "\n6 " RESET "USU�RIO");
	printf(GREEN "\n7 " RESET "SENHA");
	printf(GREEN "\n8 " RESET "CARGO");
	printf(YELLOW "\n9 " RESET "CONFIRMAR");
	printf(RED "\n0 " RESET "CANCELAR\n");
	alt = _getch();

	switch (alt)
	{
	case '1':
		printf("DIGITE O NOVO NOME: " RED "(NOME ATUAL: %s%s", nomeFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%[^\n]s", nomeFuncionario);
		goto opc;
	case '2':
		printf("DIGITE O NOVO EMAIL: " RED "(EMAIL ATUAL: %s%s", emailFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", emailFuncionario);
		goto opc;
	case '3':
		printf("DIGITE O NOVO RG: " RED "(RG ATUAL: %s%s", rgFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", rgFuncionario);
		goto opc;
	case '4':
		printf("DIGITE O NOVO CPF: " RED "(CPF ATUAL: %s%s", cpfFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", cpfFuncionario);
		goto opc;
	case '5':
		printf("DIGITE O NOVO CEP: " RED "(CEP ATUAL: %s%s", cepFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", cepFuncionario);
		goto opc;
	case '6':
		printf("DIGITE O NOVO USU�RIO: " RED "USU�RIO ATUAL: %s%s", userFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", userFuncionario);
		goto opc;
	case '7':
		printf("DIGITE A NOVA SENHA: " RED "SENHA ATUAL: %s%s", passFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", passFuncionario);
		goto opc;
	case '8':
		printf("DIGITE A NOVA FUN��O: " RED "FUN��O ATUAL: %s%s", funcaoFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", funcaoFuncionario);
		goto opc;
	case '9':
		// CHAMA O M�TODO PARA CONFIRMAR
		if (AlterarFuncionario(opcao, nomeFuncionario, emailFuncionario, rgFuncionario, cpfFuncionario, cepFuncionario, userFuncionario, passFuncionario, funcaoFuncionario)) {
			centerText(GREEN "O FUNCION�RIO FOI ALTERADO COM SUCESSO", cmd_dimension.columns - 6);

		}
		else {
			centerText(RED "OCORREU UM ERRO AO ALTERA O FUNCION�RIO", cmd_dimension.columns - 4);
		}
		Sleep(3000);
		MenuFuncionario();
	case '0':
		centerText(RED "VOC� CANCELOU AS ALTERA��ES, VOLTANDO AO MENU" RESET, cmd_dimension.columns + 10);
		MenuFuncionario();
	default:
		centerText(RED "SELECIONE UMA OP��O V�LIDA " YELLOW "(DE 1 A 0)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" RESET, cmd_dimension.columns + 12);
		system("pause >nul");
		goto opc;
	}
	system("pause > nul");
}