/*
QUEST�O 02:
Dada uma fila F, do tipo TLista, implementar uma fun��o que remova de F todos os divisores do n�mero
inteiro N e, ao final, retorne a quantidade de remo��es realizadas.
Notas: i. as regras de manipula��o de uma fila cl�ssica devem ser respeitadas; ii. Caso alguma
estrutura auxiliar seja necess�ria, esta dever� ser uma fila ou uma pilha.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No* prox;
}TNo;

typedef TNo* TLista;

// prot�tipos das fun��es
int enfilar(TLista *F, TLista *U, int numero);
int desenfilar(TLista *F, TLista *U, int *numero);
int primeiro(TLista F, int *numero);
int removerDivisores(TLista *F, TLista *U, int n);

int menu();

void main (){
	
	TLista F = NULL, U = NULL;
	int num, op, cnt;

	do
	{
		system ("CLS");		//limpar tela

		//exibindo o meu ao usu�rio
		op = menu ();

		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
			        if (enfilar (&F, &U, num) == 1)   //ou apenas: if (enfilar (&F, &U, num))
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remo��o
			case 2: //chamando a fun��o
			        if (desenfilar (&F, &U, &num) == 1)
			        {
			        	printf ("\n\tElemento %d removido da fila!", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!");
					}
					break;

			//Primeiro
			case 3: if (primeiro (F, &num) == 1)
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!");
					}
					break;	
														        
			case 4:	printf ("\nEntre com o valor N: ");
			        scanf ("%d", &num);
					
					cnt = removerDivisores(&F, &U, num);
					
					if(cnt>0){
						printf("\n\tExibindo quantidade de valores removidos: %d", cnt);
					}else{
						printf("\n\tNenhum valor removido");
					}
					break;
			//Sa�da			
			case 5: printf ("\n\nPrograma finalizado!");
			        break;
			        
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 5); //5 = SAIR
	
}

int removerDivisores(TLista *F, TLista *U, int n){
	
	TLista Faux = NULL, Uaux = NULL;
	int numero, cont = 0;
	
	if(!(*F)) return 0;
	
	while(*F){
		
		desenfilar(F, U, &numero);
			
		if(n % numero == 0){
			
			cont++;	// atualizando a quantidade de valores divisores de 'n' removidos
									
		}else{
			enfilar(&Faux, &Uaux, numero);
		}
	}
	
	*F = Faux;  // fazendo 'F' apontar pro mesmo n� que aponta 'Faux'
	*U = Uaux;
		
	return cont;
}


int enfilar(TLista *F, TLista *U, int numero){
	
	TLista aux;
	
	aux = malloc(sizeof(TNo));
	
	if(!aux) return 0;
	
	aux->valor = numero;
	aux->prox = NULL;
	
	// verificando se a lista est� vazia
	if(*F){
		(*U)->prox = aux;
	}else{
		
		// caso esteja vazia
		*F = aux;
	}
	
	*U = aux;
	
	return 1;	
}

int desenfilar(TLista *F, TLista *U, int *numero){
	
	TLista aux;
	
	if(!(*F)){
		return 0;
	}else{
		
		// armazenando em 'aux' o primeiro n� da fila
		aux = *F;
		
		// guardando o valor a ser excluido(topo)
		*numero = (*F)->valor;
		
		// atualizando o topo
		*F = (*F)->prox;
		
		// verificando se h� elementos na lista depois da atualiza��o 
		if(!(*F)){
			
			*U = NULL;
		}
		
		free (aux);
		return 1;
	}
}


int primeiro(TLista F, int *numero){
	
	if(!F){
		return 0;
	}else{
		
		*numero = F->valor;
		return 1;
	}
}


int menu(){
	
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Remover Divisores\n");
	printf ("(5) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
