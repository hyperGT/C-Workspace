/* Tipo exportado */
typedef struct ponto Ponto;

/* Fun��es exportadas */
/* Fun��o cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y);

/* Fun��o libera - Libera a mem�ria de um ponto previamente criado */
void pto_libera(Ponto* p);

/* Fun��o acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y);

/* Fun��o atribui - Atribui novos valores �s coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y);

/* Fun��o exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p);

/* Fun��o copia -  retorna um novo  ponto com coordenadas do ponto recebido*/
Ponto* pto_copia(Ponto*p);

/* Fun��o getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p);

/* Fun��o distancia - Retorna a dist�ncia entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2);

/* Fun��o menorque -recebe dois pontos e retorna 1 se o pt1 est� mais pr�ximo da origem, 0 cc*/
int pto_menorque(Ponto* pt1,Ponto* pt2);

/**/




