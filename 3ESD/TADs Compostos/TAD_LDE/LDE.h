#ifndef LDE_H
#define LDE_H
// Lista duplamente encadeada com n� cabe�a 

/**
*	defini��o dos tipos lista e n�
*/
typedef struct tno tNo;	// node struct

typedef struct LDE tLDE;	// list struct

/* Cria uma lista duplamente encadeada vazia e inicializa o n� cabe�a */
tLDE * lde_criar(int classificada, int repeticao);

/* permite a inser��o de novos elementos na lista */
int lde_adicionar(tLDE *pL, int num);

/* permite a exclus�o de um elemento da lista */
int lde_excluir(tLDE *pL, int num);

/* Libera toda a estrutura da lista da mem�ria */
void lde_destruir(tLDE **pl);

/* Exibe toda a lista no console*/
void lde_imprimir(const tLDE *l);

/* Verifica se a lista � classificada ou n�o */
int lde_classificada(const tLDE *l);

/* Verifica se a lista permite repeti��o */
int lde_repeticao(const tLDE *l);

/* Verifica se a lista est� vazia */
int lde_lista_vazia(const tLDE *l);

#endif
