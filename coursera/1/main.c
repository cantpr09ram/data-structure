#include <stdlib.h>
#include <stdio.h>

int main (){
    int i=0, j=0, k=0;
    scanf("%d %d %d", &i, &j, &k);
    printf("%d, %d, %d\n", i, j, k);
    printf("%d %d\n", i*j*2 + i*k*2 + j*k*2, i*j*k);
}