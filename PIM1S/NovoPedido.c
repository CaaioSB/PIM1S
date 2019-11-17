#include "util.h"
#include "main.h"
#include "BibCliente.h"
#include "BibProduto.h"
#include "BibPedido.h"

struct Pedido
{
	char* Produto[100][500];
	char Observacao[500];
	double Total;
};

void NovoPedido() {
	int opcao;
	int posicao = 1;
	//int loop = 0;
	int idProduto;
	int idCliente[5];
cliente:
	opcao = 0;
	//loop = 1;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "NOVO PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}
	printf(MAGENTA "O CLIENTE POSSUI UM CADASTRO ATIVO NA PIZZARIA?\n" WHITE);
	printf(GREEN "1" WHITE " SIM\n");
	printf(RED "2" WHITE " NÃO\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto selCliente;
	case '2':
		CadCliente();
		goto cliente;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 2)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto cliente;
	}

selCliente:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "SELECIONAR CLIENTE - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "%+47s\n" WHITE, "SELECIONE O CLIENTE PELO ID");
	ListarClientes();
	printf("\n");
	setbuf(stdin, NULL);
	(void)scanf("%i", idCliente);

	BuscarCliente(idCliente[0]);
confCliente:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "SELECIONAR CLIENTE - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}
	printf("VOCÊ ESTA FAZENDO UM NOVO PEDIDO PARA: " YELLOW "%s" WHITE "?\n", nomeCliente);
	printf(GREEN "1" WHITE " SIM\n");
	printf(RED "2" WHITE " NÃO\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto novoPedido;
	case '2':
		goto cliente;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 2)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto selCliente;
	}


novoPedido:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "NOVO PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "O QUE DESEJA FAZER?\n" WHITE);
	printf(GREEN "1" WHITE " ADICIONAR PRODUTO\n");
	printf(GREEN "2" WHITE " REMOVER PRODUTO\n");
	printf(GREEN "3" WHITE " RESUMO PEDIDO\n");
	printf(RED "9" WHITE " CANCELAR PEDIDO\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto adcProduto;
	case '2':
		goto removerProduto;
	case '3':
		goto resumoPedido;
	case '9':
		for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
			idProdutoCarrinho[prod] = NULL;
			nomeProdutoCarrinho[prod] = NULL;
			precoProdutoCarrinho[prod] = 0;
		}
		qntProdutoCarrinho = 0;
		totalProdutoCarrinho = 0;
		menuPizzaria();
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 3 ou 9)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto novoPedido;
	}

adcProduto:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ADICIONAR PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "QUAL PRODUTO DESEJA ADICIONAR? \n" WHITE);
	printf(GREEN "1" WHITE " ADICIONAR PIZZA\n");
	printf(GREEN "2" WHITE " ADICIONAR BEBIDA\n");
	printf(RED "3" RED " ADICIONAR ACOMPANHAMENTO\n");
	printf(RED "9" WHITE " VOLTAR\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto adcPizza;
	case '2':
		goto adcBebida;
	case '9':
		goto novoPedido;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 3 OU 9)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto adcProduto;
	}

adcPizza:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ADICIONAR PIZZA - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "SELECIONE A PIZZA:\n" WHITE);
	ListarPizzas();
	setbuf(stdin, NULL);
	(void)scanf("%i", &idProduto);

	if (AdicionarCarrinho(idProduto)) {
		printf(GREEN "A %s FOI ADICIONADA COM SUCESSO!" WHITE, nomeProdutoCarrinho[qntProdutoCarrinho]);
		Sleep(3000);
		goto adcProduto;
	}
	else {
		qntProdutoCarrinho--;
		printf(RED "A PIZZA NÃO FOI ADICIONADA!" WHITE);
		Sleep(3000);
		goto adcProduto;
	}

adcBebida:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ADICIONAR BEBIDA - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "SELECIONE A BEBIDA:\n" WHITE);
	ListarBebidas();
	setbuf(stdin, NULL);
	(void)scanf("%i", &idProduto);

	if (AdicionarCarrinho(idProduto)) {
		printf(GREEN "A PRODUTO: %s FOI ADICIONADO COM SUCESSO!" WHITE, nomeProdutoCarrinho[qntProdutoCarrinho]);
		Sleep(3000);
		goto adcProduto;
	}
	else {
		qntProdutoCarrinho--;
		printf(RED "A BEBIDA NÃO FOI ADICIONADA!" WHITE);
		Sleep(3000);
		goto adcProduto;
	}

removerProduto:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "REMOVER PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "SELECIONE O PRODUTO QUE DESEJA REMOVER " WHITE "OU" RED " 0 " WHITE "PARA VOLTAR\n" WHITE);
	for (int loop = 1; loop < qntProdutoCarrinho + 1; loop++) {
		printf(GREEN "%d" WHITE " %s\n", loop, nomeProdutoCarrinho[loop]);
	}
	(void)scanf("%i", &opcao);

	if (opcao != 0) {
		qntProdutoCarrinho--;
		nomeProdutoCarrinho[opcao] = NULL;
		totalProdutoCarrinho -= precoProdutoCarrinho[opcao];

		for (posicao; posicao <= qntProdutoCarrinho; posicao++) {
			if (nomeProdutoCarrinho[posicao] == NULL) {
				int next = posicao + 1;
				nomeProdutoCarrinho[posicao] = nomeProdutoCarrinho[next];
				nomeProdutoCarrinho[next] = NULL;
			}
		}
	}
	else {
		goto novoPedido;
	}
	goto novoPedido;

resumoPedido:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "RESUMO PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < (((cmd_dimension.rows / 2 - 3) - qntProdutoCarrinho)); i++) {
		printf("\n");
	}

	printf(MAGENTA "%+40s\n" WHITE, "RESUMO PEDIDO");
	printf(BLUE "%-15s" BLUE "%-32s" BLUE "%-0s\n" WHITE, "ID", "PRODUTO", "PREÇO");
	for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
		printf(WHITE "%-15d" WHITE "%-32s" WHITE "R$ %-0.2f\n" WHITE, prod, nomeProdutoCarrinho[prod], precoProdutoCarrinho[prod]);
	}
	printf(WHITE "________________________________________________________\n");
	printf(GREEN "%+50s%0.2f" WHITE, "TOTAL: R$ ", totalProdutoCarrinho);
	printf(WHITE "\n\nO QUE DESEJA FAZER?\n");
	printf(GREEN "1" WHITE " CONTINUAR PEDIDO\n");
	printf(GREEN "2" WHITE " FINALIZAR PEDIDO\n");
	printf(RED "9" WHITE " CANCELAR PEDIDO\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto adcProduto;
	case '2':
		goto finalizarPedido;
		break;
	case '9':
		for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
			idProdutoCarrinho[prod] = NULL;
			nomeProdutoCarrinho[prod] = NULL;
			precoProdutoCarrinho[prod] = 0;
		}
		qntProdutoCarrinho = 0;
		totalProdutoCarrinho = 0;
		menuPizzaria();
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 3)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto resumoPedido;
	}
finalizarPedido:
	opcao = 0;
	float valor = 0;
	float troco = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "RESUMO PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < ((cmd_dimension.rows / 2 - 3)); i++) {
		printf("\n");
	}
	printf(WHITE "%+75s\n" WHITE, "SELECIONE A MEIO DE" GREEN " PAGAMENTO" WHITE " OU" RED " 9 " WHITE "PARA CANCELAR");
	printf(BLUE "%-15s" BLUE "%-32s" BLUE "%-15s" BLUE "%-0s\n" WHITE, "ID", "SERVIÇO", "TAXA", "NOVO TOTAL");
	printf(BLUE "%-15s" WHITE "%-32s" WHITE  "%-15s" WHITE "%-0s" WHITE "%0.2f\n", "1", "DINHEIRO", "0%", "R$ ", totalProdutoCarrinho);
	printf(BLUE "%-15s" WHITE "%-32s" WHITE "%-15s" WHITE "%-0s" WHITE "%0.2f\n", "2", "CARTÃO DÉBITO/CRÉDITO", "2.5%", "R$ ", totalProdutoCarrinho + (totalProdutoCarrinho * 4.00) / 100);
	printf(BLUE "%-15s" WHITE "%-32s" WHITE "%-15s" WHITE "%-0s" WHITE "%0.2f\n", "3", "VALE REFEIÇÃO", "1.5%", "R$ ", totalProdutoCarrinho + (totalProdutoCarrinho * 3.5) / 100);
	opcao = _getch();
	switch (opcao) {
	case '1':
		printf("\nDIGITE O VALOR ENTREGUE PELO CLIENTE:" GREEN "R$");
		(void)scanf("%f", &valor);
		troco = valor - totalProdutoCarrinho;

		if (valor != totalProdutoCarrinho && valor > totalProdutoCarrinho) {
			printf(WHITE "VOCÊ DEVE ENTREGAR R$" RED " %0.2f " WHITE "DE TROCO\n", troco);
			printf(WHITE "VOCÊ DEU O TROCO?\n" WHITE);
			printf(GREEN "1 " WHITE "SIM\n");
			printf(GREEN "2 " WHITE "NÃO (VOLTARÁ PARA A ESCOLHA DO MEIO DE PAGAMENTO)\n");
			opcao = _getch();

			switch (opcao) {
			case '1':
				if (FinalizarPedido(1)) {
					centerText(GREEN "PEDIDO FINALIZADO...\n" WHITE, cmd_dimension.columns + 12);
					Sleep(3000);
					menuPizzaria();
				}
				else {
					centerText(RED "ERRO AO FINALIZAR PEDIDO...\n" WHITE, cmd_dimension.columns + 10);
					Sleep(2000);
					for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
						idProdutoCarrinho[prod] = NULL;
						nomeProdutoCarrinho[prod] = NULL;
						precoProdutoCarrinho[prod] = 0;
					}
					qntProdutoCarrinho = 0;
					totalProdutoCarrinho = 0;
				}
			default:
				goto finalizarPedido;
			}
		}
		else if (valor == totalProdutoCarrinho) {
			printf(WHITE "O VALOR ESTA CORRETO, VOCÊ" RED " NÃO " WHITE "DEVE DAR TROCO\n");
			if (FinalizarPedido(1)) {
				centerText(GREEN "PEDIDO FINALIZADO...\n" WHITE, cmd_dimension.columns + 12);
				Sleep(3000);
				menuPizzaria();
			}
			else {
				centerText(RED "ERRO AO FINALIZAR PEDIDO...\n" WHITE, cmd_dimension.columns + 10);
				Sleep(2000);
				for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
					idProdutoCarrinho[prod] = NULL;
					nomeProdutoCarrinho[prod] = NULL;
					precoProdutoCarrinho[prod] = 0;
				}
				qntProdutoCarrinho = 0;
				totalProdutoCarrinho = 0;
			}
		}
		else {
			troco = totalProdutoCarrinho - valor;
			printf(WHITE "O CLIENTE TE DEVE" RED " R$%0.2f" WHITE "!\n", troco);
			printf(WHITE "O CLIENTE DEU O RESTANTE?\n" WHITE);
			printf(GREEN "1 " WHITE "SIM\n");
			printf(GREEN "2 " WHITE "NÃO (VOLTARÁ PARA A ESCOLHA DO MEIO DE PAGAMENTO)\n");
			printf(GREEN "9 " WHITE "CANCELAR PEDIDO\n");
			opcao = _getch();

			switch (opcao) {
			case '1':
				if (FinalizarPedido(1)) {
					centerText(GREEN "PEDIDO FINALIZADO..." WHITE, cmd_dimension.columns + 12);
					Sleep(3000);
					menuPizzaria();
				}
				else {
					centerText(RED "ERRO AO FINALIZAR PEDIDO...\n" WHITE, cmd_dimension.columns + 10);
					Sleep(2000);
					for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
						idProdutoCarrinho[prod] = NULL;
						nomeProdutoCarrinho[prod] = NULL;
						precoProdutoCarrinho[prod] = 0;
					}
					qntProdutoCarrinho = 0;
					totalProdutoCarrinho = 0;
				}
			case '2':
				centerText(RED "VOLTANDO AO MENU DE FORMA DE PAGAMENTO..." WHITE, cmd_dimension.columns + 10);
				Sleep(2000);
				goto finalizarPedido;
			case '9':
				for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
					idProdutoCarrinho[prod] = NULL;
					nomeProdutoCarrinho[prod] = NULL;
					precoProdutoCarrinho[prod] = 0;
				}
				qntProdutoCarrinho = 0;
				totalProdutoCarrinho = 0;
				centerText(RED "PEDIDO CANCELADO..." WHITE, cmd_dimension.columns + 10);
				Sleep(2000);
				menuPizzaria();
			}

		}


		if (FinalizarPedido(1)) {
			for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
				idProdutoCarrinho[prod] = NULL;
				nomeProdutoCarrinho[prod] = NULL;
				precoProdutoCarrinho[prod] = 0;
			}
			qntProdutoCarrinho = 0;
			totalProdutoCarrinho = 0;
			menuPizzaria();
		}
		break;
	case '2':
		printf(WHITE "O PAGAMENTO FOI REALIZADO? "	CYAN "(CARTÃO DÉBITO/CRÉDITO)\n" WHITE);
		printf(GREEN "1 " WHITE "SIM\n" WHITE);
		printf(YELLOW "2 " WHITE "NÃO\n" WHITE);
		printf(RED "9 " WHITE "CANCELARn" WHITE);
		int sOpcao = _getch();
		switch (sOpcao)
		{
		case '1':
			if (FinalizarPedido(2)) {
				for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
					idProdutoCarrinho[prod] = NULL;
					nomeProdutoCarrinho[prod] = NULL;
					precoProdutoCarrinho[prod] = 0;
				}
				qntProdutoCarrinho = 0;
				totalProdutoCarrinho = 0;
				centerText(GREEN "PEDIDO FINALIZADO..." WHITE, cmd_dimension.columns + 18);
				Sleep(2000);
				menuPizzaria();
			}
		case '9':
			for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
				idProdutoCarrinho[prod] = NULL;
				nomeProdutoCarrinho[prod] = NULL;
				precoProdutoCarrinho[prod] = 0;
			}
			qntProdutoCarrinho = 0;
			totalProdutoCarrinho = 0;
			centerText(RED "PEDIDO CANCELADO..." WHITE, cmd_dimension.columns + 10);
			Sleep(2000);
			menuPizzaria();
		default:
			centerText(RED "VOLTANDO AO MENU DE FORMA DE PAGAMENTO..." WHITE, cmd_dimension.columns + 10);
			Sleep(2000);
			goto finalizarPedido;
		}
	case '3':
		printf(WHITE "\nO PAGAMENTO FOI REALIZADO? " YELLOW "(VALE REFEIÇÃO)\n" WHITE);
		printf(GREEN "1 " WHITE "SIM\n");
		printf(YELLOW "2 "WHITE "NÃO\n");
		printf(RED "9 " WHITE "CANCELAR\n");
		int tOpcao = _getch();
		switch (tOpcao)
		{
		case '1':
			if (FinalizarPedido(3)) {
				for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
					idProdutoCarrinho[prod] = NULL;
					nomeProdutoCarrinho[prod] = NULL;
					precoProdutoCarrinho[prod] = 0;
				}
				qntProdutoCarrinho = 0;
				totalProdutoCarrinho = 0;
				centerText(GREEN "PEDIDO FINALIZADO..." WHITE, cmd_dimension.columns + 12);
				Sleep(2000);
				menuPizzaria();
			}
		case '9':
			for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
				idProdutoCarrinho[prod] = NULL;
				nomeProdutoCarrinho[prod] = NULL;
				precoProdutoCarrinho[prod] = 0;
			}
			qntProdutoCarrinho = 0;
			totalProdutoCarrinho = 0;
			centerText(RED "PEDIDO CANCELADO..." WHITE, cmd_dimension.columns + 10);
			Sleep(2000);
			menuPizzaria();
		default:
			centerText(RED "VOLTANDO AO MENU DE FORMA DE PAGAMENTO..." WHITE, cmd_dimension.columns + 10);
			Sleep(2000);
			goto finalizarPedido;
		}
	case '9':
		for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
			idProdutoCarrinho[prod] = NULL;
			nomeProdutoCarrinho[prod] = NULL;
			precoProdutoCarrinho[prod] = 0;
		}
		qntProdutoCarrinho = 0;
		totalProdutoCarrinho = 0;
		menuPizzaria();
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 4)" WHITE, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" WHITE, cmd_dimension.columns + 12);
		system("pause > nul");
		goto finalizarPedido;
	}
	system("pause > nul");
}