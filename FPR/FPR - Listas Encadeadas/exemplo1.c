#include <stdio.h>
#include <stdlib.h>

// definindo tipos
typedef struct No{

    int valor;
    struct No *prox;

}TNo;

typedef TNo* Tlista;

// funções
int inserir(Tlista *L, int valor);
void exibir(Tlista L);

void main(){

    Tlista lista =  NULL;    

    /* MENU */
    inserir(&lista, 10);
    inserir(&lista, 20);

    exibir(lista);

}

int inserir(Tlista *L, int valor){

    Tlista aux;

    // alocar memoria pro novo nó
    aux = malloc(sizeof(TNo));

    if(!aux){
        return 0;
    }else{
        
        aux->valor = valor;     // Atribui o valor ao nó
        
        aux->prox = *L;         // O ponteiro do novo nó aponta para o primeiro nó da lista

        *L = aux;               // Atualiza o ponteiro da lista para o novo nó (agora ele é o primeiro)

        return 1;
    }


}

void exibir(Tlista L){

    Tlista aux = L;

    if(aux == NULL){
        printf("Lista encadeada está vazia");
    }

    while(aux != NULL){
        printf("%d, ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}