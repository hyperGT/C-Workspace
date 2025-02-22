/*
* Calc the MDC betwen two numbers
*/


#include <stdio.h>
// funções
int calcMDC (int v1, int v2){	
	
	int i, mdc=1;
	
	int menor = (v1 < v2) ? v1 : v2;// obtendo o menor valor dos dois
	
	
	for(i=1; i<=menor; i++){
	
		if(v1%i==0 && v2%i==0){
			mdc=i;
		}
		
	}
	return mdc;
}

int main(){
	
	int n1, n2, res;
	
	printf("Insira o primeiro valor: ");
	scanf("%d", &n1);
	printf("Insira o segundo valor: ");
	scanf("%d", &n2);
	
	res = calcMDC(n1, n2);
	
	printf("MDC(%d, %d) = %d", n1, n2, res);
}

