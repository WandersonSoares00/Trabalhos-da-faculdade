/*
	INTEGRANTES DA EQUIPE:
		Wanderson Soares da Silva - 538348
		Gabriel Victor Magalhães da Silva - 539922
*/

#include <stdio.h>
#include <stdlib.h>
#include "escalonador.h"

int main(int argc, char *argv[]) {
	Escalonador e;
	char entrada[17] = "entrada-", saida[15] = "saida-";

	if ( argc < 2 ){ /* nenhum arquivo informado na linha de comando */
		printf("Arquivo de entrada não informado.\nEx. entrada: ./main 1\n");
		return EXIT_FAILURE;
	}
	
	/* obtendo o nome dos arquivos de entrada e saída
   	   de acordo com o número informado pelo usuário. */
	sprintf(argv[1], "%04d", atoi(argv[1]));
	strcat(saida, argv[1]);
	strcat(entrada, argv[1]);
	strcat(entrada, ".txt");
	strcat(saida, ".txt");

	e_rodar(&e, entrada, saida);
	
	return EXIT_SUCCESS;
}
