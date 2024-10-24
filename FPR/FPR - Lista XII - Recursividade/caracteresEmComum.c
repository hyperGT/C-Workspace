/*
Questão 07:
Desenvolver uma função recursiva que
determine o número de caracteres comuns
entre duas strings s1 e s2.
*/

// bibliotecas
#include <stdio.h>
#include <string.h>

// protótipo da função
int qntSameChar (char *str1, char *str2, int i, int j);

void main(){

    char str1[31] = "bombas", str2[31] = "armas";
    int resposta;

    resposta = qntSameChar(str1, str2, 0, 0);

    if(resposta != 0){
        printf("Existem %d caracteres comuns entre as strings.\n", resposta);
    }else{
        printf("Nao existem caracteres comuns entre as strings.\n");
    }
}

int qntSameChar (char *str1, char *str2, int i, int j){


    if(str1[i] == '\0') return 0;  // caso base

    if(str2[j] == '\0') qntSameChar(str1, str2, i+1, 0);

    // os caracteres forem iguais
    if(str1[i] == str2[j]){    // caso geral
        return 1 + qntSameChar(str1, str2, i+1, 0);
    }else{
        return qntSameChar(str1, str2, i, j+1);
    }

}