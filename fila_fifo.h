#ifndef fila_fifo_h
#define fila_fifo_h

#include <stdlib.h>

typedef struct Fila{
	unsigned int val;
	unsigned int nconta;
	struct Fila *prox;
} No;


typedef struct Descritor{
	No *pri;
	No *fim;
} Fila_FIFO;


void f_inicializar (Fila_FIFO **f);

int f_inserir (Fila_FIFO **f, int chave, int valor);

int f_obter_proxima_chave (Fila_FIFO **f);

int f_consultar_proxima_chave (Fila_FIFO **f);

int f_consultar_proximo_valor (Fila_FIFO **f);

int f_num_elementos (Fila_FIFO **f);

int f_consultar_chave_por_posicao (Fila_FIFO **f, int posicao);

int f_consultar_valor_por_posicao (Fila_FIFO **f, int posicao);

#endif
