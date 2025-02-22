#include <stdio.h>
#include <stdlib.h>

// structs
typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* Tlista;

// Fun��es
int inserir(Tlista *L, int numero, int pos);
void exibirListas(Tlista L);

int main() {
	
    Tlista lista = NULL;
	int r, p;
	
	/*Populando a lista*/
	inserir(&lista, 1, 1);
	inserir(&lista, 2, 1);
	inserir (&lista, 10, 1);
	inserir (&lista, 20, 1);
	inserir (&lista, 30, 4);
	inserir (&lista, 40, 2);
	inserir (&lista, 50, 3);
	
	exibirListas(lista);		
	
	printf("Qual valor deseja inserir? valor: ");
	scanf("%d", &r);
	
	printf("\nEm qual posicao? Posicao: ");
	scanf("%d", &p);
	
	inserir(&lista, r, p);
	
	exibirListas(lista);

    return 0;
}

int inserir(Tlista *L, int numero, int pos) {
    if (pos < 1) {
        return 0; // Posi��o inv�lida
    }

    Tlista novoNo = malloc(sizeof(TNo));
    if (!novoNo) {
        return 0; // Falha na aloca��o de mem�ria
    }
    novoNo->valor = numero;

    if (pos == 1) { // Inser��o na cabe�a
        novoNo->prox = *L;
        *L = novoNo;
        return 1;
    }

    Tlista aux1 = *L;
    int cont = 1;

    // Avan�ando at� o n� anterior � posi��o desejada
    while (cont < pos - 1 && aux1 != NULL) {
        aux1 = aux1->prox;
        cont++;
    }

    if (aux1 == NULL) { // Posi��o inv�lida
        free(novoNo); // Liberar mem�ria do n� alocado
        return 0;
    }

    // Inserindo o novo n�
    novoNo->prox = aux1->prox;
    aux1->prox = novoNo;

    return 1; // Sucesso
}

void exibirListas(Tlista L) {
    Tlista tmp = L;

    if (tmp) {
        printf("Lista: ");
        while (tmp) {
            printf("%d -> ", tmp->valor);
            tmp = tmp->prox;
        }
        printf("NULL\n");
    } else {
        printf("Lista Vazia\n");
    }
}

