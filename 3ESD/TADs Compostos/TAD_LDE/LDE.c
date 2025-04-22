#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LDE.h"

#define TRUE 1
#define FALSE 0

/* Criando os tipos */
struct tno {
	int valor;
	tNo *ant;
	tNo *prox;
};

struct LDE {
	tNo* cabeca;
	int qtdNos;
	int isClassif;
	int temRep;
};

// prot�tipos de fun��es auxiliares
static tNo * cria_no(int num);

int busca_rapida(tLDE *pL, int num, tNo **pAnterior);

/* Cria uma lista duplamente encadeada vazia e inicializa o n� cabe�a */
tLDE * lde_criar(int classificada, int repeticao){
	tLDE *nova = (tLDE *) malloc(sizeof(tLDE));
	
	if(nova) {
		nova->cabeca = (tNo *) malloc(sizeof(tNo));
		nova->cabeca->ant = nova->cabeca->prox = NULL;
		nova->cabeca->valor = INT_MIN;
		nova->qtdNos = 0;	
		nova->isClassif = classificada;
		nova->temRep = repeticao;
	}
	return nova;
}

/* permite a inser��o de novos elementos na lista */
int lde_adicionar(tLDE *pL, int num){
		if(pL == NULL) return -1;
		
		// criar novo n�
		tNo *pAnt = NULL, *novo = NULL;
		int temRep = lde_repeticao(pL);
		int ehClassf = lde_classificada(pL);
		
		novo = cria_no(num);
		
		// lista ainda vazia
		if(pL->qtdNos == 0) {
        	pL->cabeca->prox = novo;
	        pL->cabeca->ant = novo;
	        novo->ant = pL->cabeca;
	        novo->prox = NULL;
	        pL->qtdNos++;
	        return TRUE;
    	}
		
		
		// lista n�o classificada e permite repeti��o
		if(!ehClassf && temRep){
			tNo *ultimo = pL->cabeca->ant;
		
			ultimo->prox = novo;
			novo->ant = ultimo;
			pL->cabeca->ant = novo;
		
			pL->qtdNos++;
			return TRUE;
		}
		
		// lista classificada com ou sem repeti��o: insere na posi��o correta
		int encontrado = busca_rapida(pL, num, &pAnt);
		
		// caso valor j� existe na lista e n�o permite repeti��es	
		if(encontrado && !temRep) {
			free(novo);
			return -1;	
		}
		
		tNo *pProx = pAnt->prox;
		
		
		// faz as liga��es do novo n�
		pAnt->prox = novo;
		novo->ant = pAnt;
		novo->prox = pProx;
		
		// Atualiza o anterior do pr�ximo n� (se existir)
		if(pProx != NULL){
			pProx->ant = novo;
		}else{
			// atualiza o ponteiro do cabe�alho (inserindo o novo n� no final)
			pL->cabeca->ant = novo;
		}
		pL->qtdNos++;
		return TRUE;
}

/* permite a exclus�o de um elemento da lista */
int lde_excluir(tLDE *pL, int num){
	tNo *pAnt = NULL;
	int encontrado = busca_rapida(pL, num, &pAnt);
	if(!encontrado) return -1; // valor n�o encontrado
	
	int removidos = 0;
	tNo *pAtual = pAnt->prox;
	
	// lista sem repeti��o
	if(!lde_repeticao(pL)){
		pAnt->prox = pAtual->prox;
		if(pAtual->prox != NULL){	// caso o prox do atual seja nulo, faz com que o anterior aponte para o elemento anterior 
			pAtual->prox->ant = pAnt;
		}else{
			pL->cabeca->ant = pAnt;
		}
		free(pAtual);
		pL->qtdNos--;
		return TRUE;
	}else{
		// lista classificada
		if(lde_classificada(pL)){
			while(pAtual != NULL && pAtual->valor == num){
				tNo *pProx = pAtual->prox;
				pAnt->prox = pProx;
				if(pProx != NULL){
					pProx->ant = pAnt;
				}else{
					pL->cabeca->ant = pAnt;	// atualiza o fim
				}
				free(pAtual);
				pAtual = pProx;
				removidos++;
			}
		}else{
			// lista n�o classificada
			while(pAtual != NULL){
				if(pAtual->valor == num){
					tNo *pProx = pAtual->prox;
					pAnt->prox = pProx;
					if(pProx != NULL){
						pProx->ant = pAnt;
					}else{
						pL->cabeca->ant = pAnt;
					}
					free(pAtual);
					pAtual = pProx;
					removidos++;
				}else{
					pAnt = pAtual;
					pAtual = pAtual->prox;
				}
			}
		}
	}
	pL->qtdNos -= removidos;
	return removidos;
}

/* Libera toda a estrutura da lista da mem�ria */
void lde_destruir(tLDE **pl){
	if(pl == NULL || *pl == NULL) return; // lista inv�lida ou vazia
	
	tLDE *l = *pl;
	tNo *pSuc = NULL;
	
	// Percorre toda a lista liberando cada n�
	tNo *pAtual = l->cabeca->prox;  // Come�a ap�s o cabe�a
	while(pAtual != NULL) {
	    tNo *prox = pAtual->prox;
	    free(pAtual);
	    pAtual = prox;
	}
	free(l->cabeca);  // Libera o cabe�a separadamente
	free(l);
	
	free(l);	// libera toda a estrutura da lista
	*pl = NULL; // Atualiza o ponteiro pra NULL; (boa pr�tica)
}

/* Exibe toda a lista no console*/
void lde_imprimir(const tLDE *l){
	if (l == NULL || l->cabeca == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    const tNo *pAtual = l->cabeca->prox;
    printf("[");
    while(pAtual != NULL){
    	printf("%d", pAtual->valor);
    	if(pAtual->prox != NULL) printf(", ");
    	pAtual = pAtual->prox;
	}
	printf("]\n");
}

/* Verifica se a lista � classificada ou n�o */
int lde_classificada(const tLDE *l){
	return (l->isClassif == 1);
}

/* Verifica se a lista permite repeti��o */
int lde_repeticao(const tLDE *l){
	return (l->temRep == 1);
}

/* Verifica se a lista est� vazia */
int lde_lista_vazia(const tLDE *l){
	return (l->qtdNos == 0);
}


/* Implementa��o das fun��es secund�rias */
static tNo * cria_no(int num){
	tNo *no = (tNo *) malloc(sizeof(tNo));
	
	if(no != NULL){
		no->valor = num;	
		no->prox = NULL;
		no->ant = NULL;
	}
	return no;
}

int busca_rapida(tLDE *l, int num, tNo **pAnterior){
	if (l == NULL || l->cabeca == NULL || l->qtdNos == 0) {
        *pAnterior = l->cabeca; // Aponta para o n� cabe�a se lista vazia
        return FALSE;
    }
    
    // Configura sentinela
    int valorOriginal = l->cabeca->valor;
    l->cabeca->valor = num;

    tNo *pAtual = l->cabeca->prox;
    *pAnterior = l->cabeca;

    // Busca em lista classificada
    if (lde_classificada(l)) {
        while (pAtual->valor < num) {
            *pAnterior = pAtual;
            pAtual = pAtual->prox;
        }
    } 
    // Busca em lista n�o-classificada (original)
    else {
        while (pAtual->valor != num) {
            *pAnterior = pAtual;
            pAtual = pAtual->prox;
        }
    }

    // Restaura valor do n� cabe�a
    l->cabeca->valor = valorOriginal;

    // Retorna TRUE se encontrou o valor (e n�o � a sentinela)
    return (pAtual != l->cabeca && pAtual->valor == num);    
}

// TODO: adicionar essas fun��es auxiliares na fun��o principal de inser��o
/*
int inserir_ordenado(tLDE *pL, int num){
	tNo *pAnt;
	int encontrado = busca_rapida(pL, num, &pAnt);
	
	if(encontrado && !pL->temRep) return -1; // n�o permite repeti��o
	
	tNo *novo = cria_no(num);
	novo->prox = pAnt->prox;
	novo->ant = pAnt;
	
	if(pAnt->prox != NULL){
		pAnt->prox->ant = novo;
	}
	pAnt->prox = novo;
	pL->qtdNos++;
	return TRUE;
}

int inserir_no_fim(tLDE *pL, int num){
	
}*/
