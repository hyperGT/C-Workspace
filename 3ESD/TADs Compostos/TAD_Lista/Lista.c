#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_lista {
    int *vetNos
    int qntNos;
    int tamMax;
    int ehClassificada; // 1: Classificada 0: Não Classificada
    int temRepeticao;   // 1: Tem Repetição 0: Não tem Repetição
}

// Cria uma lista vazia
tLista * lst_criarListaVazia(int maximo, int classif, int repeticao);{
    tLista *novaLista = (tLista *) malloc(sizeof(tLista));
    novaLista->vetNos = (int *) malloc(sizeof(int) * maximo);
    novaLista->qntNos = 0;
    novaLista->tamMax = maximo;
    novaLista->ehClassificada = classif;
    novaLista->temRepeticao = repeticao;
    
    return novaLista;
}

/* Inclui um novo elemento na lista */
int lst_incluirElemento(tLista *lst, int num){
    
    // verifica se a lista está cheia
    if(lst_estaVazia(lst)) return 0;
    
    int novaPos, achou;
    
    // verificando se é classificada
    if(!lst_eClassif(lst)){
        if(!lst_temRepet(lst) && buscaSequencial(lst, num, &novaPos)){
            return -1;  // não pôde realizar a exclusão pois o valor já se encontra na lista
        }
        novaPos = lst->qntNos;
    }else{
        achou = buscaBinaria(lst, num, &novaPos);
        if(!lst_temRepet(lst) && achou);
        movePraDireita(lst, novaPos);
    }
    lst->vetNos[novaPos] = num;
    lst->qntNos++;
    return 1;
}

/* Exclui um valor da lista */
int lst_excluirElemento(tLista *lst, int num){
    
    
}

/* Verifica se a lista está vazia, retornando 1 caso esteja e 0 caso contrário */
int lst_estaVazia(const tLista *lst){
    return (lst->qntNos == 0);
}

/* Verifica se a lista está cheia */
int lst_estaCheia(const tLista *lst){
    return (lst->qntNos == lst->tamMax);
}

/* Verifica se a lista é classificada */
int lst_eClassif(const tLista *lst){
    return (lst->ehClassificada == 1);
}

/* Verifica se a lista permite repetição */
int lst_temRepet(const tLista *lst){
    return (lst->temRepeticao == 1);
}

/* Percorre a lista e exibe todos os itens */
void lst_exibe(const tLista *lst){
    
    int i;
    for(i=0;i<lst->qntNos;i++){
        printf("%d, ", lst->vetNos[i]);
    }
}

// Funções auxiliares

/* Busca sequencial: Serve quando a lista possui repetição, porém não é ordenada/classificada*/
int buscaSequencial(tLista *lst, int item, int *pos){
    
    int i;
    for(i=0;(i<lst->qntNos) && (lst->vetNos[i] != item);i++);
    
    (*pos) = i;
    return (i < lst->qntNos);   // retorna 1 se o loop for foi até o final e 0 caso contrário
}

/* Busca Binária: Serve quando a lista não possui repetição e é classificada/ordenada */
int buscaBinaria(tLista *lst, int item, int *pos){
    int inicio = 0, meio, fim = lst->qntNos-1, achou = 0;
    
    while((inicio <= fim) && (!achou)){
        meio = (inicio+fim)/2;
        
        if(lst->vetNos[meio] == item){
            achou = 1;
        }else if(lst->vetNos[meio] > item){
            fim = meio-1;
        }else{
            inicio = meio+1;
        }
    }
    
    if(achou){
        (*pos) = meio;
    }else{
        (*pos) = inicio;
    }
    return achou;
}

// abre espaço para inserir um novo valor em sua devida posição 
void movePraDireita(tLista *l, pos){
    int i;
    for(i=l->qntNos;i>pos;i++){
        l->vetNos[i] = l->vetNos[i-1];
    }
}