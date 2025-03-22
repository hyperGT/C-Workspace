/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "Retangulo.h"
#include "Ponto.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	Retangulo* tab[4];
	Ponto * origem = pto_cria(0,0);
	tab[0]= ret_cria(2,2,2,2);
	tab[1] = ret_cria(-1,-1,2,2);
	tab[2] = ret_cria(-1,-1,3,3);
	tab[3]= ret_cria(2,2,4,3);
	for(i=0; i < 4; i++)
	{
		printf( "\nRetangulo: %d\n",i+1);
		ret_exibe(tab[i]);
		printf("\tDistancia da Origem: %f", pto_distancia(ret_vertice(tab[i]), origem));
	}
	return 0;
}

