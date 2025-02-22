/*
O Cadastro Nacional de Pessoas Jurídicas (CNPJ) associa a cada empresa um código no formato 
	XX.XXX.XXX/YYYY-ZZ,
onde:
? XX.XXX.XXX: representa a inscrição;
? YYYY: indica se é matriz ou filial. No caso de ser matriz, YYYY será igual a 0001;
? ZZ: dígitos verificadores.
Desenvolver uma função que receba uma string representando um CNPJ e retorne:
 - A inscrição (string),
 - A sequência que representa a matriz ou o número da filial (string),
 - além da informação (no inteiro) se o código representa uma matriz (1)
ou uma filial (0) e, por último, os dígitos verificadores (string).
*/

#include <stdio.h>
#include <string.h>

void ativ01 (char *cnpj, char *inscricao, char *mf, char *dV, int *verify){
	
	int i, j;
	
	i = 0;
	while(cnpj[i]!='/'){
		inscricao[i] = cnpj[i];
		i++;
	}
	inscricao[i] = '\0';
	
	i++; // pula o '/'
	j = 0;
	while(cnpj[i]!='-'){
		mf[j] = cnpj[i];
		j++;
		i++;
	}
	mf[j] = '\0';
	
	// Verificação se é matriz ou filial
	if(strcmp(mf, "0001")==0){
		*verify = 1; // é uma matriz
	}else{
		*verify = 0; // não é uma matriz
	}
	
	i++; // pula o '-'
	j = 0;
	while(cnpj[i]){
		dV[j] = cnpj[i];
		j++;
		i++;
	}
	dV[j] = '\0';
}

int main(){
	
	char cnpj[19] = "48.899.044/0002-21", inscricao[11], yyyy[5], digVerificadores[3];
	int eMatriz;
	
	ativ01 (cnpj, inscricao, yyyy, digVerificadores, &eMatriz);
	
	printf("CNPJ: %s\n", cnpj);
	printf("Numero da inscricao: %s\n", inscricao);
	//printf("Matriz ou filial: %s\n", yyyy);
	
	if(eMatriz == 1){
		printf("Matriz: %s\n", yyyy);
	}else{
		printf("Filial: %s\n", yyyy);
	}
	
	printf("Digitos verificadores: %s\n", digVerificadores);
}
