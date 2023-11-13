#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h> 
#include <time.h> 
#define SIZE 100

//411440430 bo-chain
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct {
    int A[SIZE];
    int top;
}stack;
stack S, s1;
int isEmpty(stack *ps) {
    return (ps->top == -1);
};

bool isFull(stack *ps) {
    return(ps -> top==SIZE-1);
};

void push(stack *ps, int x){
    if(isFull(ps)){
        printf("Stack is full.\n");
        exit(1);
    }
    ps->A[++ps->top] = x;
};

int pop(stack *ps) {
    if(isEmpty(ps)){
        printf("Stack is empty.\n");
        exit(2); 
    }
    
    return ps -> A[ps->top--];
}

void prints(stack*ps){
    int w;
    printf("\n");
    for(w = 0; w < ps->top+1; w++){
        printf("%2d ", ps->A[ ps->top - w ]);
        if((w+1)%10 == 0){
            printf("\n");
        }
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int k, i, m;
    k=0;
    
    //question 1
    S.top = s1.top = -1;
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }
    prints(&S);
    for(i=0; i<3; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        m = pop(&S);
    }
    printf("%d\n", m);
    prints(&S);

    //question 2
    S.top = s1.top = -1;
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);
    for(i=0; i<3; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        push(&s1, m = pop(&S));
    }
    printf("%d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    prints(&S);

    //question 3
    prints(&S);
    for(i=0; i<10; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        m = pop(&S);
    }
    printf("%d\n", m);
    prints(&S);
    //question 4
    S.top = s1.top = -1;
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);
    for(i=0; i<10; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        push(&s1, m = pop(&S));
    }
    printf("%d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    prints(&S);

    //question 5
    prints(&S);
    while(!isEmpty(&S)){
        m = pop(&S);
    }
    printf("%d\n", m);
    prints(&S);
    //question 6
    S.top = s1.top = -1;
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);
    while(!isEmpty(&S)){
        push(&s1, m = pop(&S));
    }
    printf("%d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    prints(&S);

    //question 7
    prints(&S);
    for(i=0; i<30 - 2; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        m = pop(&S);
    }
    printf("%d\n", m);
    prints(&S);
    //question 8
    S.top = s1.top = -1;
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);
    for(i=0; i<30 - 2; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        push(&s1, m = pop(&S));
    }
    printf("%d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    prints(&S);

    //question 9
    prints(&S);
    for(i=0; i<30 - 3; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        m = pop(&S);
    }
    printf("%d\n", m);
    prints(&S);
    //question 10
    S.top = s1.top = -1;
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);
    for(i=0; i<30 - 3; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        push(&s1, m = pop(&S));
    }
    printf("%d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    prints(&S);

    //question 11
    prints(&S);
    for(i=0; i<30 - 4; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        m = pop(&S);
    }
    printf("%d\n", m);
    prints(&S);
    //question 12
    S.top = s1.top = -1;
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);
    for(i=0; i<30 - 4; i++){
        if(isEmpty(&S)){
            printf("%d element(s) stack", i+1);
        }
        push(&s1, m = pop(&S));
    }
    printf("%d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    prints(&S);

    return 0;
}
