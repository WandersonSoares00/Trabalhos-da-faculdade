#ifndef caixas_h
#define caixas_h
#include <stdlib.h>

typedef struct{
	unsigned int qtd_atendidos;
	short int oper;
}Caixa;


 /*   Funções auxiliares   */
int c_inicializar(Caixa **c, int qtd_caixas);

int c_realizar_prox_operacao(Caixa **c);

int c_obter_prox_caixa(Caixa **c);

int c_obter_num_atendidos(Caixa **c, int j);

int c_obter_oper_ultimo_cliente(Caixa **c);

#endif
