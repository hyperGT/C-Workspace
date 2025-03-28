#include "Horario.h"

void corrigeHorario(Horario* horario){
	
	// corrigindo o horario 
	
	// corrige horas negativas
	horario->hora %= 24;
	
	if(horario->hora < 0){
		horario->hora += 24;		
	}
	
	horario->minuto %= 60;
	if(horario->minuto < 0){		
		horario->minuto += 60;
		horario->hora--;		
	}
}

int verificaHorario(int hora, int min){
	if(min >= 60){
		/*
		horario->minuto -= 60;
		horario->hora++;
		*/
		
		return -1;
	}
	if(hora >= 24){
		// horario->hora -= 24;
		return -2;
	}
	return 1;
}

Horario *hr_criarHorario(int hora, int minuto){		
	
	if(verificaHorario(hora, minuto) < 1){
		printf("Entradas inválidas para horas e minutos");
		exit(1);
	}
	
	Horario *h = (Horario *) malloc(sizeof(Horario));
	
	h->hora = hora;
	h->minuto = minuto;		
	
	return h;
}

void hr_acessarHorario(Horario *horario, int *hora, int*minuto){
	*hora = horario->hora;
	*minuto = horario->minuto;
}

void hr_atribuirHorario(Horario *horario,int  hora, int minuto){
	horario->hora = hora;
	horario->minuto = minuto;
}

void hr_imprimirHorario(Horario *horario){
	printf("%02d:%02d", horario->hora, horario->minuto);
}

void hr_destruirHorario(Horario *horario){
	free(horario);
}

void hr_somarMinutos(Horario *horario, int minutos){
	
	horario->hora += minutos / 60;
    horario->minuto += minutos % 60;
    
    // Corrige overflow de minutos
    if (horario->minuto >= 60) {
        horario->minuto -= 60;
        horario->hora++;
    }    
	
	corrigeHorario(horario);
}

void hr_subtrairMinutos(Horario *horario, int minutos){
	horario->hora -= minutos / 60;
    horario->minuto -= minutos % 60;
    
    // Corrige underflow de minutos
    if (horario->minuto < 0) {
        horario->minuto += 60;
        horario->hora--;
    }
    corrigeHorario(horario);
}

char* hr_formatoTexto(Horario *horario){
	char* strHorario = (char *) malloc(sizeof(*horario) + 3);
	sprintf(strHorario, "%02d:%02d", horario->hora, horario->minuto);
	return strHorario;
}
