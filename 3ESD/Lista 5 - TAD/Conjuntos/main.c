/******************************************************************************
Gabriel Teixeira Charles da Silva
*******************************************************************************/
#include <stdio.h>
#include "Conjunto.h"

int main()
{
    
    Conjunto *A = conj_cria(), *B = conj_cria(), *unionAB = conj_cria(), *interAB = conj_cria();
    int i;
    
    for(i=0; i<10; i++){
        A = conj_insere(A, i*2);
        B = conj_insere(B, i*1);
    } 
    
    conj_exibe(A);
    conj_exibe(B);
    
    unionAB = conj_uniao(A, B);
    
    conj_exibe(unionAB);
    
    
    interAB = conj_intersecao(A, B);
    
    conj_exibe(interAB);
    
    
    return 0;
}