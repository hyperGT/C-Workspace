#include <stdio.h>

void funcao1 (int a[], int *b) {
int i;
(*b)--;
a[0] += 1;
for (i=1;i<*b;i++) {
a[i] =(a[i-1]+a[i+1])/2;
}
}
void funcao2 (int k, int z) {
int t = k;
k = z;
z = t;
}
void funcao3 (int w[], int u) {
int i;
for (i=0;i<u;i++) {
printf ("%d ", w[i]);
}
printf ("\n");
}
void main () {
int x[10] = {1,5,8,1,2,9,0,2,3,8};
int i, y = 10;
for (i=0;i<10;i+=2) {
funcao3 (x,y);
funcao1 (x, &y);
if (i%2 == 0) {
funcao2 (x[i], x[i+1]);
}
}
}
