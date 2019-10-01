#include "BibFuncionario.h"
#include "AltFuncionario.h"
#include "util.h"

void AltFuncionario() {
	int opcao;
	int alt;
	inicio:
	system(CLEAR_SCREEN_PROGRAM);
	centerText(YELLOW "ALTERAR FUNCIONÁRIO - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(YELLOW "SELECIONE UM FUNCIONÁRIO\n" RESET);
	ListarFuncionarios();
	opcao = _getch();

	BuscarFuncionario(opcao);
	opc:
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
	pritnf(RED "\n0 " RESET "CANCELAR");
	alt = _getch();

	switch (alt)
	{
	case '1':
		printf("DIGITE O NOVO NOME: " RED "(NOME ANTIGO: %s, %s", nomeFuncionario, ")");
		(void)scanf("%[^\n]s", nomeFuncionario);
		goto opc;
	case '2':
		printf("DIGITE O NOVO EMAIL: " RED "(EMAIL ANTIGO: %s, %s", emailFuncionario, ")");
		(void)scanf("%s", emailFuncionario);
		goto opc;
	case '3':
		printf("DIGITE O NOVO RG: " RED "(RG ANTIGO: %s, %s", rgFuncionario, ")");
		(void)scanf("%s", rgFuncionario);
		goto opc;
	case '4':

		goto opc;
	case '5':
		break;
		break;
	case '6':
		break;
	case '7':
		break;
	case '8':
		break;
	case '9':
		// CHAMA O MÉTODO PARA CONFIRMAR
		break;
	case '0':
		centerText(RED "VOCÊ CANCELOU AS ALTERAÇÕES" RESET, cmd_dimension.columns + 11);
		MenuFuncionario();
	default:
		printf(RED "SELECIONE UMA OPÇÃO VÁLIDA " YELLOW "(DE 1 A 9)" RESET);
		goto inicio;
		break;
	}
	system("pause > nul");
}

// FAZER A FUNÇÃO QUE POSSIBILITA O USUÁRIO A ESCOLHER O QUE ELE DESEJA ALTERARH

