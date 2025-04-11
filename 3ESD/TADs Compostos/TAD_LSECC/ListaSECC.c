#include <stdio.h>
#include <stdlib.h>
#include "ListaSECC.h"

// defini��o de tipos
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

// prot�tipos das fun��es auxiliares
tNo * criaNo(int valor);

// fun��es principais
tLSE * lse_criarLista(int classificada, int repete){
    tLSE *pl = (tLSE *) malloc(sizeof(tLSE));
    
    if(pl){
        pl->qtdNos = 0;
        pl->prim = criaNo(0);   // cria o n� "cabe�a"
        pl->isClassif = classificada;
        pl->temRep = repete;
        pl->prim->prox = pl->prim;
    }
    return pl;
}

// fun��es secund�rias/auxiliares
tNo * criaNo(int valor){
    tNo *no = (tNo *) malloc(sizeof(tNo));
    
    if(no){
        no->prox = NULL;
        no->valor = valor;
    }
    return no;
}
