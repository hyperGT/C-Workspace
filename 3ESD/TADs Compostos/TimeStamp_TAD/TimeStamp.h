#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include "Data.h"
#include "Horario.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Une a data e o hor�rio em uma �nica estrutura.
* Permite opera��es combinadas de tempo, como adicionar minutos e ajustar automaticamente a data.
* Facilita a manipula��o de informa��es temporais em compromissos.
*/

typedef struct {
	Data *data;
	Horario *horario;
}TimeStamp;

/*Cria um timestamp com Data e Hor�rio.*/
TimeStamp *ts_criarTimestamp(int dia, int mes, int ano, int hora, int minuto);

/*Exibe data e hor�rio no formato DD/MM/AAAA HH:MM.*/
void ts_imprimirTimeStamp(TimeStamp *timeStamp);

/* Libera mem�ria da estrutura Timestamp. */
void ts_freeTimeStamp(TimeStamp *timeStamp);

/*Adiciona minutos ao timestamp, ajustando data e hor�rio.*/
void ts_somarMinutos(TimeStamp *timeStamp, int minutos);

/* Subtrai minutos, garantindo consist�ncia entre data e hor�rio. */
void ts_subtrairMinutos(TimeStamp *timeStamp, int minutos);

#endif
