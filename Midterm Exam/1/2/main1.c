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

struct parenthesis peek(struct parenthesis stack[], int *top) {
    if (*top == -1) {
        struct parenthesis last = {
            '\0', // Change this to '\0' to represent a null character
            -1
        };
        return last; 
    }
    return stack[(*top)];
}

bool isEmpty(int top) {
    return top == -1;
}

char otherside(char oneside){
    char otherside = '(';
    if (oneside == '}'){
        otherside = '{';
    }else if (oneside == ']'){
        otherside = '[';
    }else if(oneside == ')'){
        otherside = '(';
    }else if(oneside == '{'){
        otherside = '}';
    }else if(oneside == '['){
        otherside = ']';
    }else if(oneside == '('){
        otherside = ')';
    }
    return otherside;
}
//411440430 bo-chain
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
            struct parenthesis topEle = peek(stack, &top);
            if (topEle.element == otherside(symb)){
                printf("%c%d, %d%c\n", otherside(symb), topEle.position, position, symb);
                pop(stack, &top);
            } else {
                printf("right parenthesis %c at %d has no matching left parenthesis %c \n",symb, position, otherside(symb));
            }   
        
        }
        position++;
    }

    if (isEmpty(top)) {
        return 0;
    } else {
        while (!isEmpty(top)) {
            printf("left parenthesis %c at %d has no matching right parenthesis %c\n", stack[top--].element, stack[top].position, otherside(stack[top].element));
        }
    }

    return 0;
}
//(((a+b)]*[[[c+d)] 
//{(a+b)*c]}}/{[d*[e+f]
//(((a+b)]*[[[c+d)]

