#include "logtree.h"

/*Inicializa o registrador l*/
void log_inicializar(Log **l){
	(*l) = NULL;
}


/*Inclui um registro de tempo de atendimento da conta de número “conta”, que faz parte da classe de número “classe”, que 
  sperou “timer” minutos para ser atendido pelo caixa de número “caixa” */
void log_registrar(Log **l, int conta, int classe, int timer, int caixa){
  Log *aux, *q1, *q2;
  
  aux = (Log *) malloc(sizeof(Log));
  if(aux == NULL)
    return;
  
  aux -> conta = conta;
  aux -> clas = classe;
  aux -> tempo = timer;
  aux -> cxa = caixa;
  aux -> esq = NULL;
  aux -> dir = NULL;

  q1 = q2 = (*l);
  while( q1 != NULL ){
    q2 = q1;
    if( conta > q1 -> conta )
      q1 = q1 -> dir;
	else if ( conta == q1 -> conta )  /* Conta duplicada */
		return;
    else
      q1 = q1 -> esq;
  }

  if(q2 == NULL)
    (*l) = aux;
  else if(conta > q2 -> conta)
      q2 -> dir = aux;
  else 
    q2 -> esq = aux;
}


/*Retorna o tempo médio de espera, em minutos, para a classe de número “classe”.*/
float log_media_por_classe(Log **l, int classe){
	float tsoma;
	float qtd;
	
	tsoma = log_obter_soma_por_classe(l, classe);
	qtd = log_obter_contagem_por_classe(l, classe);

	if( qtd == 0 )		return 0;
	else 				return (tsoma / qtd);
}


/*Retorna a soma dos tempos de espera de todos os clientes cujas contas fazem parte da classe de número “classe”.*/
int log_obter_soma_por_classe(Log **l, int classe){
	int t = 0;
	if((*l) == NULL)
		return 0;
	
	t += (log_obter_soma_por_classe(&((*l) -> esq), classe)) + log_obter_soma_por_classe(&((*l) -> dir), classe);
	
	if((*l) -> clas == classe)
		t += (*l) -> tempo;
	
	return t;
}


/*Retorna a quantidade de clientes atendidos cujas contas são da categoria de número “classe”.*/
int log_obter_contagem_por_classe(Log **l, int classe){
  	int qtd = 0;
	
	if((*l) == NULL)
      return 0;
	
	qtd += (log_obter_contagem_por_classe(&((*l) -> esq), classe)) + log_obter_contagem_por_classe(&((*l) -> dir), classe);

	if((*l) -> clas == classe)
		qtd++;
	
	return qtd;
}
