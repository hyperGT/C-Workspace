// Lista simplesmente encadeada com nó cabeça
// declaração do tipo nó
typedef struct tno tNo;
// declaração do tipo lista
typedef struct LSE tLSE;



// funções 
tLSE * lse_criarLista(int classificada, int repete);

void lse_classificada(const tLSE *l);

void lse_repeticao(const tLSE *l);

void lse_vazia(const tLSE *l);
