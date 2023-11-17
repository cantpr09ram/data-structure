#include <stdio.h>
#include <stdlib.h>

int main(void){
	//411440430 bo-chain
    int m, i, j;
    printf("please enter any integer\n");
    scanf("%d",&m);
    int *arr = malloc(sizeof(int) * (m+2) * (m+2)/2);
    for(i = 0; i< m+2; i++){
        for(j = 0; j< i+1; j++){
            
            if(j == 0 || j == i){
                 arr[i * (m+2) + j] = 1;
             }
             else{
                 arr[i*(m+2)+ j] = arr[(i-1)*(m+2)+ j] + arr[(i-1)*(m+2)+ j-1];
            }
        }
    }

    for(i = m+1; i > -1 ; i--){
        for(j = 0; j < i; j++){
            printf("%4d ", arr[i * (m+2)+ j]);
            if(i - 1 == j){
                printf("\n");
            }
        }
    }

    free(arr);
    return 0;
}
