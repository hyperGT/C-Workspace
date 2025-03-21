/* Tipo exportado */
typedef struct tempo Tempo;

// Criação de uma unidade de tempo
Tempo* tpo_cria(int hr, int min, int seg);

// Exibição de um período de tempo
void tpo_exibe(Tempo*t);

// Conversão para segundos
int tpo_tempoParaSegundos(Tempo*t);

// Conversão de segundos para unidade de tempo
Tempo* tpo_tempoDeSegundos (int total_segundos);

// Soma de períodos de tempo
Tempo* tpo_soma(Tempo* t1, Tempo* t2);

// Subtração de períodos de tempo
Tempo* tpo_subtrai(Tempo*t1, Tempo*t2);

// Compara dois períodos de tempo e determina se um período é menor, maior ou igual a outro
int tpo_compara(Tempo*t1, Tempo*t2);
