/*

Quest�o 03:
Desenvolver uma fun��o recursiva que exiba
todos os m�ltiplos do n�mero N, inferiores ou
iguais ao valor V.

*/

#include <stdio.h>

// fun��es
void exibirMultiplosDeN (int n, int cnt, int v);

void main(){
     
    // declara��o de vari�veis
    int n = 2, v = 10;        
    
    /* Entrada de dados
    printf("Insert 'n': ");
    scanf("%d", &n);
    
    printf("Insert 'v': ");
    scanf("%d", &v);
    */
    
    // chamando a fun��o 
    exibirMultiplosDeN (n, 1, v);
}

void exibirMultiplosDeN (int n, int cnt, int v){
	
	int r = n * cnt;
	if(r > v){
		return 0;
	}else{
		// exibindo o m�ltiplo
		printf("%d\n", r);
		
		return exibirMultiplosDeN(n, cnt+1, v);
	}
}


/*
N = 2; V = 10
	exibirMultiplosDeN(2, 1, 10) -> r = 2 printa
		exibirMultiplosDeN(2, 2, 10) -> r = 4 printa
			exibirMultiplosDeN(2, 3, 10) -> r = 6 printa
				exibirMultiplosDeN(2, 4, 10) -> r = 8 printa
					exibirMultiplosDeN(2, 5, 10) -> r = 10 printa
						exibirMultiplosDeN(2, 6, 10) -> r = 12 retorno: 0
*/	
