#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <new.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "util.h"
#include "MenuPizzaria.h"
#include "main.h"

struct REGISTER {
	char nome_completo[1024];
	char email[1024];
	char rg[1024];
	char cpf[1024];
	char cep[1024];
	char usuario[1024];
	char senha[1024];
	char funcao[1024];
};

// MAX = 3
static int tentativas = 0;

static bool validateEmail(char* email) {
	int tam = strlen(email);
	int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

	for (i = 0; i < tam; i++) {
		char c = email[i];
		if (c == '@') {
			if (arroba)
				break; // não pode ter uma segunda @
			arroba = 1;
			if (i < 3)
				break; // se @ vier antes de 3 caracteres, erro
		}
		else if (arroba) { // se já encontrou @
			if (ponto) { // se já encontrou . depois de @
				depoisPonto++;
			}
			else if (c == '.') {
				ponto = 1;
				if (antesPonto < 3) {
					break; // se . depois de @ vier antes de 3 caracteres, erro
				}
			}
			else {
				antesPonto++;
			}
		}
	} // for

	if (i == tam && depoisPonto > 1) {
		return false;
	}
	else {
		return true;
	}
}

static bool validateCPF(char* cpf) {
	if (sizeof(cpf) != 11) {
		return false;
	}
	else {
		return true;
	}
}

static bool validateCEP(char* cep) {
	if (sizeof(cep) != 6) {
		return false;
	}
	else {
		return true;
	}
}

static bool CadastrarFuncionario(char nome[30], char email[100], char rg[20], char cpf[11], char cep[8], char usuario[10], char senha[10], char funcao[100]) {
	int errors = 0;
	if (validateCPF(cpf)) {
		centerText(RED "\nCPF INVÁLIDO!" WHITE, cmd_dimension.columns + 10);
		errors++;
	}

	if (validateEmail(email)) {
		centerText(RED "\nE-MAIL INVÁLIDO!" WHITE, cmd_dimension.columns + 10);
		errors++;
	}

	if (validateCEP(cep)) {
		centerText(RED "\nCEP INVÁLIDO!\n" WHITE, cmd_dimension.columns + 10);
		errors++;
	}

	if (errors == 0) {
		int id = (int)ContarFuncionarios() + 1;
		FILE* file;
		if (id == 1) {
			file = fopen(tb_funcionario, "w");
			fprintf(file, "%d;%s;%s;%s;%s;%s;%s;%s;%s;\n", id, nome, email, rg, cpf, cep, usuario, senha, funcao);
			printf("\n\n");
			fclose(file);
			return true;
		}
		else {
			file = fopen(tb_funcionario, "a");
			fprintf(file, "%d;%s;%s;%s;%s;%s;%s;%s;%s;\n", id, nome, email, rg, cpf, cep, usuario, senha, funcao);
			printf("\n\n");
			fclose(file);
			return true;
		}
	}
	else {
		return false;
	}
}

#define MAX_STR_SIZE	6
#define MIN_STR_SIZE	6
char* captcha;

static char generateCaptcha() {
	char* validchars = "abcdefghijklmnopqrstuvwxyz";
	register int i;
	int str_len;

	// inicia o contador aleatório
	srand(time(NULL));

	// novo tamanho
	str_len = (rand() % MAX_STR_SIZE);

	// checa tamanho
	str_len += (str_len < MIN_STR_SIZE) ? MIN_STR_SIZE : 0;

	// aloca memoria
	captcha = (char*)malloc((str_len + 1) * sizeof(char));
	if (!captcha) {
		printf("[*] Erro ao alocar memoria.\n");
		exit(EXIT_FAILURE);
	}

	// gera string aleatória
	for (i = 0; i < str_len; i++) {
		captcha[i] = validchars[rand() % strlen(validchars)];
		captcha[i + 1] = 0x0;
	}

	// imprive informações
	printf(YELLOW "\n[*]" WHITE " DIGITE O CAPTCHA SEGUINTE PARA PROSSEGUIR: %s\n", captcha);
}

static bool valideCaptcha(char* userCaptcha) {
	if (strcmp(captcha, userCaptcha) == 0) {
		return true;
	}
	else {
		return false;
	}
}

static bool LoginFuncionario(char usuario[], char senha[]) {
	int i = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	char delimiter[] = ";";
	char* values[10];
	FILE* arquivo;
	arquivo = AbreArquivo('l', tb_funcionario);

	if (arquivo == NULL)
		return EXIT_FAILURE;

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras[i] = _strdup(line);

		//Conta a quantidade de linhas
		i++;
		numLinhas++;
	}

	for (int x = 0; x < numLinhas; x++) {
		int j = 0;
		char* ptr = strtok(palavras[x], delimiter);
		values[j] = ptr;
		j++;
		while (ptr != NULL)
		{
			// Imprime os dados lidos do documento de texto
			//printf("'%s'\n", ptr);

			ptr = strtok(NULL, delimiter);
			values[j] = ptr;
			j++;

		}
		if (tentativas >= 3) {
			generateCaptcha();
			char userCaptcha[100];
			(void)scanf(" %[^\n]s", &userCaptcha);
			if (valideCaptcha(userCaptcha)) {
				if (strcmp(usuario, values[6]) == 0) {
					if (strcmp(senha, values[7]) == 0) {
						strcpy(loggedId, values[0]);
						strcpy(loggedNomeCompleto, values[1]);
						strcpy(loggedEmail, values[2]);
						strcpy(loggedRG, values[3]);
						strcpy(loggedCPF, values[4]);
						strcpy(loggedCEP, values[5]);
						strcpy(loggedUser, values[6]);
						strcpy(loggedSenha, values[7]);
						strcpy(loggedProfissao, values[8]);
						printf("\n\n");
						centerText(GREEN "LOGIN REALIZADO" WHITE, cmd_dimension.columns + 10);
						Sleep(3000);
						FecharArquivo(arquivo);
						menuPizzaria();
						return true;
					}
					else {
						printf("\n\n");
						centerText(RED "SENHA INCORRETA, VOLTANDO AO MENU INICIAL" WHITE, cmd_dimension.columns + 10);
						Sleep(3000);
						FecharArquivo(arquivo);
						tentativas++;
						return false;
					}
				}
				else {
					printf("\n\n");
					centerText(RED "USUÁRIO NÃO ENCONTRADO, VOLTANDO AO MENU INICIAL" WHITE, cmd_dimension.columns + 10);
					Sleep(3000);
					FecharArquivo(arquivo);
					tentativas++;
					return false;
				}
			}
			else {
				printf("\n\n");
				centerText(RED "CAPTCHA INCORRETO, VOLTANDO AO MENU INICIAL" WHITE, cmd_dimension.columns + 10);
				Sleep(3000);
				FecharArquivo(arquivo);
				tentativas++;
				return false;
			}
		}
		else {
			if (strcmp(usuario, values[6]) == 0) {
				if (strcmp(senha, values[7]) == 0) {
					printf("\n\n");
					centerText(GREEN "LOGIN REALIZADO" WHITE, cmd_dimension.columns + 10);
					loggedId = values[0];
					strcpy(loggedNomeCompleto, values[1]);
					strcpy(loggedProfissao, values[8]);
					strcpy(loggedEmail, values[2]);
					strcpy(loggedRG, values[3]);
					strcpy(loggedCPF, values[4]);
					strcpy(loggedCEP, values[5]);
					strcpy(loggedUser, values[6]);
 					strcpy(loggedSenha, values[7]);
					Sleep(3000);
					FecharArquivo(arquivo);
					menuPizzaria();
					return true;
				}
			}
		}
		free(ptr);
	}
	FecharArquivo(arquivo);
	return false;
}

static bool ListarFuncionarios() {
	int x = 0;
	int numLinhas = 0;
	char* palavras[50];
	char line[1024];
	FILE* arquivo;

	arquivo = AbreArquivo('l', tb_funcionario);

	if (arquivo == NULL)
		return EXIT_FAILURE;

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		palavras[x] = _strdup(line);
		printf("%s\n", palavras[x]);
		x++;

		//Conta a quantidade de linhas
		numLinhas++;
	}
	FecharArquivo(arquivo);
	return true;
}

static bool AlterarFuncionario(char idFuncionario, char nomeFuncionario[100], char emailFuncionario[100], char rgFuncionario[20], char cpfFuncionario[11], char cepFuncionario[20], char userFuncionario[20], char passFuncionario[20], char funcaoFuncionario[50]) {
	/*
	*	FAZER UMA STRING QUE SIMULA UMA LINDA DO BANCO DADOS
	*	DEPOIS DE DESENVOLVER ESSA STRING EU VOU TER QUE INSERIR
	*	ELA EM UM ARQUIVO COMO BACKUP E DEPOIS DELETAR O ARQUICO ORIGINAL
	*	APÓS DELETAR O ARQUIVO ORIGINAL, EU DEVO POR CADA QUE ESTAVA NO
	*/

	int numLinha = 0;
	char line[1024];
	char delimiter[] = ";";
	FILE* arquivo;
	FILE* newArquivo;
	char* palavras[50];
	int i = 0;
	char* values[9];
	char* fileLine[100];
	arquivo = AbreArquivo('l', tb_funcionario);

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		if (i == (idFuncionario - 49)) {
			snprintf(line, sizeof line, "%c;%s;%s;%s;%s;%s;%s;%s;%s;", idFuncionario, nomeFuncionario, emailFuncionario, rgFuncionario, cpfFuncionario, cepFuncionario, userFuncionario, passFuncionario, funcaoFuncionario);
			fileLine[i] = _strdup(line);

		}
		else {
			fileLine[i] = _strdup(line);
		}
		i++;
	}

	FecharArquivo(arquivo);

	FILE* newFile = AbreArquivo('g', tb_funcionario2);
	if (newFile == NULL) {
		centerText(RED "\n\nOCORREU UM ARRO AO ALTERAR O FUNCIONÁRIO", cmd_dimension.columns + 4);
	}
	else {
		for (int x = 0; x < i; x++) {
			fprintf(newFile, "%s", fileLine[x]);
		}
	}
	FecharArquivo(newFile);

	if (remove(tb_funcionario) == 0) {
		if (rename(tb_funcionario2, tb_funcionario) == 0) {
			return true;
		}
	}
	else {
		perror("remove");
		return false;
	}
}

static char BuscarFuncionario(char id) {
	int numLinha = 0;
	char line[1024];
	char delimiter[] = ";";
	FILE* arquivo;
	FILE* arquivo2;
	char* palavras[50];
	int i = 0;
	char* values[9];
	char* fileLine[100];

	arquivo = AbreArquivo('l', tb_funcionario);

	while (fgets(line, sizeof line, arquivo) != NULL)
	{
		//Adiciona cada linha no vetor
		fileLine[i] = _strdup(line);
		i++;
	}

	FecharArquivo(arquivo);
	/*
	* O NÚMERO DA LINHA É O MESMO QUE O CÓDIGO DO FUNCIONÁRIO
	* ENTÃO: SE LINHA É IGUAL A 15, O CÓDIGO DO FUNCIONÁRIO TAMBÉM SERÁ 15
	*/

	arquivo2 = AbreArquivo('l', tb_funcionario);

	if (arquivo2 == NULL)
		return EXIT_FAILURE;

	while (fgets(dadosFuncionario, sizeof dadosFuncionario, arquivo2) != NULL)
	{
		palavras[numLinha] = _strdup(dadosFuncionario);
		if (dadosFuncionario[0] == id)
		{
			int j = 0;
			while (j < 1) {
				char* ptr = strtok(palavras[numLinha], delimiter);
				values[j] = ptr;
				j++;
				while (ptr != NULL && j < 9)
				{
					// Imprime os dados lidos do documento de texto
					//printf("'%s'\n", ptr);
					ptr = strtok(NULL, delimiter);
					values[j] = ptr;
					j++;
				}
			}
			// PEGANDO OS DADOS DO FUNCIONÁRIO REQUERIDO
			idFuncionario = values[0];
			strcpy(nomeFuncionario, values[1]);
			strcpy(emailFuncionario, values[2]);
			strcpy(rgFuncionario, values[3]);
			strcpy(cpfFuncionario, values[4]);
			strcpy(cepFuncionario, values[5]);
			strcpy(userFuncionario, values[6]);
			strcpy(passFuncionario, values[7]);
			strcpy(funcaoFuncionario, values[8]);
			FecharArquivo(arquivo2);
			break;
		}
		numLinha++;
	}
	FecharArquivo(arquivo2);
}

static int ContarFuncionarios() {
	int numLinhas = 0;
	char line[1024];
	FILE* file;
	file = fopen(tb_funcionario, "r");

	if (file == NULL) {
		FecharArquivo(file);
		return 0;
	}

	while (fgets(line, sizeof line, file) != NULL)
	{
		numLinhas++;
	}
	fclose(file);
	return numLinhas;
}

// static bool trocarSenha(char senha[]) {}

// static bool recuperarSenha(char email[], char usuario[]) {}