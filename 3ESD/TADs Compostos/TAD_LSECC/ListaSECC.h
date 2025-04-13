// Lista simplesmente encadeada com nó cabeça
// declaração do tipo nó
typedef struct tno tNo;
// declaração do tipo lista
typedef struct LSE tLSE;



// funções 

/* Cria uma lista simplesmente encadeada vazia*/
tLSE * lse_criar_lista(int classificada, int repete);

void lse_classificada(const tLSE *l);

void lse_repeticao(const tLSE *l);

void lse_lista_vazia(const tLSE *l);
