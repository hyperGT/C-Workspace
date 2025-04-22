#include <stdio.h>
#include <stdlib.h>
#include "ListaSECC.h"

// defini��o de tipos
struct tno {
    int valor;
    tNo *prox;
};

struct LSE {
    tNo *prim;
    int qtdNos;
    int isClassif;
    int temRep;
};

// prot�tipos das fun��es auxiliares
/** criaNo
* Cria um novo n� com as informa��es necess�rias 
*/
tNo * criaNo(int valor);

/** buscaRapida 
*	Realiza uma busca rapida pela lista
*	Retorna TRUE ou FALSE, dependendo se o valor buscado for encontrado
*/
int buscaRapida(tLSE *l, int num, tNo** ponteiroAnterior);

// fun��es principais

/** lse_criar_lista
* Cria uma lista vazia 
*/
tLSE * lse_criar_lista(int classificada, int repete){
    tLSE *pl = (tLSE *) malloc(sizeof(tLSE));
    
    if(pl){
        pl->qtdNos = 0;
        pl->prim = criaNo(0);   // cria o n� "cabe�a"
        pl->isClassif = classificada;
        pl->temRep = repete;
        pl->prim->prox = NULL;
    }
    return pl;
}

/* lse_adicionar_elemento
*	Inclui um novo n� na lista 
*/
int lse_adicionar_elemento(tLSE *l, int num){
	
    if (l == NULL || l->prim == NULL) return -1;

    tNo *pAnt = l->prim;  // Inicializa pAnt com o n� cabe�a
    int ehClass = lse_classificada(l);
    int temRepet = lse_repeticao(l);
    int resultBusca = FALSE;

	// Lista n�o-classificada COM repeti��o: insere no final
    if (!ehClass && temRepet) {
        pAnt = l->prim;
        while(pAnt->prox!=NULL) pAnt = pAnt->prox;	// add no final         
    } else {	 
         // Lista classificada ou sem repeti��o: usa busca r�pida
        int encontrado = buscaRapida(l, num, &pAnt);
        if(encontrado && !temRepet) return -1;
    }

    // Cria e insere o novo n�
    tNo* pNovo = criaNo(num);
    if (pNovo == NULL) return -1;

    pNovo->prox = pAnt->prox;
    pAnt->prox = pNovo;
    l->qtdNos++;
    return TRUE;
}


/** lse_excluir_elemento
*  Remove todas as ocorr�ncias de 'num' da lista
*  simplesmente encadeada, retornando a quantidade
*  de inst�ncias exclu�das.
*/
int lse_excluir_elemento(tLSE *l, int num){
	if(l == NULL || l->prim == NULL || l->qtdNos == 0){		
		return -1; // lista inv�lida ou vazia
	} 
	
	tNo *pAnt = NULL;
	int found = buscaRapida(l, num, &pAnt);
	// verificando se o valor n�o existe
	if(!found){
		return -1; // exclus�o inexistente
	}
	
	tNo *pAtual = NULL;
	int removed = 0;
	
	pAtual = pAnt->prox;
	
	// lista sem repeti��o
	if(!lse_repeticao(l)){
		pAnt->prox = pAtual->prox;
		free(pAtual);
		l->qtdNos--;
		return TRUE;
	}else{		// listas com repeti��o
	
		// lista classificada - elementos iguais est�o juntos	
		if(lse_classificada(l)){
			while(pAtual != NULL && pAtual->valor == num){
				tNo *pSuc = pAtual->prox;
				pAnt->prox = pSuc;
				free(pAtual);
				removed++;
				pAtual = pSuc;
			}
		}else{		// lista N�O classificada - elementos repetidos podem estar em qualquer lugar da lista
			
			while(pAtual != NULL){
				if(pAtual->valor == num){
					tNo *pSuc = pAtual->prox;
					pAnt->prox = pSuc;
					free(pAtual);
					removed++;
					pAtual = pSuc;	
				}else{
					pAnt = pAtual;
					if(pAtual == NULL) break;
					pAtual = pAtual->prox;
				}
			}
		}
	}
	l->qtdNos -= removed;
	return removed;
}

/** lse_lista_vazia
* Verifica se uma lista est� vazia 
*/
int lse_lista_vazia(const tLSE *l){
	return (l->qtdNos == 0);
}

/**lse_classificada
* Verifica se uma lista � classificada ou n�o
*/
int lse_classificada(const tLSE * l){
	return (l->isClassif == 1);
}

/**lse_repeticao
* Verifica se uma lista permite repeti��o
*/
int lse_repeticao(const tLSE *l){
	return (l->temRep == 1);
}

/** lse_destruir_lista
* Destroi uma lista e todos seus elementos da mem�ria
*/
void lse_destruir(tLSE **pl){
	if(pl == NULL || *pl == NULL) return; // lista inv�lida ou vazia
	
	tLSE *l = *pl;
	tNo *pAtual = l->prim;
	tNo *pSuc = NULL;
	
	// Percorre toda a lista liberando cada n�
	while(pAtual != NULL){
		pSuc = pAtual->prox; // salva refer�ncia pro pr�ximo
		free(pAtual);		// Libera o n� atual
		pAtual = pSuc;		//Avan�a pro pr�ximo
	}
	
	free(l);	// libera toda a estrutura da lista
	*pl = NULL; // Atualiza o ponteiro pra NULL; (boa pr�tica)
}

/*lse_imprimir
*	Exibe todos os valores de todos os elementos da lista no console
* 	const - n�o � poss�vel modificar a lista nem seus elementos dentro da fun��o
*/
void lse_imprimir(const tLSE *l){
	if (l == NULL || l->prim == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    const tNo *pAtual = l->prim->prox;
    printf("[");
    while(pAtual != NULL){
    	printf("%d", pAtual->valor);
    	if(pAtual->prox != NULL) printf(", ");
    	pAtual = pAtual->prox;
	}
	printf("]\n");
}

// fun��es secund�rias/auxiliares
tNo * criaNo(int valor){
    tNo *no = (tNo *) malloc(sizeof(tNo));
    
    if(no){
        no->prox = NULL;
        no->valor = valor;
    }
    return no;
}

int buscaRapida(tLSE *l, int num, tNo** ponteiroAnterior){	
	if (l == NULL || l->prim == NULL || l->qtdNos == 0) {
        *ponteiroAnterior = l->prim; // Aponta para o n� cabe�a se lista vazia
        return FALSE;
    }

    // Configura sentinela
    int valorOriginal = l->prim->valor;
    l->prim->valor = num;

    tNo *pAtual = l->prim->prox;
    *ponteiroAnterior = l->prim;

    // Busca em lista classificada
    if (lse_classificada(l)) {
        while (pAtual->valor < num) {
            *ponteiroAnterior = pAtual;
            pAtual = pAtual->prox;
        }
    } 
    // Busca em lista n�o-classificada (original)
    else {
        while (pAtual->valor != num) {
            *ponteiroAnterior = pAtual;
            pAtual = pAtual->prox;
        }
    }

    // Restaura valor do n� cabe�a
    l->prim->valor = valorOriginal;

    // Retorna TRUE se encontrou o valor (e n�o � a sentinela)
    return (pAtual != l->prim && pAtual->valor == num);
}
