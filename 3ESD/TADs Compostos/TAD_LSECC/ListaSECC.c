#include <stdio.h>
#include <stdlib.h>
#include "ListaSECC.h"

// definição de tipos
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

// protótipos das funções auxiliares
/** criaNo
* Cria um novo nó com as informações necessárias 
*/
tNo * criaNo(int valor);

/** buscaRapida 
*	Realiza uma busca rapida pela lista
*	Retorna TRUE ou FALSE, dependendo se o valor buscado for encontrado
*/
int buscaRapida(tLSE *l, int num, tNo** ponteiroAnterior);

// funções principais

/** lse_criar_lista
* Cria uma lista vazia 
*/
tLSE * lse_criar_lista(int classificada, int repete){
    tLSE *pl = (tLSE *) malloc(sizeof(tLSE));
    
    if(pl){
        pl->qtdNos = 0;
        pl->prim = criaNo(0);   // cria o nó "cabeça"
        pl->isClassif = classificada;
        pl->temRep = repete;
        pl->prim->prox = NULL;
    }
    return pl;
}

/* lse_adicionar_elemento
*	Inclui um novo nó na lista 
*/
int lse_adicionar_elemento(tLSE *l, int num){
	
    if (l == NULL || l->prim == NULL) return -1;

    tNo *pAnt = l->prim;  // Inicializa pAnt com o nó cabeça
    int ehClass = lse_classificada(l);
    int temRepet = lse_repeticao(l);
    int resultBusca = FALSE;

	// Lista não-classificada COM repetição: insere no final
    if (!ehClass && temRepet) {
        pAnt = l->prim;
        while(pAnt->prox!=NULL) pAnt = pAnt->prox;	// add no final         
    } else {	 
         // Lista classificada ou sem repetição: usa busca rápida
        int encontrado = buscaRapida(l, num, &pAnt);
        if(encontrado && !temRepet) return -1;
    }

    // Cria e insere o novo nó
    tNo* pNovo = criaNo(num);
    if (pNovo == NULL) return -1;

    pNovo->prox = pAnt->prox;
    pAnt->prox = pNovo;
    l->qtdNos++;
    return TRUE;
}


/** lse_excluir_elemento
*  Remove todas as ocorrências de 'num' da lista
*  simplesmente encadeada, retornando a quantidade
*  de instâncias excluídas.
*/
int lse_excluir_elemento(tLSE *l, int num){
	if(l == NULL || l->prim == NULL || l->qtdNos == 0){		
		return -1; // lista inválida ou vazia
	} 
	
	tNo *pAnt = NULL;
	int found = buscaRapida(l, num, &pAnt);
	// verificando se o valor não existe
	if(!found){
		return -1; // exclusão inexistente
	}
	
	tNo *pAtual = NULL;
	int removed = 0;
	
	pAtual = pAnt->prox;
	
	// lista sem repetição
	if(!lse_repeticao(l)){
		pAnt->prox = pAtual->prox;
		free(pAtual);
		l->qtdNos--;
		return TRUE;
	}else{		// listas com repetição
	
		// lista classificada - elementos iguais estão juntos	
		if(lse_classificada(l)){
			while(pAtual != NULL && pAtual->valor == num){
				tNo *pSuc = pAtual->prox;
				pAnt->prox = pSuc;
				free(pAtual);
				removed++;
				pAtual = pSuc;
			}
		}else{		// lista NÃO classificada - elementos repetidos podem estar em qualquer lugar da lista
			
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
* Verifica se uma lista está vazia 
*/
int lse_lista_vazia(const tLSE *l){
	return (l->qtdNos == 0);
}

/**lse_classificada
* Verifica se uma lista é classificada ou não
*/
int lse_classificada(const tLSE * l){
	return (l->isClassif == 1);
}

/**lse_repeticao
* Verifica se uma lista permite repetição
*/
int lse_repeticao(const tLSE *l){
	return (l->temRep == 1);
}

/** lse_destruir_lista
* Destroi uma lista e todos seus elementos da memória
*/
void lse_destruir(tLSE **pl){
	if(pl == NULL || *pl == NULL) return; // lista inválida ou vazia
	
	tLSE *l = *pl;
	tNo *pAtual = l->prim;
	tNo *pSuc = NULL;
	
	// Percorre toda a lista liberando cada nó
	while(pAtual != NULL){
		pSuc = pAtual->prox; // salva referência pro próximo
		free(pAtual);		// Libera o nó atual
		pAtual = pSuc;		//Avança pro próximo
	}
	
	free(l);	// libera toda a estrutura da lista
	*pl = NULL; // Atualiza o ponteiro pra NULL; (boa prática)
}

/*lse_imprimir
*	Exibe todos os valores de todos os elementos da lista no console
* 	const - não é possível modificar a lista nem seus elementos dentro da função
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

// funções secundárias/auxiliares
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
        *ponteiroAnterior = l->prim; // Aponta para o nó cabeça se lista vazia
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
    // Busca em lista não-classificada (original)
    else {
        while (pAtual->valor != num) {
            *ponteiroAnterior = pAtual;
            pAtual = pAtual->prox;
        }
    }

    // Restaura valor do nó cabeça
    l->prim->valor = valorOriginal;

    // Retorna TRUE se encontrou o valor (e não é a sentinela)
    return (pAtual != l->prim && pAtual->valor == num);
}
