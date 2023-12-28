#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

typedef struct node *treePointer
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
}

void inorder (treePointer ptr) {
    if (ptr) {
        inorder(ptr->leftChild); // 2*ptr + 1
        printf("%d", ptr->data);
        inorder(ptr->rightChild); // 2*ptr + 2
    }
    
}

void postorder (treePointer ptr) {
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%d", ptr->data);
    }
}

void iterInorder (treePointer node) {
    int top = -1;
    treePointer stack[MAX_STACK_SIZE];
    for(;;){
        for(; node; node = node->leftChild){
            push(node);
        }
        node = pop()
        if(!node){
            break;
        }
        printf("%d", node->data);
        node = node->rightChild;
    }
}

void levelOrder(treePointer ptr) {
    int front = rear = 0;
    treePointer queue[MAX_QUEUE_SIZE];
    if(!ptr){
        return;
    }
    addq(ptr);
    for(;;) {
        ptr = deleteq();
        if(ptr) {
            printf("%d", ptr->data);
            if(ptr->leftChild){
                addq(ptr->leftChild);
            }
            if(ptr->rightChild){
                addq(ptr->rightChild);
            }
        }
        else break;
    }
}