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
	
	switch(mes){
		case 1:
			diaDoAno = dia;
			break;
		case 2:
			diaDoAno = dia + jan;
			break;
		case 3:
			diaDoAno = dia + (jan+fev);
			break;
		case 4:
			diaDoAno = dia + (jan+fev+mar);
			break;
		case 5:
			diaDoAno = dia + (jan+fev+mar+abr);
			break;
		case 6:
			diaDoAno = dia + (jan+fev+mar+abr+mai);
			break;
		case 7:
			diaDoAno = dia + (jan+fev+mar+abr+mai+jun);
			break;
		case 8:
			diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul);
			break;
		case 9:
			diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul+ago);
			break;
		case 10:
			diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul+ago+set);
			break;
		case 11:	
			diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul+ago+set+out);
			break;
		case 12:
			diaDoAno = dia + (jan+fev+mar+abr+mai+jun+jul+ago+set+out+nov);						
			break;
		default:
			printf("Mes invalido\n");
			return 1;			
}		

printf("0%d/0%d - %d° dia do ano", dia, mes, diaDoAno);
}
