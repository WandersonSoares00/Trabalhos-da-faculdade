#include "fila_fifo.h"

/*Inicializa a fila.*/
void f_inicializar (Fila_FIFO **f){
	(*f) = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
	(*f) -> pri = NULL;
	(*f) -> fim = NULL;
}

/*Insere um determinado valor inteiro indexado por um valor de chave na fila. Retorna 1 se a
  inserção for bem sucedida e 0 se houver algum problema (duplicação de chave ou falta de memória).*/
int f_inserir (Fila_FIFO **f, int chave, int valor){
	No *aux;

	aux = (No *) malloc(sizeof(No));

	if(aux == NULL)		return 0;
	//if(f_consultar_chave_por_posicao(f, chave) != -1)	return 0;

	aux -> val = valor;
	aux -> nconta = chave;
	aux -> prox = NULL;

	if((*f) -> pri == NULL) //Fila vazia
		(*f) -> pri = aux;
	else
		(*f) -> fim -> prox = aux;

	(*f) -> fim = aux;

	return 1;
}


/*Retorna o número de chave do próximo elemento da fila, retirando-o da fila.
  Retorna -1 se a fila estiver vazia.*/
int f_obter_proxima_chave (Fila_FIFO **f){
	No *deletado;
	int chave;

	if((*f) -> pri == NULL)
		return -1;

	deletado = (*f) -> pri;
	chave = deletado -> nconta;
	(*f) -> pri = (*f) -> pri -> prox;
	free(deletado);

	return chave;
}


/*Retorna a chave do elemento que está na cabeça da fila, sem retirá-lo da fila. Retorna -1 se a fila estiver vazia.*/
int f_consultar_proxima_chave (Fila_FIFO **f){
	if((*f) -> pri == NULL)
		return -1;
	else
		return (*f) -> pri -> nconta;
}


/*Retorna o valor armazenado no elemento que está na cabeça da fila, sem retirá-lo da fila.
  Retorna -1 se a fila estiver vazia.*/
int f_consultar_proximo_valor (Fila_FIFO **f){
	if((*f) -> pri == NULL)
		return -1;
	else
		return (*f) -> pri -> val;
}


/*Retorna o número de elementos presentes na fila*/
int f_num_elementos (Fila_FIFO **f){
	int cont = 0;
	No *q = (*f) -> pri;

	while(q != NULL){
		cont ++;
		q = q -> prox;
	}

	return cont;
}


/*Retorna a chave do posicao-ésimo elemento da fila. Caso não exista a posição desejada, retornar -1.
  A posição se inicia em 1*/
int f_consultar_chave_por_posicao (Fila_FIFO **f, int posicao){
	int i = 1;
	No *q = (*f) -> pri;

	if((*f) -> pri == NULL)	//Fila vazia
		return -1;

	while(q -> prox != NULL && i < posicao){
		q = q -> prox;
		i++;
	}

	if(i == posicao)
		return q -> nconta;
	else
		return -1;
}


/*Retorna o valor do posicao-ésimo elemento da fila. Caso não exista a posição desejada, retornar -1.
  A posição se inicia em 1.*/
int f_consultar_valor_por_posicao (Fila_FIFO **f, int posicao){
	int i = 1;
	No *q = (*f) -> pri;

	if((*f) -> pri == NULL)	//Fila vazia
		return -1;

	while(q -> prox != NULL && i < posicao){
		q = q -> prox;
		i++;
	}

	if(i == posicao)
		return q -> val;
	else
		return -1;
}
