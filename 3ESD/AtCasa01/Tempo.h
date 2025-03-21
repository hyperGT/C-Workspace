/* Tipo exportado */
typedef struct tempo Tempo;

// Cria��o de uma unidade de tempo
Tempo* tpo_cria(int hr, int min, int seg);

// Exibi��o de um per�odo de tempo
void tpo_exibe(Tempo*t);

// Convers�o para segundos
int tpo_tempoParaSegundos(Tempo*t);

// Convers�o de segundos para unidade de tempo
Tempo* tpo_tempoDeSegundos (int total_segundos);

// Soma de per�odos de tempo
Tempo* tpo_soma(Tempo* t1, Tempo* t2);

// Subtra��o de per�odos de tempo
Tempo* tpo_subtrai(Tempo*t1, Tempo*t2);

// Compara dois per�odos de tempo e determina se um per�odo � menor, maior ou igual a outro
int tpo_compara(Tempo*t1, Tempo*t2);
