#include "BibFuncionario.h"
#include "AltFuncionario.h"
#include "util.h"

void AltFuncionario() {
	char opcao;
	int alt;
inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "SELECIONE UM FUNCIONÁRIO\n" RESET);
	ListarFuncionarios();
	opcao = _getch();
	//opcao = _getch();

	BuscarFuncionario(opcao);
opc:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}
	printf("O QUE VOCÊ DESEJA ALTERAR?");
	setbuf(stdin, NULL);
	printf(GREEN "\n1 " RESET "NOME");
	printf(GREEN "\n2 " RESET "EMAIL");
	printf(GREEN "\n3 " RESET "RG");
	printf(GREEN "\n4 " RESET "CPF");
	printf(GREEN "\n5 " RESET "CEP");
	printf(GREEN "\n6 " RESET "USUÁRIO");
	printf(GREEN "\n7 " RESET "SENHA");
	printf(GREEN "\n8 " RESET "CARGO");
	printf(YELLOW "\n9 " RESET "CONFIRMAR");
	printf(RED "\n0 " RESET "CANCELAR\n");
	alt = _getch();

	switch (alt)
	{
	case '1':
		printf("DIGITE O NOVO NOME: " RED "(NOME ANTIGO: %s%s", nomeFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%[^\n]s", nomeFuncionario);
		goto opc;
	case '2':
		printf("DIGITE O NOVO EMAIL: " RED "(EMAIL ANTIGO: %s%s", emailFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", emailFuncionario);
		goto opc;
	case '3':
		printf("DIGITE O NOVO RG: " RED "(RG ANTIGO: %s%s", rgFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", rgFuncionario);
		goto opc;
	case '4':
		printf("DIGITE O NOVO CPF: " RED "(CPF ANTIGO: %s%s", cpfFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", cpfFuncionario);
		goto opc;
	case '5':
		printf("DIGITE O NOVO CEP: " RED "(CEP ANTIGO: %s%s", cepFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", cepFuncionario);
		goto opc;
	case '6':
		printf("DIGITE O NOVO USUÁRIO: " RED "USUÁRIO ANTIGO: %s%s", userFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", userFuncionario);
		goto opc;
	case '7':
		printf("DIGITE A NOVA SENHA: " RED "SENHA ANTIGA: %s%s", passFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", passFuncionario);
		goto opc;
	case '8':
		printf("DIGITE A NOVA FUNÇÃO: " RED "FUNÇÃO ANTIGA: %s%s", funcaoFuncionario, ")\n" RESET);
		setbuf(stdin, NULL);
		(void)scanf("%s", funcaoFuncionario);
		goto opc;
	case '9':
		// CHAMA O MÉTODO PARA CONFIRMAR
		AlterarFuncionario(opcao, nomeFuncionario, emailFuncionario, rgFuncionario, cpfFuncionario, cepFuncionario, userFuncionario, passFuncionario, funcaoFuncionario);
		break;
	case '0':
		centerText(RED "VOCÊ CANCELOU AS ALTERAÇÕES, VOLTANDO AO MENU" RESET, cmd_dimension.columns + 10);
		MenuFuncionario();
	default:
		centerText(RED "SELECIONE UMA OPÇÃO VÁLIDA " YELLOW "(DE 1 A 9)" RESET, cmd_dimension.columns + 18);
		goto inicio;
		break;
	}
	system("pause > nul");
}

