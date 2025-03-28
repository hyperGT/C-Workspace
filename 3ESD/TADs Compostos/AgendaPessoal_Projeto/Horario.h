#ifndef HORARIO_H
#define HORARIO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hora, minuto;
} Horario;

Horario *hr_criarHorario(int hora, int minuto);
void hr_acessarHorario(Horario *horario,int * hora, int* minuto);
void hr_atribuirHorario(Horario *horario,int  hora, int minuto) ;
void hr_imprimirHorario(Horario *horario);
void hr_destruirHorario(Horario *horario);
void hr_somarMinutos(Horario *horario, int minutos);
void hr_subtrairMinutos(Horario *horario, int minutos);
char* hr_formatoTexto(Horario *horario);

#endif
