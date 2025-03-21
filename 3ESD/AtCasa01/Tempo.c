#include "Tempo.h"
#include <stdio.h>
#include <stdlib.h>

/* Tipo exportado */
struct tempo {
	int horas;
	int minutos;
	int segundos;
};

/* Fun��es auxiliares */

// ajusta o tempo
void ajustaTempo(Tempo *t){
	if(t->segundos >= 60){
		t->minutos += t->segundos/60;
		t->segundos %= 60;		
	}
	if(t->minutos >= 60){		
		t->horas += t->minutos/60;
		t->minutos %= 60;
	}
}

// Cria��o de uma unidade de tempo
Tempo* tpo_cria(int hr, int min, int seg){
	Tempo* t = (Tempo*) malloc(sizeof(Tempo));
	
	if(t == NULL){
		printf("Erro: mem�ria insuficiente para criar Tempo.\n");
		return NULL;
	}
	
	t->horas = hr;
	t->minutos = min;
	t->segundos = seg;
	
	ajustaTempo(t);
	
	return t;	
}

// Exibi��o de um per�odo de tempo
void tpo_exibe(Tempo *t){
	printf("%02d:%02d:%02d\n", t->horas, t->minutos, t->segundos);
}

// Convers�o para segundos
int tpo_tempoParaSegundos(Tempo *t){
	return t->horas * 3600 + t->minutos * 60 + t->segundos;
}

// Convers�o de segundos para unidade de tempo
Tempo* tpo_tempoDeSegundos (int total_segundos){
	Tempo* t = tpo_cria(total_segundos / 3600, (total_segundos % 3600) / 60, total_segundos % 60);
	return t;
}

// Soma de per�odos de tempo
Tempo* tpo_soma(Tempo* t1, Tempo* t2){
	Tempo* resultado = tpo_cria(
		t1->horas + t2->horas, 
		t1->minutos + t2->minutos, 
		t1->segundos + t2->segundos
	);
	ajustaTempo(resultado);
	return resultado;
}

// Subtra��o de per�odos de tempo
Tempo* tpo_subtrai(Tempo*t1, Tempo*t2){
	int segundosT1 = tpo_tempoParaSegundos(t1);
	int segundosT2 = tpo_tempoParaSegundos(t2);
	
	if(segundosT1 < segundosT2){
		printf("Erro: resultado negativo n�o suportado.\n");
		return NULL;
	}
	
	int diff = segundosT1 - segundosT2;
	return tpo_tempoDeSegundos(diff);
}

// Compara dois per�odos de tempo e determina se um per�odo � menor, maior ou igual a outro
int tpo_compara(Tempo*t1, Tempo*t2){
	int segundosT1 = tpo_tempoParaSegundos(t1);
	int segundosT2 = tpo_tempoParaSegundos(t2);
	
	if(segundosT1 < segundosT2)	return -1;
	if(segundosT1 > segundosT2)	return 1;
	return 0;
}
