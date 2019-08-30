#include <stdio.h>
#include <string.h>

#include "login_window.h"
#include "util.h"
#include "funcionario_library.h"
#include "menu_principal.h"

char usuario;
char senha;
int opcao;

void login_window() {
	system(CLEAR_SCREEN_PROGRAM);
	topLines();
	printf("\n\n");
	centerText("REGISTRAR-SE - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE SEU USUÁRIO: ");
	(void)scanf("%s", usuario);

	printf("DIGITE SUA SENHA: ");
	(void)scanf("%s", senha);

	if (LoginFuncionario(usuario, senha)) {
		// Login realizado com sucesso!
	}
	else {
		/*  Falha: verifique seus dados.
		*   Para alterar a senha digite: 1.
		*	Para voltar ao menu digite : 2
		*/
		(void)scanf("%i", &opcao);

		switch (opcao)
		{
		case 1:
			// alterar senha
			break;
		case 2:
			menu_principal();
			break;
		}
	}

	system("pause");    
}	