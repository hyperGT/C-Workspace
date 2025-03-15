/* Tipo exportado */
typedef struct vect Vector2f;


/* Funções exportadas base obrigatórias */
/* Create function: Aloca e retorna um vetor de 2 dimensões (x, y) */
Vector2f * vect_criar(float x, float y);

/* set function: atribui novos valores ao vetor */
void vect_atribui(Vector2f * v, float x, float y);

/* copy function: copia os valores de vetor e os atribui a outro vetor de mesma natureza */
Vector2f * vect_copia(Vector2f * v);

/* Free vector memory: libera a memória que o vetor ocupa no heap */
void vect_libera(Vector2f * v);

/* show Vect: exibe os valores de x e y que compõe o vetor de duas dimensões */
void vect_exibe(Vector2f * v);

/* getVector function: Retorna o valor em formato de string */
char * vect_getVec(Vector2f * v);

/* Funções exportadas operações com vetores */

/* add function: retorna o produto de dois vetores A e B como um novo vetor AB */
// Vector2f * operator += (const Vector2f& rhsVec);
Vector2f * vect_add (Vector2f * v1, Vector2f *v2);

/* scale function: retorna o produto de um vetor por uma escalar (que pertence ao conjunto dos naturais) */
Vector2f * vect_scale (Vector2f * v, float s);

/* dist function: retorna a distância de um vetor para outro */
float vect_dist (Vector2f * v1, Vector2f * v2);

