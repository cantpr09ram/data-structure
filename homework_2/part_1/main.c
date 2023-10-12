#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

struct parenthesis {
    char element;
    int position;
};

void push(struct parenthesis stack[], int *top, int value, char element) {
    if (*top == SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    stack[++(*top)].position = value;
    stack[(*top)].element = element;
}

struct parenthesis pop(struct parenthesis stack[], int *top) {
    if (*top == -1) {
        struct parenthesis last = {
            '\0', // Change this to '\0' to represent a null character
            -1
        };
        return last; 
    }
    return stack[(*top)--];
}

bool isEmpty(int top) {
    return top == -1;
}

int main(int argc, char *argv[]) {

    struct parenthesis stack[SIZE] = {};
    int top = -1;
    int position = 0;

    while (1) {
        char symb = getchar();

        if (symb == '\n' || symb == EOF) {
            break;
        }
        
        if (symb == '('){
            push(stack, &top, position, symb);
        } else if (symb == ')') {
            struct parenthesis topEle = pop(stack, &top);
            if (topEle.element == '('){
                printf("(%d, %d)\n", topEle.position, position);
            } else if (topEle.element == '\0'){
                printf("right parenthesis at %d has no matching paraenthesis\n", position);
            }   
            //top--; 
        }
        position++;
    }

    if (isEmpty(top)) {
        printf("Balanced parentheses\n");
    } else {
        printf("%d\n", top);
        
        while (!isEmpty(top)) {
            printf("left parenthesis at %d has no matching paraenthesis\n", stack[top--].position);
        }
    }

    return 0;
}
