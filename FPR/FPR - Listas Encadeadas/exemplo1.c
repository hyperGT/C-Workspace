#include <stdio.h>
#include <stdlib.h>

// definindo tipos
typedef struct No{

    int valor;
    struct No *prox;

}TNo;

typedef TNo* Tlista;

// fun��es 
int menu ();
int inserir(Tlista *L, int valor);
int removerUm(Tlista *L, int valor);
int removerTodos(Tlista *L, int valor);
int alterar(Tlista L, int novoValor, int antValor);
int buscar(Tlista L, int valor);
void exibirLista(Tlista L);

void main(){

    Tlista lista =  NULL;    
    int resp, novo, ant, value;
	
	do{
		
		system ("CLS");	// limpa o prompt
		
		/* LISTA */
		exibirLista(lista);
				
	    /* MENU */
		resp = menu();
		
		switch(resp){
			
			case 1: // inserir
		
				printf("Enter a value to add to the list: ");
				scanf("%d", &value);
				
				if(inserir(&lista, value)){
					printf("Value inserted sucessfully. \n");
				}else{
					printf("Failed to insert a value. \n");
				}
				
				break;			
			case 2:	{	// alterar

				printf("Enter the value to update: ");
				scanf("%d", &ant);
				printf("Enter the new value: ");
				scanf("%d", &novo);

				int c = alterar(lista, novo, ant);

				if(c>0){
					printf("Numero de alteracoes: %d\n", c);
				}else{
					printf("Numero de alteracoes: 0\n");	
				}

				break;
			}
			case 3: // remover apenas uma vez o elemento
			
				printf("Enter the value to remove: ");
				scanf("%d", &value);
				
				if(removerUm(&lista, value)){
					printf("Valor foi devidamente removido\n");
				}else{
					printf("Valor inserido nao encontrado\n");
				}
			
				break;
			case 4: {
				printf("Enter a value to remove all the occurrences: ");
				scanf("%d", &value);
				
				int cnt = removerTodos(&lista, value);
				
				if(cnt>0){
					printf("Quantidade de valores removidos: %d\n", cnt);
				}else{
					printf("Nenhum valor encontrado\n");
				}
				
				break;
			}
			case 5:
				
				printf("Enter a value to search: ");
				scanf("%d", &value);
				
				if(buscar(lista, value)){
					printf("Valor encontrado");					
				}else{
					printf("Valor nao encontrado");
				}
				
				break;
			case 6:
				printf("Saindo do programa...");				
				break;		
			default:
				printf("Valor invalido, por favor tente novamente");
				break;
		}
		
		system("PAUSE");
		
	}while(resp!=6);
}

int buscar(Tlista L, int valor){
	
	Tlista aux = L;	
	
	while(aux != NULL){
		
		if(aux->valor == valor){
			
			return 1; 	// valor encontrado
			
		}else{
			aux = aux->prox;
		}
	}
	
	return 0;	// valor n�o encontrado
}

int removerTodos(Tlista *L, int valor){
	
	Tlista a1, a2;
	int cont = 0;
	
	// Remove o valor enquanto ele estiver no come�o da lista
	while((*L) != NULL && (*L)->valor == valor){
		
		a1 = *L
		
		*L = (*L)->prox;
		free(a1);
		cont++;
	}
	
	if(*L){  // ou:		*L != NULL
		
		a2 = *L;	// guarda o primeiro n� 
		a1 = a2->prox;	 // guarda o pr�x n�
		
		// percorre toda a lista
		while(a1 != NULL){
			
			if(a1->valor == valor){
				
				a2->prox = a1->prox;	// n� anterior recebe o pr�ximo	
				cont++;
				free(a1);
				
				// indo pro pr�x n�
				a1 = a2->prox;
				
			}else{
				a2 = a1;
				a1 = a1->prox;
			}
		}
	}
	return cont;
}

int menu (){
	
	int r;			
	
	printf("\n+------------------------------+\n");
	
	printf("1: Insert \n");
	printf("2: Update \n");
	printf("3: Remove One \n");
	printf("4: Remove ALL \n");
	printf("5: Search \n");	
	printf("6: Exit \n");
	printf("\nEnter the operation: ");
	scanf("%d", &r);
	
	printf("\n+------------------------------+\n");
	
	return r;
}

int removerUm(Tlista *L, int valor){
	
	Tlista auxAnt = NULL;
	Tlista aux = *L;
	
	while(aux != NULL){
					
		
		if(aux->valor == valor){
			
			if(auxAnt == NULL){
				
				// caso especial: caso seja necess�rio remover o primeiro n�
				*L = aux->prox;
				
			}else{
				auxAnt->prox = aux->prox;	// liga o n� anterior com o pr�ximo 
			}
			
			free(aux);		// libera a mem�ria do n� removido
			return 1;
		}else{
			auxAnt = aux;	// atualiza o anterior para o atual
			aux = aux->prox;	// atualiza o atual para o pr�ximo
		}
		
	}
	
	return 0; 	// valor n�o encontrado
}

int inserir(Tlista *L, int valor){
	
	Tlista aux;
	
    // alocar memoria pro novo n�
    aux = malloc(sizeof(TNo));
	
    if(!aux){
        return 0;
    }else{
        
        aux->valor = valor;     // Atribui o valor ao n�
        
        aux->prox = *L;         // O ponteiro do novo n� aponta para o primeiro n� da lista

        *L = aux;               // Atualiza o ponteiro da lista para o novo n� (agora ele � o primeiro)

        return 1;
    }
}

int alterar(Tlista L, int novoValor, int antValor){
	
	Tlista aux = L;		// guarda a lista
	int cont = 0;		// guarda a qnt de valores alterados
	
	while(aux != NULL){		
		
		if(aux->valor == antValor){		// caso encontre o valor
				
			aux->valor = novoValor;
			
			// atualiza a qnt de trocas
			cont++;
			
		}
		aux = aux->prox;	// segue pro pr�x n�
	}
	return cont;
}

void exibirLista(Tlista L){

    Tlista aux = L;
    
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
