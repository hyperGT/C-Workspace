#include <stdio.h>
#include <stdlib.h>
#include "TimeStamp.h"


int main(){
	
	TimeStamp *ts = ts_criarTimestamp(10, 5, 2024, 10, 30);
	//{ {10, 5, 2024}, {10, 30} };  // 10/05/2024 10:30
		
	ts_imprimirTimeStamp(ts);
	// Teste 1: Subtração sem mudar de dia
	ts_subtrairMinutos(ts, 30);  // Resultado: 10/05/2024 10:00
	ts_imprimirTimeStamp(ts);
	// Teste 2: Subtração que muda de dia
	ts_subtrairMinutos(ts, 1440);  // Resultado: 09/05/2024 10:00
	ts_imprimirTimeStamp(ts);
	// Teste 3: Subtração grande com valores negativos
	ts_subtrairMinutos(ts, 2881);  // Resultado: 06/05/2024 09:29 (2 dias + 1 minuto)
	ts_imprimirTimeStamp(ts);
	
	ts_somarMinutos(ts, 5000); 
	ts_imprimirTimeStamp(ts);
	
	ts_freeTimeStamp(ts);
}
