// Lista simplesmente encadeada com n� cabe�a
// declara��o do tipo n�
typedef struct tno tNo;
// declara��o do tipo lista
typedef struct LSE tLSE;



// fun��es 
tLSE * lse_criarLista(int classificada, int repete);

void lse_classificada(const tLSE *l);

void lse_repeticao(const tLSE *l);

void lse_vazia(const tLSE *l);
