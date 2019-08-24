#pragma once
#include "funcionario_library.c"

struct REGISTER;

struct REGISTER register_func;

static void CadastrarFuncionario(char nome[30], char email[100], char rg[20], char cpf[11], char cep[8], char usuario[10], char senha[10]);

static bool LoginFuncionario(char usuario, char senha);