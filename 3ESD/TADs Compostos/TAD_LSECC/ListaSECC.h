// Lista simplesmente encadeada com n� cabe�a
// declara��o do tipo n�
typedef struct tno tNo;
// declara��o do tipo lista
typedef struct LSE tLSE;



// fun��es 

/* Cria uma lista simplesmente encadeada vazia*/
tLSE * lse_criar_lista(int classificada, int repete);

void lse_classificada(const tLSE *l);

void lse_repeticao(const tLSE *l);

void lse_lista_vazia(const tLSE *l);
