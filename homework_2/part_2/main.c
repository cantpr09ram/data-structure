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

char otherside(char left){
    char right = '(';
    if (left == '}'){
        right = '{';
    }else if (left == ']'){
        right = '[';
    }

    return right;
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
        
        if (symb == '(' || symb == '[' || symb == '{'){
            push(stack, &top, position, symb);

        } else if (symb == ')' || symb == ']' || symb == '}') {// symb = )
            struct parenthesis topEle = pop(stack, &top);
            if (topEle.element == otherside(symb)){
                printf("%c%d, %d%c\n", otherside(symb), topEle.position, position, symb);
            } else {
                printf("right parenthesis at %d has no matching paraenthesis\n", position);
            }   
        
        }
        position++;
    }

    if (isEmpty(top)) {
        printf("Balanced parentheses\n");
    } else {
        while (!isEmpty(top)) {
            printf("left parenthesis at %d has no matching paraenthesis\n", stack[top--].position);
        }
    }

    return 0;
}
