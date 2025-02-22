/*
* Do a function that print on terminal the sequence in below according with 'N'
* 	N = 3
*	(1 2)(1 3)(2 1)(2 3)(3 1)(3 2)
*/

#include <stdio.h>

// functions
void printSequence(int n){
	
	int i, j;
	
	for(i=1; i <= n; i++){
		
		for(j=1; j <= n; j++){
			
			if(j!=i){
				// printando i e j, mas apenas se 'j' for diferente de 'i'
				printf("(%d %d) ", i, j);
			}
			
		}
		
	}
}


int main(){
	
	int n;
	
	printf("Insert N: ");
	scanf("%d", &n);
	
	printSequence(n);
}
