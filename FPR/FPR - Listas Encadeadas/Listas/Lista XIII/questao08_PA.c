/*

QUESTÃO 08:
Implementar uma função que crie uma lista encadeada (dinâmica) com os N primeiros termos
de uma PA (progressão aritmética) de razão R e primeiro termo igual a A1.

*/

#include<stdio.h>
#include<stdlib.h>


// structs
typedef struct No{
	
	int valor;	
	struct No *prox;
	
}TNo;

typedef TNo* Tlista; 

// funções
Tlista criarListaPA(int a1, int r, int n);
void exibirLista(Tlista L);


void main(){
	
	Tlista lista = NULL;
	int r, a1, n;		
	
	printf("Insira o primeiro valor: ");
	scanf("%d", &a1);
	
	printf("\nInsira a razao: ");
	scanf("%d", &r);
	
	printf("\nInsira ate que elemento deve ser inserido na lista: ");
	scanf("%d", &n);
	
	lista = criarListaPA(a1, r, n);
	
	exibirLista(lista);		
	
}

Tlista criarListaPA(int a1, int r, int n){
	
	Tlista L = NULL, aux, novo;
	int i, termo;
	
	// inserindo o termo inicial
	L = malloc(sizeof(TNo));
	L->valor = a1;
	L->prox = NULL;
	aux = L;
		
	// preenchendo até o n-ésimo termo
	for(i = 2, termo = a1+r; i <= n; termo+=r, i++){
		
		novo = malloc(sizeof(TNo));
		
		novo->valor = termo;
		novo->prox = NULL;
		
		aux->prox = novo;
		aux = novo;
	}
	
	return L;
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
