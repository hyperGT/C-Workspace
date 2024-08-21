/*
Questão 01:
	Suponha que não existissem as funções strlen,
	strcpy, strcat e strcmp. Pede-se, então, a
	implementação de funções que tenham o
	mesmo objetivo daquelas.
*/

#include <stdio.h>

int stcmp (char s1[], char s2[]){
	
	int i;	
	
	while((s1[i]) && (s2[i])){
		
		if(s1[i]!=s2[i]){			
			if(s1[i]>s2[i]){
				return 1;
			}else{
				return -1;
			}						
		}
		i++;
	}
	
	if(s1[i]){
		return 1;
	}else{
		if(s2[i]){
			return -1;
		}else{
			return 0;
		}
	}
	/*
	for(i = 0; (s1[i]) && (s2[i]) && (s1[i] == s2[i]); i++);
	
	return s1[i] - s2[i];
	*/
}


int main(){
	
	char st1[100] = "teste", st2[100] = "casa";
	int r;
	
	r = stcmp (st1, st2);
	
	printf("\n %d ", r);
}

