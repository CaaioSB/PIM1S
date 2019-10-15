#pragma once#pragma once
#include "BibCliente.c"
#pragma warning(disable : 4028)

struct Cliente;

struct Cliente BCliente;

static bool CadastrarCliente(char nome_completo[100], char telres[15], char telcel[16], char cpf[11], char cep[10]);

static int ContarClientes();