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
    for(w = 0; w < ps->top+1; w++){
        printf("%2d ", ps->A[ ps->top - w ]);
        if((w+1)%9 == 0){
            printf("\n");
        }
    }
}

int main(){
    srand(time(NULL));
    int k, i, m;
    k=0;
    
    //question 1
    //411440430 bo-chain
    printf("qustion 2.1\n");
    S.top = s1.top = -1;
    for(i=0;i<18;i++){
        k = rand()%100;
        printf("%d ", k);
        if((i+1) %9 == 0){
            printf("\n");
        }
        push(&S, k);
    }
    //question 2
    while(!isEmpty(&S)){
        push(&s1, m = pop(&S));
    }
    printf("question 2. %d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    //question 3
    //411440430 bo-chain
    while(!isEmpty(&S)){
        push(&s1, pop(&S));
    }
    for (i=0;i< 2; i++){
        push(&S, m = pop(&s1));
    }
    printf("question 2.3: j = %d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    
    //question 4
    while(!isEmpty(&S)){
       push(&s1, pop(&S));
    }
    for (i=0;i< 3; i++){
        push(&S, m = pop(&s1));
    }
    printf("question 2.3: j = %d\n", m);
    while(!isEmpty(&s1)){
        push(&S, pop(&s1));
    }
    //question 5
    //411440430 bo-chain
    printf("question 2.5\n");
    prints(&S);
    //question 6
    while(!isEmpty(&S)){
        push(&s1, pop(&S));
    }
    for (i=0;i< 4; i++){
        push(&S, m = pop(&s1));
    }
    printf("question 2.6: m = %d\n", m);

    return 0;
}
