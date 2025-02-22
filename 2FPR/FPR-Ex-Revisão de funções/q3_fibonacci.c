/*
* Do a funtion that calc the n number of fibonacci
*/

#include <stdio.h>

// funções
int fibonacci(int n)
{
	int vAntigo=1, vAtual=1, aux, i;
	
	if(n<=2){
		return 1;
	}else{
		
		for(i=2; i<=n; i++)
		{
			aux = vAtual;
			vAtual = vAntigo+vAtual;
			vAntigo = aux;
		}
	}
	return vAtual;
}

int main()
{
	int n, r;
	
	printf("Insira n: ");
	scanf("%d", &n);
	
	r = fibonacci(n);
	
	printf("Valor: %d", r);
	
}
