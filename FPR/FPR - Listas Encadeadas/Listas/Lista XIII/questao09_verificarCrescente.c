/*

QUEST�O 09:
Implementar uma fun��o que, dada uma lista din�mica do tipo TLista, verifique se os elementos
da estrutura encontram-se ordenados de forma crescente ou n�o.

*/

#include<stdio.h>
#include<stdlib.h>


// structs
typedef struct No{
	
	int valor;	
	struct No *prox;
	
}TNo;

typedef TNo* Tlista;

// fun��es
int verificaOrdemLista(Tlista L);
int inserir(Tlista *L, int numero);
void exibirLista(Tlista L);


void main(){
	
	Tlista lista = NULL;
	
	inserir(&lista, 4);
	inserir(&lista, 3);
	inserir(&lista, 2);
	inserir(&lista, 1);
	
	exibirLista(lista);	
	
	if(verificaOrdemLista(lista) == 1){
		printf("Esta ordenado crescentemente.\n");
	}else{
		printf("Nao esta ordenado.\n");
	}
	
}

int verificaOrdemLista(Tlista L){
	
	if(!L || !L->prox){
		return 1; 
	}
	
	Tlista aux = L->prox;
	int valorAnterior = L->valor;
	
	while(aux){
				
		if(valorAnterior > aux->valor){
			return 0; // n�o est� ordenado 
		}
		
		valorAnterior = aux->valor;
		aux = aux->prox;
	}
	return 1;
}

int inserir(Tlista *L, int numero){

	Tlista aux;
	
	aux = malloc(sizeof(TNo));
	
	if(!aux) return 0;
	
	aux->valor = numero;
	
	aux->prox = *L;
	
	*L = aux;
}

void exibirLista(Tlista L){
	
	Tlista tmp = L;
	
	if(tmp){		
		printf("Lista: ");
		while(tmp){
			printf("%d, ", tmp->valor);
			tmp = tmp->prox;
		}
		printf("NULL\n");
	}else{
		printf("Lista Vazia\n\n");		
	}
	
}
