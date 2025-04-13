#include <stdio.h>
#include <stdlib.h>
#include "ListaSECC.h"

#define TRUE 1
#define FALSE 0

// definição de tipos
struct tno {
    int valor;
    tNo *prox;
}

struct LSE {
    tNo *prim;
    int qtdNos;
    int isClassif;
    int temRep;
}

// protótipos das funções auxiliares
/* Cria um novo nó com as informações necessárias */
tNo * criaNo(int valor);

/* Realiza uma busca rapida pela lista
	Retorna TRUE ou FALSE, dependendo se o valor buscado for encontrado
*/
int buscaRapida(tLSE *l, int num, tNo** ponteiroAnterior);

// funções principais
tLSE * lse_criar_lista(int classificada, int repete){
    tLSE *pl = (tLSE *) malloc(sizeof(tLSE));
    
    if(pl){
        pl->qtdNos = 0;
        pl->prim = criaNo(0);   // cria o nó "cabeça"
        pl->isClassif = classificada;
        pl->temRep = repete;
        pl->prim->prox = pl->prim;
    }
    return pl;
}

/* Verifica se uma lista está vazia */
void lse_lista_vazia(const tLSE *l){
	return (l->qtdNos == 0);
}

// funções secundárias/auxiliares
tNo * criaNo(int valor){
    tNo *no = (tNo *) malloc(sizeof(tNo));
    
    if(no){
        no->prox = NULL;
        no->valor = valor;
    }
    return no;
}

int buscaRapida(tLSE *l, int num, tNo** ponteiroAnterior){	
	tNo *ponteiroAux, *pTemp;
	l->prim->valor = num;
	
	if(lse_classificada(l)){
		ponteiroAux = l->prim->prox;
		pTemp = l->prim;
		while(ponteiroAux->valor < num){
			pTemp = ponteiroAux;
			ponteiroAux = ponteiroAux->prox;
		}
	}else{
		ponteiroAux = l->prim->prox;
		pTemp = l->prim;
		while(ponteiroAux->valor != num){
			pTemp = ponteiroAux;
			ponteiroAux = ponteiroAux->prox;
		}
	}
	(*ponteiroAnterior) = pTemp; // atualiza o ponteiro pro nó anterior
	
	return (p != l->prim && p->num == num);	// Retorna 1 se encontrou e 0 caso contrário
}
