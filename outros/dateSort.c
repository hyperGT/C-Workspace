/*
Desenvolvendo um programinha que ordena datas

Usando função etc.
*/

#include <stdio.h>

// prototipo das funções
void dateSortJap(int d, int m, int y);

void dateSortBr(int d, int m, int y);

int main(){
	
	// inicializando as variaveis
	int day, month, year;
	char resp;
	
	// pedindo a entrada da data
	printf("Escolha a versao na qual deseja ordenar a data [b - brasileira , j - japonesa]:  ");
	scanf("%c", &resp);
	
	printf("Insira o dia: ");
	scanf("%d", &day);
	
	printf("Insira o mes: ");	
	scanf("%d", &month);
	
	printf("Insira o ano: ");	
	scanf("%d", &year);
	
	if(resp == 'j'){
		dateSortJap(day, month, year);
	} else if(resp == 'b'){
		dateSortBr(day, month, year);
	} else{
		printf("Insira uma versao valida: ");
	}		
	
}

// ano, mes, dia
void dateSortJap(int d, int m, int y){

	printf("\n %d / %d / %d ", y, m, d);

}

// dia, mes, ano
void dateSortBr(int d, int m, int y){

	printf("\n %d / %d / %d ", d, m, y);

}

