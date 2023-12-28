#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

typedef struct node *treePointer;
struct node {
    int data;
    treePointer leftChild, rightChild;
};
//411440430 bo-chain
// Function to insert a node at the beginning of the list
void insert(treePointer *root, int x) {
    if (*root == NULL) {
        treePointer newNode = (treePointer)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->leftChild = newNode->rightChild = NULL;
        *root = newNode;
    } else {
        if (x < (*root)->data) {
            insert(&((*root)->leftChild), x);
        } else {
            insert(&((*root)->rightChild), x);
        }
    }
}

void preorder (treePointer ptr){
    if(ptr){
        printf("%d ", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
   
}

void inorder (treePointer ptr) {
    if (ptr) {
        inorder(ptr->leftChild); // 2*ptr + 1
        printf("%d ", ptr->data);
        inorder(ptr->rightChild); // 2*ptr + 2
    }
    
}

void postorder (treePointer ptr) {
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%d ", ptr->data);
    }
}

treePointer pop(treePointer stack[], int *top) {
    if (*top < 0) return NULL;
    return stack[(*top)--];
}

void push(treePointer node, treePointer stack[], int *top) {
    if (*top >= MAX_STACK_SIZE - 1) return;
    stack[++(*top)] = node;
}

bool empty(int top) {
    return top < 0;
}

void iterInorder(treePointer root) {
    treePointer stack[MAX_STACK_SIZE];
    int top = -1;
    treePointer current = root;

    while (true) {
        while (current) {
            push(current, stack, &top);
            current = current->leftChild;
        }

        current = pop(stack, &top);
        if (!current) break;

        printf("%d ", current->data);
        current = current->rightChild;
    }
}

void addq(treePointer queue[], treePointer node, int *rear) {
    queue[*rear] = node;
    (*rear)++;
}


treePointer deleteq(treePointer queue[], int *front, int *rear) {
    if (*front > *rear) {
        return NULL;
    } else {
        treePointer deletedNode = queue[*front];
        (*front)++;
        return deletedNode;
    }
}

void levelOrder(treePointer root) {
    if (!root)
        return;

    int front = 0, rear = 0;
    treePointer queue[MAX_QUEUE_SIZE];
    addq(queue, root, &rear);

    while (front < rear) {  // Change condition to use <
        treePointer node = deleteq(queue, &front, &rear);
        if (node) {
            printf("%d ", node->data);

            if (node->leftChild)
                addq(queue, node->leftChild, &rear);

            if (node->rightChild)
                addq(queue, node->rightChild, &rear);
        }
    }
}


int main() {
	treePointer root = NULL;
    int i, k;
	//411440430 bo-chain
    
    for(i=0; i<50;i++){
        k = rand()%100;
        insert(&root, i);
        printf("%d ", i);
    }
    printf("\n");
    //inorder
    inorder(root);
    printf("\n");
    //postorder
    postorder(root);
    printf("\n");
    //preorder
    preorder(root);
    printf("\n");
    //iterInorder
    iterInorder(root);
    printf("\n");
    //levelOrder
    levelOrder(root);
    printf("\n");

    return 0;
}