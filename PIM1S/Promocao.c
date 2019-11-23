#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Promocao.h"
#include "util.h"
#include "Promocao.h"
#include "main.h"
//#include "main.h"

int opcao;

void menuDesconto() {
	system(CLEAR_SCREEN_PROGRAM);
	centerText(BOLDMAGENTA "MENU LOGIN - SISTEMA GERENCIADOR DE PIZZARIA" WHITE, cmd_dimension.columns + 18);

	for (int i = 0; i < cmd_dimension.rows / 2 - 3; i++) {
		printf("\n");
	}

	printf(BLUE "DIGITE QUANTOS % VOCÊ QUER DAR DE DESCONTO: ");
	printf(RED "ATENÇÃO: ESSE DESCONTO É PARA TODOS OS PRODUTOS DO SISTEMA!\n" WHITE);
	setbuf(stdin, NULL);
	(void)scanf("%i", &descontoPorcentagem);
	printf(YELLOW "VOCÊ DEFINIU UM DESCONTO DE %i%%.\n", descontoPorcentagem);
}