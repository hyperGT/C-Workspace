/*
Fazer um algoritmo que determine a ordem de
uma data (dia e mês) no ano.
Exemplos:
01/01 - 1o dia do ano
03/02 - 34o dia do ano
*/

#include<stdio.h>
#include<ctype.h>


int main(){
	
	int dia, mes, diaDoAno;
	int jan=31, fev=28, mar=31, abr=30, mai=31, jun=30, jul=31, ago=31, set=30, out=31, nov=30;
	char res;
	
	printf("Insira o dia: ");
	scanf("%d", &dia);
	printf("Insira o mes: ");
	scanf("%d", &mes);
	printf("\nO ano e bissexto? [S/N]: ");
	fflush(stdin); //resetando o buffer do teclado
	scanf("%c", &res);	
	res = toupper(res); //colocando pra maiusculo
	
	// vendo se é ano bissexto
	if(res == 'S')	{
		fev +=1;
	}
	printf("fevereiro tem: %d dias\n", fev);
	
	
	if(mes == 1){
		diaDoAno = dia;
	}
	if(mes == 2){
		diaDoAno = dia + jan;
	}
	if(mes == 3){
		diaDoAno = dia + (jan+fev);
	}
	if(mes == 4){
		diaDoAno = dia + (jan+fev+mar);
	}
	if(mes == 5){
		diaDoAno = dia + (jan+fev+mar+abr);
	}
	if(mes == 6){
		diaDoAno = dia + (jan+fev+mar+abr+mai);
	}
	if(mes == 7){
		diaDoAno = dia + (jan+fev+mar+abr+mai+jun);
	}	
	if(mes == 8){
		diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul);
	}
	if(mes == 9){
		diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul+ago);
	}
	if(mes == 10){
		diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul+ago+set);
	}
	if(mes == 11){
		diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul+ago+set+out);
	}
	if(mes == 12){
		diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul+ago+set+out+nov);
	}
	printf("%d/%d - %d° dia do ano", dia, mes, diaDoAno);
}
