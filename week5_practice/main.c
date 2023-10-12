#include <stdio.h>
#include <stdlib.h>

typedef struct Triangle {
    int num;
    int side1;
    int side2;
    int side3;
} Triangle;

int main(void) {
    Triangle *arr = (Triangle *)malloc(sizeof(Triangle));
    //Triangle *arr
    //This part declares a pointer variable named arr of type Triangle*
    //(Triangle *)
    //tells the compiler to treat the result of malloc as a pointer to a Triangle
    //malloc(sizeof(Triangle)) 
    //This part allocates memory dynamically using the malloc function. malloc stands for "memory allocation."

    int i, j, k, count = 0, ascii;
    for(i=1; i<6; i++) {
        for (j = 1; j < 6; j++) {
            for (k = 1; k < 6; k++) {
                if((i*i == j*j + k*k) || (j*j == i*i + k*k) || (k*k == j*j + i*i)) {
                    count++;
                    arr = (Triangle *)realloc(arr, count * sizeof(Triangle));
                    arr[count-1].num = (i-1)*25+(j-1)*5+k-1;
                    arr[count-1].side1 = i;
                    arr[count-1].side2 = j;
                    arr[count-1].side3 = k;
                }
            }
        }
    }
    int x;
    for (x = 0; x < count; x++) {
        printf("Triangle %c is number %3d a right triangle with side : {%d, %d, %d}\n", arr[x].num, arr[x].num, arr[x].side1, arr[x].side2, arr[x].side3);
    }
    printf("411440430 bo-chain");
    free(arr);
    return 0;
}
