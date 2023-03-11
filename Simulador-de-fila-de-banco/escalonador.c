#include "escalonador.h"

/*Inicializa o escalonador, alocando e inicializando as 5 filas, que serão atendidas por “caixas” caixas,
  onde cada operação é tratada em “delta_t” minutos por um caixa, e o escalonamento utiliza a Disciplina de 
  Atendimento representada por {n_1; n_2; n_2; n_4; n_5}, nos termos do que foi definido na página 1 deste 
  enunciado.*/
void e_inicializar (Escalonador *e, int caixas, int delta_t, int n_1, int n_2, int n_3, int n_4, int n_5){
	f_inicializar(&(e -> fpremium));
	f_inicializar(&(e -> fouro));
	f_inicializar(&(e -> fprata));
	f_inicializar(&(e -> fbronze));
	f_inicializar(&(e -> fleezu));
	e -> caixas = caixas;
	e -> delt = delta_t;
	e -> n[0] = n_1;
	e -> n[1] = n_2;
	e -> n[2] = n_3;
	e -> n[3] = n_4;
	e -> n[4] = n_5;
	e -> natual = 0;		 /*Inicia na primeira disciplina*/
}


/*Insere na fila “classe” o cliente de número “num_conta”, que pretende realizar “qtde_operacoes” operações
  bancárias. Retorna 1 se a inserção for bem sucedida e 0 se houver algum problema (duplicação de chave ou falta de memória).*/
int e_inserir_por_fila (Escalonador *e, int classe, int num_conta, int qtde_operacoes){
	int resp = 0;
	
	switch(classe){
		case 1: 
			resp = f_inserir(&(e -> fpremium), num_conta, qtde_operacoes);
			break;
		case 2: 
			resp = f_inserir(&(e -> fouro), num_conta, qtde_operacoes);
			break;
		case 3: 
			resp = f_inserir(&(e -> fprata), num_conta, qtde_operacoes);
			break;
		case 4: 
			resp = f_inserir(&(e -> fbronze), num_conta, qtde_operacoes);
			break;
		case 5: 
			resp = f_inserir(&(e -> fleezu), num_conta, qtde_operacoes);
			break;
	}
	return resp;
}


/*
  Retorna o número da conta do próximo cliente a ser atendido de acordo com a Disciplina de Atendimento,
  retirando-o da sua respectiva fila. Retorna -1 se tiver não tiver clientes na fila.*/
int e_obter_prox_num_conta(Escalonador *e){
	int conta;

	switch(e -> natual){
		case 0:
			conta = f_obter_proxima_chave(&(e -> fpremium));
			break;
		case 1:
			conta = f_obter_proxima_chave(&(e -> fouro));
			break;
		case 2:
			conta = f_obter_proxima_chave(&(e -> fprata));
			break;
		case 3:
			conta = f_obter_proxima_chave(&(e -> fbronze));
			break;
		case 4:
			conta = f_obter_proxima_chave(&(e -> fleezu));
	}
	
	return conta;
}


/*Retorna o número da conta do próximo cliente a ser atendido de acordo com a Disciplina de Atendimento,
  sem retirá-lo da sua respectiva fila. Retorna -1 se tiver não tiver clientes na fila.*/
int e_consultar_prox_num_conta (Escalonador *e){
	int conta;
	
	switch(e -> natual){
		case 0:
			conta = f_consultar_proxima_chave(&(e -> fpremium));
			break;
		case 1:
			conta = f_consultar_proxima_chave(&(e -> fouro));
			break;
		case 2:
			conta = f_consultar_proxima_chave(&(e -> fprata));
			break;
		case 3:
			conta = f_consultar_proxima_chave(&(e -> fbronze));
			break;
		case 4:
			conta = f_consultar_proxima_chave(&(e -> fleezu));
	}
	
	return conta;
}


/*Retorna a quantidade de operações bancárias que o próximo cliente das filas pretende realizar com o caixa,sem retirá-lo da sua respectiva fila.*/
int e_consultar_prox_qtde_oper (Escalonador *e){
	int oper;
	
	switch(e -> natual){
		case 0:
			oper = f_consultar_proximo_valor(&(e -> fpremium));
			break;
		case 1:
			oper = f_consultar_proximo_valor(&(e -> fouro));
			break;
		case 2:
			oper = f_consultar_proximo_valor(&(e -> fprata));
			break;
		case 3:
			oper = f_consultar_proximo_valor(&(e -> fbronze));
			break;
		case 4:
			oper = f_consultar_proximo_valor(&(e -> fleezu));
	}
	
	if( oper == -1 ) /* Fila vazia, a próxima quantidade de operações é 0 */
		return 0;
	else
		return oper;
}


/*Retorna a próxima fila que será atendida de acordo com a Disciplina de Atendimento.*/
int e_consultar_prox_fila (Escalonador *e){
	int prox;

	if(e -> natual == 4){		/*Já atendeu os n_5 clientes da última fila, vai para a primeira*/ 
		e -> natual = 0;
		prox = e -> n[0];
	}
	else{			/*Já atendeu os n_ clientes das outras filas, vai para a próxima*/
		e -> natual = (e -> natual) + 1;
		prox = e -> n[(e -> natual)];
	}
	
	return prox;
}


/*Retorna a quantidade total (soma) de clientes esperando atendimento em todas as filas.*/
int e_consultar_qtde_clientes (Escalonador *e){
	int tpre, tour, tpra, tbro, tlee;

	tpre = f_num_elementos(&(e -> fpremium));
	tour = f_num_elementos(&(e -> fouro));
	tpra = f_num_elementos(&(e -> fprata));
	tbro = f_num_elementos(&(e -> fbronze));
	tlee = f_num_elementos(&(e -> fleezu));
	
	return (tpre + tour + tpra + tbro + tlee);
}


/*Retorna o tempo necessário para que o próximo cliente a ser atendido realize todas as operações 
  financeiras que deseja, sem retirá-lo da sua respectiva fila.
  Retornar -1 caso não tenha nenhum cliente em todas as filas.*/
int e_consultar_tempo_prox_cliente (Escalonador *e){
	int aux, tempo, op;
	
	/*Consulta se todas as 5 filas estão vazias*/
	if(f_consultar_proximo_valor(&(e -> fpremium)) == -1)
		if(f_consultar_proximo_valor(&(e -> fouro)) == -1)
			if(f_consultar_proximo_valor(&(e -> fprata)) == -1)
				if(f_consultar_proximo_valor(&(e -> fbronze)) == -1)
					if(f_consultar_proximo_valor(&(e -> fleezu)) == -1)
						return -1;
	
	op = e_consultar_prox_qtde_oper(e);
	tempo = op * (e -> delt);
	
	return tempo;
}


/*Realiza a configuração de inicialização do escalonador através da leitura do arquivo de configuração
  de nome “nome_arq_conf”, retornando 1 em caso de sucesso e 0 caso contrário.*/
int e_conf_por_arquivo (Escalonador *e, char *nome_arq_conf){
	FILE *arq;
	int q_cx, dt, conta, ops, classe_int, esc[5];
	char classe[8];

	if ( (arq = fopen(nome_arq_conf, "r")) == NULL ) return 0;

	if(fscanf(arq, "qtde de caixas = %d\n", &q_cx) == EOF)		return 0;
	if(fscanf(arq, "delta t = %d\n", &dt) == EOF)				return 0;
	if(fscanf(arq, "disciplina de escalonamento = {%d,%d,%d,%d,%d}\n", &esc[0], &esc[1], &esc[2], &esc[3], &esc[4]) == EOF)		return 0;
	
	e_inicializar(e, q_cx, dt, esc[0], esc[1], esc[2], esc[3], esc[4]);

	while ( fscanf(arq, "%s - conta %d - %d operacao(oes)\n", classe, &conta, &ops) != EOF ) {
		if		( strcmp(classe, "Premium") == 0 )	classe_int = 1;
		else if ( strcmp(classe, "Ouro"   ) == 0 )	classe_int = 2;
		else if ( strcmp(classe, "Prata"  ) == 0 )	classe_int = 3;
		else if ( strcmp(classe, "Bronze" ) == 0 )	classe_int = 4;
		else if ( strcmp(classe, "Leezu"  ) == 0 )	classe_int = 5;
		e_inserir_por_fila(e, classe_int, conta, ops);
	}
	
	fclose(arq);
	return 1;
}

/*Executar a simulação do atendimento, lendo o arquivo de configuração de nome “nome_arq_in” e escrevendo
  o resultado do processamento para arquivo de nome “nome_arq_out”.*/
void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out){
	int i, conta, oper, naux;
	int tempo = 0, aux_oper;	/*Armazena a quantidade de operações pendentes no instante "tempo"*/
	int tot_cli[5];
	float temp_esp[5], tot_oper[5];
	const char *str_fila[] = {  "Premium", "Ouro", "Prata", "Bronze", "Leezu"  };
	Caixa *cxs;
	Log *registrador;
	FILE *arq_saida;

	if(!e_conf_por_arquivo(e, nome_arq_in))					return;
	if((arq_saida = fopen(nome_arq_out, "a+")) == NULL)		return;

	log_inicializar(&registrador);
	if(!c_inicializar(&cxs, e -> caixas))		return;

	/* Inicializa a quantidade total de operações de todas as filas */
	for(i = 0; i < 5; i++)		tot_oper[i] = 0;
	
	tot_cli[0] = f_num_elementos(&e -> fpremium);
	tot_cli[1] = f_num_elementos(&e -> fouro);
	tot_cli[2] = f_num_elementos(&e -> fprata);
	tot_cli[3] = f_num_elementos(&e -> fbronze);
	tot_cli[4] = f_num_elementos(&e -> fleezu);
	
	naux = e -> n[0];	/*Quantidade primária de clientes a serem atendidos será a disciplina Premium*/
	
	while( e_consultar_tempo_prox_cliente(e) != - 1 ){	/* Repete até atender todas as filas */
		
		while( naux > 0 ){	/* Realiza os atendimentos da fila atual enquanto houver alguém determinado pela disciplina */
			aux_oper = e_consultar_prox_qtde_oper(e);
			tot_oper[e -> natual] += aux_oper; 		/* Contabiliza a quantidade de operações por fila */
			conta = e_obter_prox_num_conta(e);
			naux--;									/* Um cliente a menos atendido */
			if(conta != -1){
				oper = c_realizar_prox_operacao(&cxs);
				tempo += (oper * e -> delt);
				i = c_obter_prox_caixa(&cxs);
				cxs[i].oper = aux_oper;		/* Cliente entra no caixa i para realizar aux_oper operações */
				cxs[i].qtd_atendidos += 1;  /* Contabiliza +1 cliente atendido no caixa i */
				log_registrar(&registrador, conta, e -> natual, tempo, i + 1);
				fprintf(arq_saida, "T = %d min: Caixa %d chama da categoria %s cliente da conta %d para realizar %d operacao(oes).\n", tempo, i + 1, str_fila[e -> natual], conta, aux_oper );
			}
		}
		naux = e_consultar_prox_fila(e);
	}

	oper = c_obter_oper_ultimo_cliente(&cxs);
	tempo += (oper * e -> delt);
	
	fprintf(arq_saida, "Tempo total de atendimento: %d minutos.\n", tempo);

	for(i = 0; i < 5; i++){
		temp_esp[i] = log_media_por_classe(&registrador, i);
		fprintf(arq_saida, "Tempo medio de espera dos %d clientes %s: %.2f\n", tot_cli[i], str_fila[i], temp_esp[i]);
	}

	for(i = 0; i < 5; i++)
		fprintf(arq_saida, "Quantidade media de operacoes por cliente %s = %.2f\n",str_fila[i], (tot_oper[i] /tot_cli[i]));
	
	for(i = 0; cxs[i].oper != - 1; i++)
		fprintf(arq_saida, "O caixa de número %d atendeu %d clientes.\n", i + 1, c_obter_num_atendidos(&cxs, i));
	
	fclose(arq_saida);
}
