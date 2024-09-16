/*
	Quest�o 04:
		Dada uma matriz MLxC, onde L e C s�o constantes, desenvolver uma fun��o que verifique se os elementos da matriz est�o
		ordenados de forma crescente. Para isto, as seguintes regras devem ser atendidas:
		a. Os elementos de cada linha devem estar ordenados crescentemente (ou seja, cada elemento ser� maior ou igual
		�quele da mesma linha, por�m da coluna anterior � caso exista);
		b. O primeiro elemento de cada linha deve ser maior ou igual ao �ltimo da linha anterior (caso exista).
		Caso a matriz M atenda aos crit�rios definidos, o valor 1 dever� ser retornado pela fun��o; caso contr�rio, 0.
*/

#include <stdio.h>

int verificaCrescente(int l, int c, int m[l][c]);
void exibir (int lin, int col, int m[lin][col]);

void main(){
	
	int m[2][4] = {{2, 4, 5, 7},
					{8, 8, 8, 9}}; 
	
	exibir (2, 4, m);
	
	printf("\n======================\n\n");
	if(verificaCrescente(2, 4, m) == 1){
	
		printf("Esta ordenado de forma crescente");		
	
	}else{
			
		printf("NAO esta ordenado crescentemente");
	
	}
}

int verificaCrescente(int l, int c, int m[l][c]){
	
	int i, j;
	
	for(i=0;i<l;i++){
		for(j=1;j<c;j++){
			
		/* a. Os elementos de cada linha devem estar ordenados crescentemente 
		(ou seja, cada elemento ser� maior ou igual	�quele da mesma linha, 
		por�m da coluna anterior � caso exista);
		*/
			if(m[i][j]<m[i][j-1]){
				return 0;
			}
		}
	}
	
	/* b. O primeiro elemento de cada linha deve ser maior ou igual 
	ao �ltimo da linha anterior (caso exista).
	/	Caso a matriz M atenda aos crit�rios definidos, 
	o valor 1 dever� ser retornado pela fun��o; caso contr�rio, 0.*/
	
	for(i=1;i<l;i++){
	
		if(m[i][0] < m[i-1][c-1]){
			return 0;
		}
	}
	
	return 1;
}

void exibir (int lin, int col, int m[lin][col]){
	
	int i, j;
	
	printf("\n\n======================\n\n");
	
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
