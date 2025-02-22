#include <stdio.h>

//prototipo 

int questao6 (int vet1[] ,int quant1, int vet2[], int *quant2, int num)
{
    int j=0,i, contS = 0;
    for(i=0; i<quant1; i++)
    {
    	
    	if(contS>num){
    		
	        if(vet1[i]==0)
	        {
	           contS++;
	        }
	        
	        if(contS = num){
	        	while(vet1[i] != 0){
	        		vet2[j] = vet1[i];
	        		i++;
	        		j++;
				}
				*quant2 = j;
            	return 1;
			}
		}
    }
    return 0;
}

void exibir (int vet2[], int quant2)
{
    //declaração de variáveis
    int i;

    //percorrendo o vetor
    printf ("\nVetor: ");
    for (i=0;i<quant2;i++)
    {
        printf ("%d ", vet2[i]);
    }
    printf ("\n\n");
}

int main()
{
   int vet1[12]={5,7,3,0,5,9,0,1,0,3,4,8},
   vet2[12], 
   quant2,
   num, 
   resp;
   

   	printf("Insira um valor para o subconjunto desejado:");
   	scanf("%d", &num);

   	resp = questao6 ( vet1 , 12, vet2,  &quant2, num);

	
	exibir(vet2, quant2);
   
   if(resp>0){
   	
   		printf("\nSubconjunto: ");
		
   }

    return 0;
}
