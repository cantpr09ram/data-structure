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
} inStack, outStack;

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

void addq(struct stack* ps, int data) {
    push(ps, data);
}
//411440430 \u8b19
int deleteq(struct stack* ps_in) {
    struct stack ps_out;
    ps_out.top = NULL;

    if (empty(ps_in)) {
        fprintf(stderr, "Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    while (!empty(ps_in)) {
        push(&ps_out, pop(ps_in));
    }

    int x = pop(&ps_out);
    
    while (!empty(&ps_out)) {
        push(ps_in, pop(&ps_out));
    }

    return x;
}

int main() {
    struct stack s1, s2;
    int i, m, k;
    // Initialize the stacks
    s1.top = s2.top = NULL;
	//411440430 \u8b19
    printf("assign integer m 3th element from the top of the queue\n");
   // Initialize the stacks
    s1.top = s2.top = NULL;
    
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&s1, k);
    }
    prints(&s1);
    
    for(i=0; i<3; i++){
        addq(&s2, m = deleteq(&s1));
    }
    printf("%d\n", m);
    prints(&s1);

    printf("\nassign integer m 3th element from the top of the queue, leaveing queue unchange\n");
   // Initialize the stacks
    s1.top = s2.top = NULL;
    
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&s1, k);
    }
    prints(&s1);
    
    for(i=0; i<3; i++){
        addq(&s2, m = deleteq(&s1));
    }
    printf("%d\n", m);

    while(!empty(&s1)) {
        addq(&s2, deleteq(&s1));
    }
    while(!empty(&s2)) {
        addq(&s1, deleteq(&s2));
    }
    prints(&s1);
	//411440430 \u8b19
    printf("assign integer m 12th element from the top of the queue\n");
   // Initialize the stacks
    s1.top = s2.top = NULL;
    
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&s1, k);
    }
    prints(&s1);
    
    for(i=0; i<12; i++){
        addq(&s2, m = deleteq(&s1));
    }
    printf("%d\n", m);
    prints(&s1);

    printf("\nassign integer m 12th element from the top of the queue, leaveing queue unchange\n");
   // Initialize the stacks
    s1.top = s2.top = NULL;
    
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&s1, k);
    }
    prints(&s1);
    
    for(i=0; i<12; i++){
        addq(&s2, m = deleteq(&s1));
    }
    printf("%d\n", m);

    while(!empty(&s1)) {
        addq(&s2, deleteq(&s1));
    }
    while(!empty(&s2)) {
        addq(&s1, deleteq(&s2));
    }
    prints(&s1);
	//411440430 \u8b19
    printf("assign integer m 1st element from the bottom of the queue\n");
   // Initialize the stacks
    s1.top = s2.top = NULL;
    
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&s1, k);
    }
    prints(&s1);
    
    while(!empty(&s1)) {
        addq(&s2, m = deleteq(&s1));
    }
    printf("%d\n", m);
    prints(&s1);

    printf("\nassign integer m 1st element from the bottom of the queue, leaveing queue unchange\n");
   // Initialize the stacks
    s1.top = s2.top = NULL;
    
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&s1, k);
    }
    prints(&s1);
    
    while(!empty(&s1)) {
        addq(&s2, m= deleteq(&s1));
    }
    printf("%d\n", m);

    while(!empty(&s1)) {
        addq(&s2, deleteq(&s1));
    }
    while(!empty(&s2)) {
        addq(&s1, deleteq(&s2));
    }
    prints(&s1);


    return 0;
}

/*
printf("%d\n", m);
*/
