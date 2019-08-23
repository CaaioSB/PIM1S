#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include "main.h"
#include <new.h>

// LIMPAR A TELA
#define CLEAR_SCREEN_PROGRAM "cls"

// MENSSAGEM DE ERRO
#define ERROR_INTERNAL "ERRO FATAL: Contate o desenvolvedor do sistema para mais explicações"


// FUNÇÕES PARA ALTERAR AS CORES
void red() {
	printf("\033[1;31m");
}

void yellow() {
	printf("\033[1;33m");
}

void reset() {
	printf("\033[0m");
}

// CONSTANTES
char title[25] = "SISTEMA DE PIZZARIA v1.0";

// FUNÇÃO PARA ARMAZENAR O TAMANHO DO MS-Windows
struct CMD_DIMENSION {
	int rows;
	int columns;
};

struct REGISTER {
	char nome_completo[1024];
	char email[1024];
	char rg[1024];
	char cpf[1024];
	char cep[1024];
	char usuario[1024];
	char senha[1024];
};

struct LOGIN {
	char nome[1024];
	char senha[1024];
};

struct CMD_DIMENSION cmd_dimension;

// FUNÇÃO PARA OBTER AS DIMENSÕES DA JANELA CMD
// API DO MS-Windows
int get_cmd_dimension() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	BOOL status;

	DWORD error_code;

	LPVOID message;

	status = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	if (!status) { // CASO O RETORNO FOR IGUAL A 0, A FUNÇÃO NÃO FOI EXECUTADA CORRETAMENTE
		error_code = GetLastError();
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			status,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)& message,
			0,
			NULL);
		//log((LPSTR)message);
		LocalFree(message);

		return 0;
	}

	cmd_dimension.columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	cmd_dimension.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return 1;
}

void centerText(char* text, int fieldWidth) {
	int padlen = (fieldWidth - strlen(text)) / 2;
	printf("% *s % s % *s\n", padlen, "", text, padlen, "");
}

int i;
// FUNÇÃO PARA MOSTRAR A TELA DE SPLASH (INTRODUÇÃO)
void splash_window()
{

	// LIMPA O CONSOLE
	system(CLEAR_SCREEN_PROGRAM);

	topLines();

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	centerText("SISTEMA GERENCIADOR DE PIZZARIA v1.0", cmd_dimension.columns);
	char message[65] = "PRESSIONE A TECLA \033[1;31mESPAÇO\033[0m PARA INICIAR UM NOVO TURNO";
	centerText(message, cmd_dimension.columns + 10);

	for (i = 0; i < (cmd_dimension.rows / 2 - 3); i++) {
		printf("\n");
	}

	bottomLines();

	system("pause >nul");
}


void principal_menu() {
	int op;

	system(CLEAR_SCREEN_PROGRAM);
	topLines();
	printf("\n\n");
	centerText("MENU - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("1 - FAZER LOGIN\n");
	printf("2 - REGISTRAR-SE\n");
	printf("3 - ESQUECI MINHA SENHA\n");
	printf("ESCOLHA UMA OPÇÃO DESEJADA: \n");

	scanf_s("%d", &op);

	for (i = 0; i < (cmd_dimension.rows / 2 - 4); i++) {
		printf("\n");
	}

	bottomLines();

	switch (op)
	{
	case 1:
		break;
	case 2:
		register_window();
		break;
	}
	system("pause >nul");


}

// FUNÇÃO PARA FAZER LINHAS COLORIDAS SUPERIORES
void topLines()
{
	for (i = 0; i < cmd_dimension.columns; i++) {
		red();
		printf("_");
		yellow();
		printf("_");
		reset();
	}
}

// FUNÇÃO PARA FAZER LINHAS COLORIDAS INFERIORES
void bottomLines()
{
	for (i = 0; i < cmd_dimension.columns; i++) {
		yellow();
		printf("_");
		red();
		printf("_");
		reset();
	}
}


int main() {
	setlocale(LC_ALL, "Portuguese");

	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);

	// Primeiro obtém o tamanho da janela CMD - será utilizada para construir os menus 
	if (!get_cmd_dimension()) {
		printf(ERROR_INTERNAL);
		return 0;
	}
	splash_window();

	if (GetKeyState(VK_SPACE) && 0x8000) {
		principal_menu();
	}

	system("pause >nul");
	return 1;
}

FILE* arquivo = NULL;
FILE* AbreArquivo(char modo, char caminho[30]) {
	switch (modo) {
	case 'g':
		arquivo = fopen(caminho, "wt");
		break;
	case 'l':
		arquivo = fopen(caminho, "rt");
		break;
	case 'a':
		arquivo = fopen(caminho, "a");
		break;
	}
	if (arquivo == NULL) {
		printf("Nao foi possivel abrir o arquivo");
		exit(0);
	}
	return arquivo;
}

void FecharArquivo(FILE* arquivo) {
	fclose(arquivo);
}


void CadastrarFuncionario(char nome[30], char email[100], char rg[20], char cpf[11], char cep[8], char usuario[10], char senha[10]) {
	FILE* arquivo;
	arquivo = AbreArquivo('a', "C:\\SGP\\db\\tb_funcionario.txt");
	fprintf(arquivo, "%s %s %s %s %s %s %s\n", nome, email, rg, cpf, cep, usuario, senha);
	FecharArquivo(arquivo);
}

struct REGISTER register_func;
void register_window() {
	system(CLEAR_SCREEN_PROGRAM);
	topLines();
	printf("\n\n");
	centerText("REGISTRAR-SE - SISTEMA GERENCIADOR DE PIZZARIA", cmd_dimension.columns);

	for (i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf("DIGITE SEU NOME COMPLETO: ");
	(void)scanf(" %[^\n]s",register_func.nome_completo);

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


struct LOGIN login;
void login_window() {
	printf("Login: ");
	gets(login.nome);

	printf("Senha: ");
	gets(login.senha);
	system("pause >nul");
}