#include <stdio.h>
#include <stdlib.h>

int main(void) {
    typedef struct Triangle {       
        char name;          
        int side1;          
        int side2;          
        int side3;          
    };
    int *arr;
    calloc( arr, sizeof(Triangle) )

    int i, j, k, count = 1, ascii;
    for(i=1; i<6; i++) {
        for (j = 1; j < 6; j++) {
            for (k = 1; k < 6; k++) {
                if((i*i == j*j + k*k) || (j*j == i*i + k*k) || (k*k == j*j + i*i)) {
                    printf("Triangle %c is number %3d a right triangle with side : {%d, %d, %d}\n", (i-1)*25+(j-1)*5+k-1, (i-1)*25+(j-1)*5+k-1, i, j, k);
                }
            }
        }
    }

    return 0;
}