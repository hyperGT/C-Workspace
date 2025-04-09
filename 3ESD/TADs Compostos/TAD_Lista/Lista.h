/*
* Minha versão do TAD Lista
*/

typedef struct tipo_lista tLista

/* Criar uma nova lista */
tLista * lst_criarListaVazia(int maximo, int classif, int repeticao);

/* Inclui um novo elemento na lista */
int lst_incluirElemento(tLista *lst, int num);

/* Exclui um valor da lista */
int lst_excluirElemento(tLista *lst, int num);

/* Verifica se a lista está vazia, retornando 1 caso esteja e 0 caso contrário */
int lst_estaVazia(const tLista *lst);

/* Verifica se a lista está cheia */
int lst_estaCheia(const tLista *lst);

/* Verifica se a lista é classificada */
int lst_eClassif(const tLista *lst);

/* Verifica se a lista permite repetição */
int lst_temRepet(const tLista *lst);

/* Percorre a lista e exibe todos os itens */
void lst_exibe(const tLista *lst);