#include "cmd_resolution.h"
#include "util.h"
#include "funcionario_library.h"
#include "menu_principal.h"
int i;

void register_window() {
	system(CLEAR_SCREEN_PROGRAM);
	topLines();
	printf("\n\n");
	centerText("REGISTRAR-SE - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE SEU NOME COMPLETO: ");
	(void)scanf(" %[^\n]s", register_func.nome_completo);

	printf("DIGITE SEU E-MAIL: ");
	(void)scanf("%s", register_func.email);

	printf("DIGITE SEU RG: ");
	(void)scanf("%s", register_func.rg);

	printf("DIGITE SEU CPF: ");
	(void)scanf("%s", register_func.cpf);

	printf("DIGITE SEU CEP: ");
	(void)scanf("%s", register_func.cep);

	printf("DIGITE SEU USUÁRIO DE LOGIN: ");
	(void)scanf("%s", register_func.usuario);

	printf("DIGITE SUA SENHA DE LOGIN: ");
	(void)scanf("%s", register_func.senha);

	printf("\n\n");

	CadastrarFuncionario(register_func.nome_completo, register_func.email, register_func.rg, register_func.cpf, register_func.cep, register_func.usuario, register_func.senha);
	centerText("O FUNCIONÁRIO FOI CADASTRADO COM SUCESSO!", cmd_dimension.columns);

	Sleep(3000);

	menu_principal();
}
