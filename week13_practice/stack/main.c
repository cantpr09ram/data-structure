#include <stdio.h>
#include <stdlib.h>
//411440430 \u8b19
typedef struct listNode *listPointer;
struct listNode {
    int data;
    listPointer link;
};

struct stack {
    listPointer top;
} S, S1;

listPointer top = NULL; // initial empty stack

int empty(struct stack *ps){
    return (ps->top==NULL);
}

void push(struct stack *ps, int x){ // push x onto stack -> insert node in the front
    listPointer p = (listPointer) malloc(sizeof(struct listNode));
    p->data = x;
    p->link = ps->top; // top == NULL
    ps->top = p;
}

int pop(struct stack *ps){ // pop stack and return the popped element -> delete node in the front
    if(empty(ps)) printf("stack is empty");
    listPointer p = ps->top;
    int x = p->data;
    ps->top = p->link;
    free(p);
    return x;
}

void prints(struct stack *ps){
    int counter = 0;
    listPointer temp = ps->top;
    while (!(temp == NULL)) {
        counter++;
        printf("%2d ",temp->data);
        if((counter) % 10 == 0){
            printf("\n");
        }
        temp = temp->link;
    }
    
}

int main(void) {
    struct stack S, S1;
    int i, m, k;

    //question 1
    printf("assign integer m the 1st element from the top of the stack, leaveing stack unchange\n");
    S.top = S1.top = NULL; // Initialize two stacks
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);

    for(i=0; i<1; i++){
        if(empty(&S)){
            printf("%d element(s) stack", i+1);
        }
        push(&S1, m = pop(&S));
    }
    printf("%d\n", m);
    while(!empty(&S1)){
        push(&S, pop(&S1));
    }
    prints(&S);
	//411440430 \u8b19
    //question 2
    printf("assign integer m the 3th element from the top of the stack, leaveing stack unchange\n");
    S.top = S1.top = NULL; // Initialize two stacks
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);

    for(i=0; i<3; i++){
        if(empty(&S)){
            printf("%d element(s) stack", i+1);
        }
        push(&S1, m = pop(&S));
    }
    printf("%d\n", m);
    while(!empty(&S1)){
        push(&S, pop(&S1));
    }
    prints(&S);

    //question 3
    printf("assign integer m 1st element from the bottom of the stack, leaveing stack unchange\n");
    S.top = S1.top = NULL; // Initialize two stacks
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);

    while(!empty(&S)){
        push(&S1, m = pop(&S));
    }
    printf("%d\n", m);

    while(!empty(&S1)){
        push(&S, pop(&S1));
    }
    prints(&S);
	//411440430 \u8b19
    //question 3
    printf("assign integer m 10th element from the bottom of the stack, leaveing stack unchange\n");
    S.top = S1.top = NULL; // Initialize two stacks
    int arr[10] = {0};
    int j;
    for(i=0;i<30;i++){
        k = rand()%100;
        push(&S, k);
    }

    prints(&S);

    while(!empty(&S)){
        push(&S1, m = pop(&S));
        for(j=0; j<9; j++){
            arr[9-j] = arr[9-j-1];
        }
        arr[0] = m;
    }
    printf("%d \n", arr[9]);

    while(!empty(&S1)){
        push(&S, pop(&S1));
    }
    prints(&S);
    return 0;
}
/*
8->9
7->8
.
0->1
0 = m
*/
