#include "Data.h"

int isBissexto(int ano){
	return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasNoMes(int mes, int ano){
	int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (mes == 2 && isBissexto(ano)) return 29;
	return diasMes[mes-1];
}

Data* data_criarData(int dia, int mes, int ano){
	Data *novaData = (Data *) malloc(sizeof(Data));
	novaData->dia = dia;
	novaData->mes = mes;
	novaData->ano = ano;
	return novaData;
}

void data_imprimirData(Data *data){
	printf("%02d/%02d/%04d", data->dia, data->mes, data->ano);
}

void data_destruirData(Data *data){
	free(data);
}

void data_somarDias(Data *data, int dias){
	while(dias > 0){
		int diasRestantes = diasNoMes(data->mes, data->ano) - data->dia;
		if(dias > diasRestantes){
			dias -= (diasRestantes + 1);
			data->dia = 1;
			if(++data->mes > 12){
				data->mes = 1;
				data->ano++;
			}
		}else{
			data->dia += dias;
			dias = 0; // finaliza o programa
		}
	}
}

void data_subtrairDias(Data *data, int dias){
	while(dias > 0){
		if(dias >= data->dia){
			dias -= data->dia;
			if(--data->mes < 1){
				data->mes = 12;
				data->ano--;
			}
			data->dia = diasNoMes(data->mes, data->ano);
		}else{
			data->dia -= dias;
			dias = 0;
		}
	}
}

void data_acessaData(Data *data, int *dia, int *mes, int *ano){
	*dia = data->dia;
	*mes = data->mes;
	*ano = data->ano;
}

void data_atribuiData(Data *data, int dia, int mes, int ano){
	data->dia = dia;
	data->mes = mes;
	data->ano = ano;
}

// Exemplo: "28/02/2025"
char* data_formatoTexto(Data *data){
	char* strData = (char *) malloc(sizeof(*data) + 3);
	sprintf(strData, "%02d/%02d/%02d", data->dia, data->mes, data->ano);
	return strData;
}

