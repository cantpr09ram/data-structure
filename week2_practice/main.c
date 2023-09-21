#include <stdlib.h>
#include <stdio.h>

int main() {
    char id[50];
    int i = 0, j=0;
	//411440430 bochain
    while (1) {
        char c = getchar();

        if (c == '\n' || c == EOF) {
            break;
        }
        id[i] = c;
        i++;
    }
    for (j = i - 1; j >= 0; j--) {
        putchar(id[j]);
    }
    printf("\n");
    
    system("pause");
    return 0;
}
