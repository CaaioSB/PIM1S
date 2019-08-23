

// LIMPAR A TELA
#define CLEAR_SCREEN_PROGRAM "cls"

struct REGISTER {
	char nome_completo[1024];
	char email[1024];
	char rg[1024];
	char cpf[1024];
	char cep[1024];
	char usuario[1024];
	char senha[1024];
};

struct REGISTER register_func;
int i = 0;
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

	CadastrarFuncionario(register_func.nome_completo, register_func.email, register_func.rg, register_func.cpf, register_func.cep, register_func.usuario, register_func.senha);

	for (i = 0; i < (cmd_dimension.rows / 2 - 4); i++) {
		printf("\n");
	}

	bottomLines();

	system("pause >nul");
}