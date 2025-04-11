/*
* Gabriel Teixeira Charles da Silva
*/

#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_lista {
	int *vetNos;
	int qntNos;
	int tamMax;
	int ehClassificada; // 1: Classificada 0: NC#o Classificada
	int temRepeticao;   // 1: Tem RepetiC'C#o 0: NC#o tem RepetiC'C#o
};

// FunC'C5es auxiliares

/* Busca sequencial: Serve quando a lista possui repetiC'C#o, porC)m nC#o C) ordenada/classificada*/
int buscaSequencial(tLista *lst, int item, int *pos) {

	int i;
	for(i=0; (i<lst->qntNos) && (lst->vetNos[i] != item); i++);

	(*pos) = i;
	return (i < lst->qntNos);   // retorna 1 se achar o valor e 0 caso contrC!rio
}

/* Busca BinC!ria: Serve quando a lista nC#o possui repetiC'C#o e C) classificada/ordenada */
int buscaBinaria(tLista *lst, int item, int *pos) {
	int inicio = 0, meio, fim = lst->qntNos-1, achou = 0;

	while((inicio <= fim) && (!achou)) {
		meio = (inicio+fim)/2;

		if(lst->vetNos[meio] == item) {
			achou = 1;
		} else if(lst->vetNos[meio] > item) {
			fim = meio-1;
		} else {
			inicio = meio+1;
		}
	}

	if(achou) {
		(*pos) = meio;
	} else {
		(*pos) = inicio;
	}
	return achou;
}

// abre espaC'o para inserir um novo valor em sua devida posiC'C#o
void movePraDireita(tLista *l, int pos) {
	if (l->qntNos >= l->tamMax) return;
	
	int i;
	for(i=l->qntNos; i>pos; i++) {
		l->vetNos[i] = l->vetNos[i-1];
	}
}

void movePraEsquerda(tLista *l, int pos, int qt) {
	int i;
	for(i=pos; i<l->qntNos - qt; i++) {
		l->vetNos[i] = l->vetNos[i+1];
	}
}

// Cria uma lista vazia
tLista * lst_criarListaVazia(int maximo, int classif, int repeticao){
	tLista *novaLista = (tLista *) malloc(sizeof(tLista));
	novaLista->vetNos = (int *) malloc(sizeof(int) * maximo);
	novaLista->qntNos = 0;
	novaLista->tamMax = maximo;
	novaLista->ehClassificada = classif;
	novaLista->temRepeticao = repeticao;

	return novaLista;
}

/* Exclui a lista da memC3ria */
void lst_free(tLista *lst) {
	if(lst) {
        free(lst->vetNos);
		free(lst);
	}
}

/* Inclui um novo elemento na lista */
int lst_incluirElemento(tLista *lst, int num) {
    // Verifica se a lista está cheia
    if (lst_estaCheia(lst)) return 0;

    int novaPos = 0;
    int achou = 0;

    if (lst_eClassif(lst)) {
        // Lista é classificada → usa busca binária
        achou = buscaBinaria(lst, num, &novaPos);

        // Se não permite repetição e o elemento já existe, não insere
        if (!lst_temRepet(lst) && achou) return -1;

        // Abre espaço para o novo valor
        movePraDireita(lst, novaPos);

    } else {
        // Lista NÃO é classificada → inserção no final
        // Se não permite repetição, verifica se o valor já existe
        if (!lst_temRepet(lst) && buscaSequencial(lst, num, &novaPos)) {
            return -1;
        }

        novaPos = lst->qntNos;
    }

    // Insere o valor na posição apropriada
    lst->vetNos[novaPos] = num;
    lst->qntNos++;
    return 1;
}


/* Exclui um valor da lista */
int lst_excluirElemento(tLista *lst, int num) {

	int achou,
	    i,
	    qt = 0, // quantidade de elementos a serem removidos
	    pos = 0;

	// verificar se a lista estC! vazia
	if(lst_estaVazia(lst)) return 0;

	// lista ordenada
	if(lst_eClassif(lst)) {

		achou = buscaBinaria(lst, num, &pos);
		if(!achou) return -1;

		// se nC#o tiver repetiC'C#o
		if(lst_temRepet(lst)) {
			int i = pos;
			while(i < lst->qntNos && lst->vetNos[i] == num) {
				// atualizando a quantidade de elementos a serem removidos
				qt++;
				// atualizando a posiC'C#o do C-ndice
				i++;
			}
		} else {
			qt = 1; // nC#o possui repetiC'C#o, logo, apenas 1 elemento serC! removido da lista
		}

	} else { // caso nC#o seja classificada

		if(lst_temRepet(lst)) {
			int i, j=0;
			for(i=0; i<lst->qntNos; i++) {
				if(lst->vetNos[i] != num) {
					lst->vetNos[j++] = lst->vetNos[i];
				}
			}
			qt = lst->qntNos - j; // elementos removidos
			lst->qntNos -= j;
			return qt > 0 ? 1 : -1;
		} else {
			achou = buscaSequencial(lst, num, &pos);

			if(!achou) return -1;

			qt = 1;
		}
	}

	if(qt>0) {
		movePraEsquerda(lst, pos, qt);
		lst->qntNos -= qt;
		return 1;
	}
	return -1;
}

/* Verifica se a lista estC! vazia, retornando 1 caso esteja e 0 caso contrC!rio */
int lst_estaVazia(const tLista *lst) {
	return (lst->qntNos == 0);
}

/* Verifica se a lista estC! cheia */
int lst_estaCheia(const tLista *lst) {
	return (lst->qntNos == lst->tamMax);
}

/* Verifica se a lista C) classificada */
int lst_eClassif(const tLista *lst) {
	return (lst->ehClassificada == 1);
}

/* Verifica se a lista permite repetiC'C#o */
int lst_temRepet(const tLista *lst) {
	return (lst->temRepeticao == 1);
}

/* Percorre a lista e exibe todos os itens */
void lst_exibe(const tLista *lst) {
    //printf("qntNos: %d\n", lst->qntNos); // debug
	int i;
	for(i=0; i<lst->qntNos; i++) {
		printf("%d, ", lst->vetNos[i]);
	}
}