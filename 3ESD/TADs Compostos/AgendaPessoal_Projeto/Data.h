#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
} Data;

Data *data_criarData(int dia, int mes, int ano);

void data_imprimirData(Data *data);
void data_acessaData(Data *data, int *dia, int *mes, int *ano);
void data_atribuiData(Data *data, int dia, int mes, int ano);
char *data_formatoTexto(Data *data);
void data_destruirData(Data *data);
void data_somarDias(Data *data, int dias);
void data_subtrairDias(Data *data, int dias);

#endif
