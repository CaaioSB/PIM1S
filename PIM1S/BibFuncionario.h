#pragma once#pragma once
#include "BibFuncionario.c"
#pragma warning(disable : 4028)

struct REGISTER;

struct REGISTER BFuncionario;

static bool CadastrarFuncionario(char nome[30], char email[100], char rg[20], char cpf[11], char cep[8], char usuario[10], char senha[10], char funcao[100]);

static bool LoginFuncionario(char usuario[], char senha[]);

static bool ListarFuncionarios();

static int ContarFuncionarios();

