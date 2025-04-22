#ifndef LDE_H
#define LDE_H
// Lista duplamente encadeada com nó cabeça 

/**
*	definição dos tipos lista e nó
*/
typedef struct tno tNo;	// node struct

typedef struct LDE tLDE;	// list struct

/* Cria uma lista duplamente encadeada vazia e inicializa o nó cabeça */
tLDE * lde_criar(int classificada, int repeticao);

/* permite a inserção de novos elementos na lista */
int lde_adicionar(tLDE *pL, int num);

/* permite a exclusão de um elemento da lista */
int lde_excluir(tLDE *pL, int num);

/* Libera toda a estrutura da lista da memória */
void lde_destruir(tLDE **pl);

/* Exibe toda a lista no console*/
void lde_imprimir(const tLDE *l);

/* Verifica se a lista é classificada ou não */
int lde_classificada(const tLDE *l);

/* Verifica se a lista permite repetição */
int lde_repeticao(const tLDE *l);

/* Verifica se a lista está vazia */
int lde_lista_vazia(const tLDE *l);

#endif
