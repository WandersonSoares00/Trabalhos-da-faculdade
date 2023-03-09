#ifndef escalonador_h
#define escalonador_h
#include <stdio.h>
#include <string.h>
#include "fila_fifo.h"
#include "logtree.h"
#include "caixas.h"

typedef struct {
	Fila_FIFO *fpremium;
	Fila_FIFO *fouro;
	Fila_FIFO *fprata;
	Fila_FIFO *fbronze;
	Fila_FIFO *fleezu;
	int delt, caixas;
	int n[5]; /*Disciplina de escalonamento*/
	short int natual; /*Fila atendida atualmente (Intervalo de 0 a 4)*/
} Escalonador;

void e_inicializar (Escalonador *e, int caixas, int delta_t, int n_1, int n_2, int n_3, int n_4, int n_5);

int e_inserir_por_fila (Escalonador *e, int classe, int num_conta, int qtde_operacoes);

int e_obter_prox_num_conta(Escalonador *e);

int e_consultar_prox_num_conta (Escalonador *e);

int e_consultar_prox_qtde_oper (Escalonador *e);

int e_consultar_prox_fila (Escalonador *e);

int e_consultar_qtde_clientes (Escalonador *e);

int e_consultar_tempo_prox_cliente (Escalonador *e);

int e_conf_por_arquivo (Escalonador *e, char *nome_arq_conf);

void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out);

#endif
