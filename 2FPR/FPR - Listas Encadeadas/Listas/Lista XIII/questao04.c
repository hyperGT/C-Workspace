/*

QUEST�O 04:
Implementar uma fun��o que, dadas duas listas din�micas do tipo TLista, verifique se estas s�o
iguais; isto �, cont�m os mesmos elementos, na mesma ordem.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No {
	
	int valor;
	struct No *prox;
	
}TNo;

typedef TNo* Tlista;


// prot�tipos das fun��es
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
	
	// aloca espa�o na mem�ria para um novo n�
	aux = malloc(sizeof(TNo));
	
	// verifica se o espa�o foi corretamente alocado
	if(!aux){
		return 0;
	}else{
		
		aux->valor = numero;	// atribui o valor a ser adicionado na variavel auxiliar
		
		aux->prox = *L;			// o ponteiro pro proximo n� de aux recebe o antigo primeiro n�
		
		*L = aux;				// atualiza o ponteira da lista pro primeiro n�
		
		return 1;
	}
	
	
}

int verificaListas(Tlista L1, Tlista L2){		
	
	// percorre as listas
	while(L1 && L2){
		
		// verifica se os valores s�o diferentes
		if(L1->valor != L2->valor){
			return 0;	// as listas s�o diferentes
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


