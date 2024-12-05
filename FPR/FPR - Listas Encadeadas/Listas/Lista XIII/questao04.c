/*

QUESTÃO 04:
Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se estas são
iguais; isto é, contêm os mesmos elementos, na mesma ordem.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No {
	
	int valor;
	struct No *prox;
	
}TNo;

typedef TNo* Tlista;


// protótipos das funções
int inserir(Tlista *L, int numero);
void exibirListas(Tlista L);
int verificaListas(Tlista L1, Tlista L2);

void main(){
	
	Tlista lista1 = NULL, lista2 = NULL;
	
	inserir(&lista1, 2);
	inserir(&lista1, 3);
	
	inserir(&lista2, 2);
	inserir(&lista2, 3);
	
	
	exibirListas(lista1);
	exibirListas(lista2);
	
	if(verificaListas(lista1, lista2) == 1){
		printf("As listas sao iguais");
	}else{
		printf("As listas sao diferentes");
	}
}

int inserir(Tlista *L, int numero){
	
	Tlista aux;
	
	// aloca espaço na memória para um novo nó
	aux = malloc(sizeof(TNo));
	
	// verifica se o espaço foi corretamente alocado
	if(!aux){
		return 0;
	}else{
		
		aux->valor = numero;	// atribui o valor a ser adicionado na variavel auxiliar
		
		aux->prox = *L;			// o ponteiro pro proximo nó de aux recebe o antigo primeiro nó
		
		*L = aux;				// atualiza o ponteira da lista pro primeiro nó
		
		return 1;
	}
	
	
}

int verificaListas(Tlista L1, Tlista L2){		
	
	// percorre as listas
	while(L1 && L2){
		
		// verifica se os valores são diferentes
		if(L1->valor != L2->valor){
			return 0;	// as listas são diferentes
		}
		L1 = L1->prox;
		L2 = L2->prox;
	}
	
	// verifica se uma lista terminou antes da outra
	if(L1 != NULL || L2 != NULL){
		return 0;
	}
	return 1;
}

void exibirListas(Tlista L){
	
	Tlista aux = L;
	
	printf("\n\nLista Encadeada: ");
	if(aux)
	{
		while(aux){
			printf("%d, ", aux->valor);
			aux = aux->prox;
		}
		printf("NULL\n");
	}else{
		printf("Lista Vazia");
	}
}


