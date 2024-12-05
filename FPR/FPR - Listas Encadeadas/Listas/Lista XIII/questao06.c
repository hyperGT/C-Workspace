/*

QUEST�O 06:
Desenvolver uma fun��o que, dada uma lista L1, crie uma nova lista L2, c�pia de L1.

*/

#include<stdio.h>
#include<stdlib.h>


// structs
typedef struct No{
	
	int valor;	
	struct No *prox;

}TNo;

typedef TNo* Tlista; 

// funcoes
int inserir(Tlista *L, int numero);
void exibirListas(Tlista L);
int copiaLista(Tlista L1, Tlista *L2);

void main(){
	
	Tlista lista = NULL, listaCpy = NULL;
	
	inserir(&lista, 1);
	inserir(&lista, 2);
	inserir(&lista, 3);
	inserir(&lista, 4);
	
	exibirListas(listaCpy);
	
	if(copiaLista(lista, &listaCpy) == 1){
		printf("Lista 1 copiada para lista 2 com sucesso\n\n");		
	}else{
		printf("Falha ao copiar a lista 1 para a lista 2\n\n");
	}
	
	
	exibirListas(lista);
	
	exibirListas(listaCpy);
}

int copiaLista(Tlista L1, Tlista *L2){
	
	Tlista tmpL1 = L1, novoNo, ultimoNo = NULL;
	
	if(!tmpL1) return 0;	// verifica se a lista n�o est� vazia
	
	while(tmpL1){
				
		novoNo = malloc(sizeof(TNo));	// Aloca mem�ria para o novo n�
				
		if(!novoNo){	
			return 0;	// Falha na aloca��o
		}
		
		// copia o valor do n�
		novoNo->valor = tmpL1->valor;	
		novoNo->prox = NULL;			
		
		// insere o novo n� na lista 2
		if(!(*L2)){
			*L2 = novoNo;
		}else{
			ultimoNo->prox = novoNo;
		}
		
		ultimoNo = novoNo;		// Atualiza o �ltimo n� para o rec�m-criado
		tmpL1 = tmpL1->prox;	// avan�a para o pr�x n�
	}
	
	return 1; // deu tudo certo
}


int inserir(Tlista *L, int numero){
	
	Tlista tmp;
	
	tmp = malloc(sizeof(TNo));
	
	if(!tmp) return 0;
	
	tmp->valor = numero;
	
	tmp->prox = *L;
	
	*L = tmp;		
}

void exibirListas(Tlista L){
	
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
