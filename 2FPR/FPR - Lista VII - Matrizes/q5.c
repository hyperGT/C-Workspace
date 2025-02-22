#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

void gerarMatrizM3(int n, int m1[n][n], int m2[n][n], int m3[n][n]);

void exibir(int n, int m[n][n]);
void preencherM1(int n, int m[n][n]);
void preencherM2(int n, int m[n][n]);

void main() {
    int m1[N][N], m2[N][N], m3[N][N];
    
    preencherM1(N, m1);
    preencherM2(N, m2);
    exibir(N, m1);
    exibir(N, m2);
    
    gerarMatrizM3(N, m1, m2, m3);
    
    exibir(N, m3);
}

void gerarMatrizM3(int n, int m1[n][n], int m2[n][n], int m3[n][n]) {
    int i, j, k, soma;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (m2[i][j] == 0) {
                m3[i][j] = m1[i][j];
            } else {
                soma = 0; // Reinicializa a soma para cada novo elemento
                // Soma dos elementos da linha i e coluna j
                for (k = 0; k < n; k++) {
                    soma += m1[i][k] + m1[k][j];
                }
                m3[i][j] = soma;
            }
        }
    }
}

void exibir(int n, int m[n][n]) {
    int i, j;
    printf("\n\n======================\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void preencherM1(int n, int m[n][n]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = rand() % 10;
        }
    }
}

void preencherM2(int n, int m[n][n]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = rand() % 2;
        }
    }
}

