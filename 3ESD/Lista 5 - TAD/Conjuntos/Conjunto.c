/******************************************************************************
Gabriel Teixeira Charles da Silva
*******************************************************************************/

#include "Conjunto.h"
#include <stdio.h>
#include <stdlib.h>

// Implementação TAD: Conjunto
/*
 * Definição do tipo
*/
struct conj{
    int vet[80];
    int qntElementos;
};



/*
* Funções auxiliares
*/

int buscaElemento (Conjunto*c, int num){
    
    int i;
    for(i=0; i<c->qntElementos; i++){
        if(c->vet[i] == num){
            return i;
        }
    }
    return -1;
}


// ########### Funções do TAD ############# 

// cria um conjunto de numeros inteiros vazio
Conjunto * conj_cria(){
  Conjunto *p = (Conjunto *) malloc(sizeof(Conjunto));
  
  p->qntElementos=0;
  
  return p;
} 

//exibe um conjunto de numeros inteiros
void conj_exibe(Conjunto *c){
    
    int i;
    
    for(i = 0; i < c->qntElementos;i++)
        printf("%i, ", c->vet[i]);
    printf("\n\n");
} 

//insere um novo elemento num conjunto ja criado
Conjunto * conj_insere(Conjunto *c,int num){
    if(c->qntElementos < 80 && buscaElemento(c, num) == -1){
        c->vet[c->qntElementos] = num;
        c->qntElementos++;
        return c;
    }
    
    return c;
    
} //insere um novo elemento num conjunto ja criado


//remove um elemento de um conjunto de inteiros. Se o elemento nao existir, retornar o conjunto intacto
Conjunto * conj_remove(Conjunto *c, int num){
    
    int pos = buscaElemento(c, num);
    
    // verifica se a posição é inválida
    if(pos == -1){
        return c;
    }
        
    // insere o ultimo elemento do conjunto na posição do elemento a ser removido
    c->vet[pos] = c->vet[c->qntElementos];
        
    // atualiza a quantidade de elementos
    c->qntElementos--;
    return c;
    
} 

//cria o conjunto que e dado pela uniao dos dois conjuntos enviados como parametro
Conjunto *conj_uniao(Conjunto *a, Conjunto *b){
    
    Conjunto *uniaoAB = conj_cria();    // conjunto da uniao AB
    
    if(uniaoAB == NULL) return NULL; // verifica se a memória foi alocada
    
    int i;
    
    // insere todos os elementos do primeiro conjunto ao conjunto AB
    for(i=0;i<a->qntElementos;i++){
        uniaoAB = conj_insere(uniaoAB, a->vet[i]);
    }
    
    // percorre o conjunto B afim de encontrar e inserir no conjunto uniaoAB valores que não se encontram no conjunto A 
    for(i=0; i<b->qntElementos; i++){
        
        if(buscaElemento(a, b->vet[i]) == -1){
            uniaoAB = conj_insere(uniaoAB, b->vet[i]);
        }
    }
    
    return uniaoAB;
} 

//cria o conjunto que e dado pela intersecao dos dois conjuntos enviados como parametro
Conjunto *conj_intersecao(Conjunto *a, Conjunto *b){ 

    Conjunto * interAB = conj_cria();
    
    if(interAB == NULL) return NULL;
    
    int i;
    for(i=0;i<b->qntElementos;i++){
        
        if(buscaElemento(a, b->vet[i]) != -1){
            interAB = conj_insere(interAB, b->vet[i]);
        }
    }
    
    return interAB;
}




