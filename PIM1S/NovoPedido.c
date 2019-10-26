#include "NovoPedido.h"
#include "util.h"
#include "main.h"
#include "BibCliente.h"
#include "BibProduto.h"

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
	char idProduto;
	char idCliente[5];
cliente:
	opcao = 0;
	//loop = 1;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "NOVO PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}
	printf(MAGENTA "O CLIENTE POSSUI UM CADASTRO ATIVO NA PIZZARIA?\n" RESET);
	printf(GREEN "1" RESET " SIM\n");
	printf(RED "2" RESET " NÃO\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto selCliente;
	case '2':
		CadCliente();
		goto cliente;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 2)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" RESET, cmd_dimension.columns + 12);
		system("pause > nul");
		goto cliente;
	}

selCliente:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "SELECIONAR CLIENTE - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "%+47s\n" RESET, "SELECIONE O CLIENTE PELO ID");
	ListarClientes();
	printf("\n");
	setbuf(stdin, NULL);
	(void)scanf("%c", idCliente);

	BuscarCliente(idCliente[0]);
confCliente:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "SELECIONAR CLIENTE - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}
	printf("VOCÊ ESTA FAZENDO UM NOVO PEDIDO PARA: " YELLOW "%s" RESET "?\n", nomeCliente);
	printf(GREEN "1" RESET " SIM\n");
	printf(RED "2" RESET " NÃO\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto novoPedido;
	case '2':
		goto cliente;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 2)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" RESET, cmd_dimension.columns + 12);
		system("pause > nul");
		goto selCliente;
	}


novoPedido:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "NOVO PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "O QUE DESEJA FAZER?\n" RESET);
	printf(GREEN "1" RESET " ADICIONAR PRODUTO\n");
	printf(GREEN "2" RESET " REMOVER PRODUTO\n");
	printf(GREEN "3" RESET " FINALIZAR PEDIDO\n");
	printf(RED "9" RESET " CANCELAR PEDIDO\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto adcProduto;
	case '2':
		goto removerProduto;
	case '3':
		goto finalizarPedido;
	case '9':
		menuPizzaria();
		break;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 3 ou 9)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" RESET, cmd_dimension.columns + 12);
		system("pause > nul");
		goto novoPedido;
	}

adcProduto:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ADICIONAR PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "QUAL PRODUTO DESEJA ADICIONAR? \n" RESET);
	printf(GREEN "1" RESET " ADICIONAR PIZZA\n");
	printf(GREEN "2" RESET " ADICIONAR BEBIDA\n");
	printf(RED "3" RESET " ADICIONAR ACOMPANHAMENTO\n");
	printf(RED "9" RESET " VOLTAR\n");
	opcao = _getch();

	switch (opcao) {
	case '1':
		goto adcPizza;
	case '2':
		goto adcBebida;
	case '3':
		break;
	case '9':
		goto novoPedido;
	default:
		centerText(RED "VOCÊ DEVE SELECIONAR UMA OPÇÃO VÁLIDA!" YELLOW " (DE 1 A 3 OU 9)" RESET, cmd_dimension.columns + 18);
		centerText(GREEN "PRESSIONE QUALQUER TECLA PARA VOLTAR" RESET, cmd_dimension.columns + 12);
		system("pause > nul");
		goto adcProduto;
	}

adcPizza:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ADICIONAR PIZZA - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "SELECIONE A PIZZA:\n" RESET);
	ListarPizzas();
	setbuf(stdin, NULL);
	(void)scanf("%c", &idProduto);

	if (AdicionarCarrinho(idProduto)) {
		printf(GREEN "A %s FOI ADICIONADA COM SUCESSO!" RESET, nomeProdutoCarrinho[qntProdutoCarrinho]);
		Sleep(3000);
		goto adcProduto;
	}
	else {
		qntProdutoCarrinho--;
		printf(RED "A PIZZA NÃO FOI ADICIONADA!" RESET);
		Sleep(3000);
		goto adcProduto;
	}

adcBebida:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "ADICIONAR BEBIDA - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "SELECIONE A BEBIDA:\n" RESET);
	ListarBebidas();
	setbuf(stdin, NULL);
	(void)scanf("%c", &idProduto);

	if (AdicionarCarrinho(idProduto)) {
		printf(GREEN "A PRODUTO: %s FOI ADICIONADO COM SUCESSO!" RESET, nomeProdutoCarrinho[qntProdutoCarrinho]);
		Sleep(3000);
		goto adcProduto;
	}
	else {
		qntProdutoCarrinho--;
		printf(RED "A BEBIDA NÃO FOI ADICIONADA!" RESET);
		Sleep(3000);
		goto adcProduto;
	}

removerProduto:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "REMOVER PRODUTO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "SELECIONE O PRODUTO QUE DESEJA REMOVER " WHITE "OU" RED " 0 " WHITE "PARA VOLTAR\n" RESET);
	for (int loop = 1; loop < qntProdutoCarrinho + 1; loop++) {
		printf(GREEN "%d" RESET " %s\n", loop, nomeProdutoCarrinho[loop]);
	}
	(void)scanf("%i", &opcao);

	if (opcao != 0) {
		qntProdutoCarrinho--;
		nomeProdutoCarrinho[opcao] = NULL;

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

finalizarPedido:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "FINALIZAR PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < ((cmd_dimension.rows / 2 - 3) - qntProdutoCarrinho) + 4; i++) {
		printf("\n");
	}

	printf(MAGENTA "%+40s\n" RESET, "FINALIZANDO PEDIDO");
	printf(BLUE "%-15s" BLUE "%-32s" BLUE "%-0s\n" RESET, "ID", "PRODUTO", "PREÇO");
	for (int prod = 1; prod < qntProdutoCarrinho + 1; prod++) {
		printf(WHITE "%-15d" WHITE "%-32s" WHITE "R$ %-0.2f\n" RESET, prod, nomeProdutoCarrinho[prod], precoProdutoCarrinho[prod]);
	}
	printf(WHITE "________________________________________________________\n");
	printf(GREEN "%+50s%0.2f" RESET, "TOTAL: R$ ", totalProdutoCarrinho);
	system("pause > nul");
}