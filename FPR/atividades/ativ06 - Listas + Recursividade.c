/*
Atividade 6 - Recursividade + Listas

Desenvolver uma função recursiva que, dada uma lista encadeada L do tipo TLista, altere todas as ocorrências do valor
num1 por num2. Além disso, a função deve retornar a quantidade de alterações realizadas.

Nota: o tipo TLista consiste exatamente naquele trabalhado em nossas aulas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	
	int valor;
	struct No *prox;
		
}TNo;

typedef TNo* TLista;

// funções
int inserir(TLista *L, int valor);
void exibir(TLista L);
int trocarOcorrencias(TLista L, int num1, int num2);

void main(){
	
	TLista lista = NULL;
	int r;
	
	// fins de teste
	inserir(&lista, 18);
	inserir(&lista, 20);
	inserir(&lista, 19);
	inserir(&lista, 18);
	inserir(&lista, 18);	
	inserir(&lista, 98);
	inserir(&lista, 19);
	inserir(&lista, 18);
	
	r = trocarOcorrencias(lista, 18, 2);	
	// exibindo a lista
	exibir(lista);
	
	printf("\n\nQntd de alteracoes: %d", r);
}

int trocarOcorrencias(TLista L, int num1, int num2){
	
	// passo 1: caso base
	if(L == NULL){
		return 0;
	}
					
	// passo 2: caso geral			
	int alteracoes = 0;
	if(L->valor == num1){
		L->valor = num2;
		alteracoes = 1;	
	}
			
	return alteracoes + trocarOcorrencias(L->prox, num1, num2);
}

int inserir(TLista *L, int valor){
	
	TLista aux;
	
	aux = malloc(sizeof(TNo));	// alocando espaço na memória pro novo nó	
	
	if(!aux){
		return 0;		
	}else{
		
		aux->valor = valor; // Atribui o valor ao nó
		
		aux->prox = *L;	// O ponteiro do novo nó aponta para o primeiro nó da lista
		
		*L = aux;	// Atualiza o ponteiro da lista para o novo nó (agora ele é o primeiro)
		
		return 1;
	}
}

void exibir(TLista L){
	
	TLista aux = L;
		
	printf("\n*------------------------------*\n");
	printf("		Lista: ");
	
    if(aux == NULL){
        printf("Lista encadeada vazia");
        printf("\n*------------------------------*\n");
    }else{
    	
	    while(aux != NULL){
	        printf("%d, ", aux->valor);
	        aux = aux->prox;
	    }
	    printf("NULL");
	    printf("\n*------------------------------*\n");
	}
	
}
