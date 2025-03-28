#include "TimeStamp.h"


/*Cria um timestamp com Data e Horário.*/
TimeStamp *ts_criarTimestamp(int dia, int mes, int ano, int hora, int minuto){	
	TimeStamp *newTs = (TimeStamp *) malloc(sizeof(TimeStamp));
	
	newTs->data = data_criarData(dia, mes, ano);
	newTs->horario = hr_criarHorario(hora, minuto);
	
	return newTs;
}

/*Exibe data e horário no formato DD/MM/AAAA HH:MM.*/
void ts_imprimirTimeStamp(TimeStamp *timeStamp){
	printf("%s, %s\n", data_formatoTexto(timeStamp->data), hr_formatoTexto(timeStamp->horario));
}


/* Libera memória da estrutura Timestamp. */
void ts_freeTimeStamp(TimeStamp *timeStamp){
	free(timeStamp->data);
	free(timeStamp->horario);
	free(timeStamp);
}

/*Adiciona minutos ao timestamp, ajustando data e horário.*/
void ts_somarMinutos(TimeStamp *timeStamp, int minutos){
	// Calcula quantos dias completos se passaram
	int minutosTotais = timeStamp->horario->hora * 60 + 
	timeStamp->horario->minuto + minutos;
	int diasPassados = minutosTotais / 1440; // 1 dia = 1440 minutos
	int minutosRestantes = minutosTotais % 1440;
	
	// Atualiza a data
	if(diasPassados > 0){
		data_somarDias(timeStamp->data, diasPassados);
	}
	
	// Atualiza o horario
	timeStamp->horario->hora = 0;
	timeStamp->horario->minuto = 0;
	hr_somarMinutos(timeStamp->horario, minutosRestantes);
}

/* Subtrai minutos, garantindo consistência entre data e horário. */
void ts_subtrairMinutos(TimeStamp *timeStamp, int minutos){
	
	if (minutos >= 1440) {
	    int dias = minutos / 1440;
	    data_subtrairDias(timeStamp->data, dias);
	    minutos = minutos % 1440;
	}
	
	// Calcula o total de minutos resultante após a subtração
	int minutosTotais = timeStamp->horario->hora * 60 + 
	timeStamp->horario->minuto - minutos;
	
	// obtem a qnt de dias passados(que serão subtraidos)
	int diasPassados = minutosTotais / 1440;
	int minutosRestantes = minutosTotais % 1440;
	
	// Trata caso especia onde minutosTotais é negativo
	if(minutosRestantes < 0){
		diasPassados--;
		minutosRestantes += 1440;
	}
	
	// atualiza a data se necessário
	if(diasPassados < 0){
		data_subtrairDias(timeStamp->data, -diasPassados);
	}
	/*
	printf("Minutos totais: %d\n", minutosTotais);
	printf("Dias passados: %d\n", diasPassados);
	printf("Minutos restantes: %d\n", minutosRestantes);
	*/
	// atualiza o horario
	timeStamp->horario->hora = 0;
	timeStamp->horario->minuto = 0;
	hr_somarMinutos(timeStamp->horario, minutosRestantes);
}


