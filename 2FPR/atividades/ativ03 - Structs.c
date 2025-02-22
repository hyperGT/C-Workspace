/*                                            
Uma instituição de ensino armazenou sob a forma de vetores de structs, 
um por turno (manhã e noite), os dados das
diversas disciplinas (código, nome e a quantidade de alunos inscritos).
Considerando a existência dos vetores vetManha e vetNoite, 
conforme definido anteriormente, 
pede-se a implementação de uma função que gere um novo vetor, 
do mesmo tipo, que armazene, para cada disciplina ministrada
na instituição, o total de alunos nela inscritos 
(somando as quantidades matriculadas em cada turno).
*/

// bibliotecas
#include <stdio.h>
#include <string.h>

// tipos
typedef struct{
	
	int codigoDisc;
	char nomeDisc[31];
	int qntAlunosInscritos;
	
}Tdisciplina;

typedef struct{
	
	int qntDisc;
	Tdisciplina dadosDisciplina[100];
	
}Tturno;

// funções
Tturno somarQntAlunosEmDisciplina (Tturno turnoMt, Tturno turnoNt);
void preencherDados (Tturno *turnoM, Tturno *turnoN);
void exibir (Tturno turno, int tam);

void main(){
	
	// declaração de variaveis
	Tturno turnoNoturno, turnoMatutino , totalDisciplinas;
	
	// chamando funções
	preencherDados (&turnoMatutino, &turnoNoturno);
	
	exibir (turnoMatutino, turnoMatutino.qntDisc);
	exibir (turnoNoturno, turnoNoturno.qntDisc);
	
	totalDisciplinas = somarQntAlunosEmDisciplina(turnoMatutino, turnoNoturno);
	
	exibir (totalDisciplinas, totalDisciplinas.qntDisc);
}

// implementações
Tturno somarQntAlunosEmDisciplina (Tturno turnoMt, Tturno turnoNt){
	
	Tturno result;
	int i, j, k = 0, encontrado = 0;
	
	result.qntDisc = 0;
	
	// percorrendo o turno da manhã
	for(i=0;i<turnoMt.qntDisc;i++){
		
		encontrado = 0; // zera o valor de verificação
		for(j=0;j<turnoMt.qntDisc;j++){
			
			if(turnoMt.dadosDisciplina[i].codigoDisc == turnoNt.dadosDisciplina[j].codigoDisc){
								
				result.dadosDisciplina[k] = turnoMt.dadosDisciplina[i]; // copiando os dados da disciplina i no vetor resultado				
				result.dadosDisciplina[k].qntAlunosInscritos += turnoNt.dadosDisciplina[j].qntAlunosInscritos; // soma e guarda tudo no novo vetor
				encontrado = 1; // atualizando a variavel de verificação
				k++; // atualizando a posição e quantidade de elementos do vetor resultado
				break;
			}
		}
		
		// não foi encontrada uma disciplina igual no turno da noite
		if(encontrado != 1){

			result.dadosDisciplina[k] = turnoMt.dadosDisciplina[i]; // copiando os dados da disciplina i no vetor resultado
			k++; // atualizando a posição e quantidade de elementos do vetor resultado
		}
	}
	
	// percorrendo o turno da noite
	for(i=0;i<turnoNt.qntDisc;i++){

		encontrado = 0; // zera o valor de verificação
		
		for(j=0; j<turnoMt.qntDisc;j++){
			
			if(turnoMt.dadosDisciplina[i].codigoDisc == turnoNt.dadosDisciplina[j].codigoDisc){
				encontrado = 1; // encontrou uma disciplina que existe no turno da manhã
				break; // finaliza o loop
			}			
		}
		if(encontrado != 1){
			result.dadosDisciplina[k] = turnoNt.dadosDisciplina[i]; // copiando os dados da disciplina i no vetor resultado
			k++; 
		}
	}
	
	result.qntDisc = k; // atualizando a quantidade de disciplinas armazenadas no vetor resultado
	return result; 
}


void preencherDados (Tturno *turnoM, Tturno *turnoN){		
	
	turnoM->qntDisc = 4;
	turnoN->qntDisc = 3;
	
	// turno manha
	turnoM->dadosDisciplina[0].codigoDisc = 1111;
	strcpy(turnoM->dadosDisciplina[0].nomeDisc, "2SOP");
	turnoM->dadosDisciplina[0].qntAlunosInscritos = 40;
	
	turnoM->dadosDisciplina[1].codigoDisc = 2222;
	strcpy(turnoM->dadosDisciplina[1].nomeDisc, "1FAC");
	turnoM->dadosDisciplina[1].qntAlunosInscritos = 41;
	
	turnoM->dadosDisciplina[2].codigoDisc = 3333;
	strcpy(turnoM->dadosDisciplina[2].nomeDisc, "1ORG");
	turnoM->dadosDisciplina[2].qntAlunosInscritos = 41;
	
	turnoM->dadosDisciplina[3].codigoDisc = 4444;
	strcpy(turnoM->dadosDisciplina[3].nomeDisc, "3DAW");
	turnoM->dadosDisciplina[3].qntAlunosInscritos = 33;
	
	// turno noite
    turnoN->dadosDisciplina[0].codigoDisc = 1111;
    strcpy(turnoN->dadosDisciplina[0].nomeDisc, "2SOP");
    turnoN->dadosDisciplina[0].qntAlunosInscritos = 21;

    turnoN->dadosDisciplina[1].codigoDisc = 2222;
    strcpy(turnoN->dadosDisciplina[1].nomeDisc, "1FAC");
    turnoN->dadosDisciplina[1].qntAlunosInscritos = 35;

    turnoN->dadosDisciplina[2].codigoDisc = 3333;
    strcpy(turnoN->dadosDisciplina[2].nomeDisc, "1ORG");
    turnoN->dadosDisciplina[2].qntAlunosInscritos = 35;
}

void exibir (Tturno turno, int tam){
	
	int i;
	
	for(i=0;i<tam;i++){
		printf("Codigo da Disciplina: %d \n", turno.dadosDisciplina[i].codigoDisc);
		printf("Nome da Disciplina: %s \n", turno.dadosDisciplina[i].nomeDisc);
		printf("Quantidade de alunos inscritos: %d \n\n", turno.dadosDisciplina[i].qntAlunosInscritos);
	}
	printf("\n\n");
}
