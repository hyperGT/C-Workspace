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

// protótipos de funções auxiliares
static tNo * cria_no(int num);

int busca_rapida(tLDE *pL, int num, tNo **pAnterior);

/* Cria uma lista duplamente encadeada vazia e inicializa o nó cabeça */
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

/* permite a inserção de novos elementos na lista */
int lde_adicionar(tLDE *pL, int num){
		if(pL == NULL) return -1;
		
		// criar novo nó
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
		
		
		// lista não classificada e permite repetição
		if(!ehClassf && temRep){
			tNo *ultimo = pL->cabeca->ant;
		
			ultimo->prox = novo;
			novo->ant = ultimo;
			pL->cabeca->ant = novo;
		
			pL->qtdNos++;
			return TRUE;
		}
		
		// lista classificada com ou sem repetição: insere na posição correta
		int encontrado = busca_rapida(pL, num, &pAnt);
		
		// caso valor já existe na lista e não permite repetições	
		if(encontrado && !temRep) {
			free(novo);
			return -1;	
		}
		
		tNo *pProx = pAnt->prox;
		
		
		// faz as ligações do novo nó
		pAnt->prox = novo;
		novo->ant = pAnt;
		novo->prox = pProx;
		
		// Atualiza o anterior do próximo nó (se existir)
		if(pProx != NULL){
			pProx->ant = novo;
		}else{
			// atualiza o ponteiro do cabeçalho (inserindo o novo nó no final)
			pL->cabeca->ant = novo;
		}
		pL->qtdNos++;
		return TRUE;
}

/* permite a exclusão de um elemento da lista */
int lde_excluir(tLDE *pL, int num){
	tNo *pAnt = NULL;
	int encontrado = busca_rapida(pL, num, &pAnt);
	if(!encontrado) return -1; // valor não encontrado
	
	int removidos = 0;
	tNo *pAtual = pAnt->prox;
	
	// lista sem repetição
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
			// lista não classificada
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

/* Libera toda a estrutura da lista da memória */
void lde_destruir(tLDE **pl){
	if(pl == NULL || *pl == NULL) return; // lista inválida ou vazia
	
	tLDE *l = *pl;
	tNo *pSuc = NULL;
	
	// Percorre toda a lista liberando cada nó
	tNo *pAtual = l->cabeca->prox;  // Começa após o cabeça
	while(pAtual != NULL) {
	    tNo *prox = pAtual->prox;
	    free(pAtual);
	    pAtual = prox;
	}
	free(l->cabeca);  // Libera o cabeça separadamente
	free(l);
	
	free(l);	// libera toda a estrutura da lista
	*pl = NULL; // Atualiza o ponteiro pra NULL; (boa prática)
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

/* Verifica se a lista é classificada ou não */
int lde_classificada(const tLDE *l){
	return (l->isClassif == 1);
}

/* Verifica se a lista permite repetição */
int lde_repeticao(const tLDE *l){
	return (l->temRep == 1);
}

/* Verifica se a lista está vazia */
int lde_lista_vazia(const tLDE *l){
	return (l->qtdNos == 0);
}


/* Implementação das funções secundárias */
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
        *pAnterior = l->cabeca; // Aponta para o nó cabeça se lista vazia
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
    // Busca em lista não-classificada (original)
    else {
        while (pAtual->valor != num) {
            *pAnterior = pAtual;
            pAtual = pAtual->prox;
        }
    }

    // Restaura valor do nó cabeça
    l->cabeca->valor = valorOriginal;

    // Retorna TRUE se encontrou o valor (e não é a sentinela)
    return (pAtual != l->cabeca && pAtual->valor == num);    
}

// TODO: adicionar essas funções auxiliares na função principal de inserção
/*
int inserir_ordenado(tLDE *pL, int num){
	tNo *pAnt;
	int encontrado = busca_rapida(pL, num, &pAnt);
	
	if(encontrado && !pL->temRep) return -1; // não permite repetição
	
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
