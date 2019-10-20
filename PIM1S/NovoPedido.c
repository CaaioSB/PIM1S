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
	int loop = 0;
	char idProduto;
	char idCliente[5];
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "NOVO PEDIDO - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}
cliente:
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
	}

selCliente:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "SELECIONAR CLIENTE - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "SELECIONE O CLIENTE PELO ID\n" RESET);
	ListarClientes();
	printf("\n");
	setbuf(stdin, NULL);
	(void)scanf("%c", idCliente);

	BuscarCliente(idCliente[0]);
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
		
		break;
	case '9':

		break;
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
		break;
	case '2':
		break;
	case '3':
		break;
	case '9':
		goto novoPedido;
	}

adcPizza:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	printf("\n\n");
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
		goto novoPedido;
	}
	else {
		qntProdutoCarrinho--;
		printf(RED "A PIZZA NÃO FOI ADICIONADA!" RESET);
		Sleep(3000);
		goto novoPedido;
	}

removerProduto:
	opcao = 0;
	system(CLEAR_SCREEN_PROGRAM);
	printf("\n\n");
	centerText(BOLDMAGENTA "ADICIONAR PIZZA - SISTEMA GERENCIADOR DE PIZZARIA" RESET, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++)
	{
		printf("\n");
	}

	printf(MAGENTA "SELECIONE O PRODUTO QUE DESEJA REMOVER\n" RESET);
	for (loop; loop < qntProdutoCarrinho; loop++) {
		printf(GREEN "%d" RESET " %s", loop, nomeProdutoCarrinho[loop]);
	}
	opcao = _getch();

	qntProdutoCarrinho--;
	free(nomeProdutoCarrinho[opcao]);
}