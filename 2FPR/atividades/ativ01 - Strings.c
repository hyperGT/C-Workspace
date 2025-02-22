/*
O Cadastro Nacional de Pessoas Jur�dicas (CNPJ) associa a cada empresa um c�digo no formato 
	XX.XXX.XXX/YYYY-ZZ,
onde:
? XX.XXX.XXX: representa a inscri��o;
? YYYY: indica se � matriz ou filial. No caso de ser matriz, YYYY ser� igual a 0001;
? ZZ: d�gitos verificadores.
Desenvolver uma fun��o que receba uma string representando um CNPJ e retorne:
 - A inscri��o (string),
 - A sequ�ncia que representa a matriz ou o n�mero da filial (string),
 - al�m da informa��o (no inteiro) se o c�digo representa uma matriz (1)
ou uma filial (0) e, por �ltimo, os d�gitos verificadores (string).
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
	
	// Verifica��o se � matriz ou filial
	if(strcmp(mf, "0001")==0){
		*verify = 1; // � uma matriz
	}else{
		*verify = 0; // n�o � uma matriz
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
