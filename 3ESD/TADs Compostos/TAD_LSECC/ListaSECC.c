#include <stdio.h>
#include <stdlib.h>
#include "ListaSECC.h"

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
tNo * criaNo(int valor);

// funções principais
tLSE * lse_criarLista(int classificada, int repete){
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

// funções secundárias/auxiliares
tNo * criaNo(int valor){
    tNo *no = (tNo *) malloc(sizeof(tNo));
    
    if(no){
        no->prox = NULL;
        no->valor = valor;
    }
    return no;
}
