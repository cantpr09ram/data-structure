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

int main(){
    
    S.top = -1;
    s1.top = -1;
    srand(time(NULL));
    int k, i;
    for(i=0;i<9;i++){
        k = rand()%100;
        push(&S, k);
    }

    
    //assign integer k the 2nd element from the top of the stack, leaveing S unchange
    for (i=0;i<2;i++){
        if(isEmpty(&S)){
             printf("1-element stack");
             exit(3);
        }else{
            push(&s1, k = pop(&S));
        }
    }
    printf("the 2nd element from the stack %d\n", k);

    while(!isEmpty(&s1)){
        push(&S, k=pop(&s1));
    }
    //assign integer k the 9th element from the top of the stack, leaveing S unchange
    for (i=0;i<9;i++){
        if(isEmpty(&S)){
            printf("%d\n",i);
            exit(4);
        }else{
            push(&s1, k = pop(&S));
            
        }
    }
    printf("the 9th element from the top of the stack %d\n", k);

    while(!isEmpty(&s1)){
        push(&S, k=pop(&s1));
    }
    //assign integer k the bottom element from the top of the stack, leaveing S unchange
    while(!isEmpty(&S)){
        push(&s1, k = pop(&S));
    }
    printf("the bottom element from the top of the stack %d\n", k);

    while(!isEmpty(&s1)){
        push(&S, k=pop(&s1));
    }
    //assign integer k the 2nd element from the bottom of the stack, leaveing S unchange
    int bottom;
    push(&s1, bottom = pop(&S));
    while (isEmpty(&S)){
        printf("1-element stack");
        exit(5);
    }
    while(!isEmpty(&S)){
        k = bottom;
        push(&s1, bottom = pop(&S));
    }
    printf("the 2nd element from the bottom of the stack %d\n", k);

    while(!isEmpty(&s1)){
        push(&S, k=pop(&s1));
    }
    //print the stack from top to bottom, leaveing S unchange
    while(!isEmpty(&S)){
        push(&s1, k = pop(&S));
        printf("%d ",k);
    }

    while(!isEmpty(&s1)){
        push(&S, k=pop(&s1));
    }
    return 0;
}
