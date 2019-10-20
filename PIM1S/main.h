#pragma once

// VARIÁVEL GLOBAL DE LOGIN
static char loggedNomeCompleto[] = "";
static char loggedEmail[] = { "" };
static char loggedRG[] = { "" };
static char loggedCPF[] = { "" };
static char loggedCEP[] = { "" };
static char loggedUser[] = { "" };
static char loggedSenha[] = { "" };
static char loggedFuncao[] = { "" };

/* TABELA FUNCIONARIO
* ID[0]	NOME[1]					EMAIL[2]						RG[3]		CPF[4]			CEP[5]		USER[6]	PASS[7]	FUNÇÃO[8]
* 1;	Caio da Silva Batista;	caio_silvabatista@hotmail.com;	560179839;	49355294824;	06654230;	caio;	123;	Gerente;
*/
static char dadosFuncionario[1024];
char* idFuncionario;
static char nomeFuncionario[100];
static char emailFuncionario[100];
static char rgFuncionario[20];
static char cpfFuncionario[11];
static char cepFuncionario[10];
static char userFuncionario[20];
static char passFuncionario[20];
static char funcaoFuncionario[50];


/* TABELA CLIENTE */
static char dadosCliente[1024];
char* idCliente;
static char nomeCliente[100];
static char telresCliente[15];
static char telcelCliente[16];
static char cpfCliente[11];
static char cepCliente[11];

/* CARRINHO DE COMPRAS */
static char carrinhoCompras[1024];
static char* idProdutoCarrinho[25];
static int qntProdutoCarrinho = -1;
static char* nomeProdutoCarrinho[25];
static float totalProdutoCarrinho;

/* ARMAZENAMENTOS DO BANCO DE DADOS */
static char* tb_funcionario = "C:\\SGP\\db\\tb_funcionario.txt";
static char* tb_funcionario2 = "C:\\SGP\\db\\tb_funcionario2.txt";

static char* tb_cliente = "C:\\SGP\\db\\tb_cliente.txt";
static char* tb_cliente2 = "C:\\SGP\\db\\tb_cliente2.txt";


static char* tb_produto = "C:\\SGP\\db\\tb_produto.txt";
static char* tb_produto2 = "C:\\SGP\\db\\tb_produto2.txt";

static char* tb_feedback = "C:\\SGP\\db\\tb_feedback.txt";
static char* tb_feedback2 = "C:\\SGP\\db\\tb_feedback2.txt";