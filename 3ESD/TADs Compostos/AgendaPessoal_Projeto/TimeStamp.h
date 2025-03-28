#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include "Data.h"
#include "Horario.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Une a data e o horário em uma única estrutura.
* Permite operações combinadas de tempo, como adicionar minutos e ajustar automaticamente a data.
* Facilita a manipulação de informações temporais em compromissos.
*/

typedef struct {
	Data *data;
	Horario *horario;
}TimeStamp;

/*Cria um timestamp com Data e Horário.*/
TimeStamp *ts_criarTimestamp(int dia, int mes, int ano, int hora, int minuto);

/*Exibe data e horário no formato DD/MM/AAAA HH:MM.*/
void ts_imprimirTimeStamp(TimeStamp *timeStamp);

/* Libera memória da estrutura Timestamp. */
void ts_freeTimeStamp(TimeStamp *timeStamp);

/*Adiciona minutos ao timestamp, ajustando data e horário.*/
void ts_somarMinutos(TimeStamp *timeStamp, int minutos);

/* Subtrai minutos, garantindo consistência entre data e horário. */
void ts_subtrairMinutos(TimeStamp *timeStamp, int minutos);

#endif
