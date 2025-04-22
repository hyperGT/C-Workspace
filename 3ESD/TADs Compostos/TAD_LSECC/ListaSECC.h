#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


// Lista simplesmente encadeada com n� cabe�a
// declara��o do tipo n�
typedef struct tno tNo;
// declara��o do tipo lista
typedef struct LSE tLSE;

// fun��es 

/* Cria uma lista simplesmente encadeada vazia*/
tLSE * lse_criar_lista(int classificada, int repete);

/* Adiciona um novo n� a lista */
int lse_adicionar_elemento(tLSE *l, int num);

int lse_excluir_elemento(tLSE * l, int num);

void lse_destruir(tLSE **pl);

void lse_imprimir(const tLSE *l);

int lse_classificada(const tLSE *l);

int lse_repeticao(const tLSE *l);

int lse_lista_vazia(const tLSE *l);
