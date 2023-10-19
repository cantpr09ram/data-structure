#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h> 
#include <time.h> 
#define SIZE 100

//411440430 bo-chain
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int stack [SIZE];

int top =-1;

bool isEmpty(){return(top==-1);}

bool isFull() {return(top==SIZE-1);}

void push(int element){
     if(isFull()){
         printf("Stack is full.\n");
         exit(1);
     }
     stack[++top] = element;
}

int pop() {
    if(isEmpty()){
        printf("Stack is empty.\n");
        exit(2); 
    }
    
    return stack[top--];
}

int main(){
    srand(time(NULL));
    int k, i;
    for(i=0;i<9;i++){
        k = rand()%100;
        push(k);
    }
    //assign integer k the 2nd element from the top of the stack
    //411440430 bo-chain
    k = pop();
    if(isEmpty()){
        printf("1-element stack");
        exit(3);
    }
    k = pop();
    printf("%d\n", k);
    //assign integer k the 2nd element from the top of the stack
    for(i=0;i<2;i++){
        k = rand()%100;
        push(k);
    }
    int j;
    k =pop();
    for(j =1; j<=8;j++){
        if(isEmpty()){
            printf("%d-element stack\n", j);
            exit(4);
        }
        k = pop();
    }
    printf("%d\n", k);
    //assign integer k the bottom element of the stack
    for(i=0;i<9;i++){
        k = rand()%100;
        push(k);
    }
    k=pop();
    while(!isEmpty()){
        k = pop();
    }
    printf("%d\n", k);
    //assign integer k the 2nd element from the bottom of the stack
    for(i=0;i<9;i++){
        k = rand()%100;
        push(k);
    }
    int bottom;
    bottom = pop();
    if(isEmpty()){
        printf("1-element stack\n");
        exit(5);
    }
    while(!isEmpty()){
        k = bottom;
        bottom = pop();
    }
    
    //printout each element of the stack(from top to bottom)
    for(i=0;i<9;i++){
        k = rand()%100;
        push(k);
    }

    k = pop();
    printf("%d ",k);
    while(!isEmpty()){
        k =pop();
        printf("%d ",k);
    }
    //411440430 bo-chain
    return 0;
}
