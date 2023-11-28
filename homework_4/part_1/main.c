#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct node{
    char data;
    struct node *next;
};
typedef struct node NODE;

NODE *push(NODE *top,int val) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = val;
    newnode->next = top;
    return newnode;
}
bool emptys(NODE *top){
    if(top == NULL){
        return true;
    }
    return false;
}
NODE *pop(NODE *top) {
    if(emptys(top)) {
        printf("stack is empty!\n");
        return NULL;
    }
    NODE *tempnode = top;
    top = top->next;
    free(tempnode);
    return top;
}
void print(NODE*top) {
    //printf("top ");
    while(top != NULL) {
        printf("%d ",top->data);
        top = top->next;
    }
    printf("\n");
}
int main() {
    //a simple stack example
    NODE *top = NULL;
    int i;
    for (int i = 0; i < 10; i++){
        top = push(top, i);
    }
    print(top);
    top = pop(top);
    print(top);
    
}
