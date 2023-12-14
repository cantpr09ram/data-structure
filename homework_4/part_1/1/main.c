#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;

struct listNode {
    char symbol;
    int position;
    listPointer link;
};

struct stack {
    listPointer top;
} S;

listPointer top = NULL; // initial empty stack

int empty(struct stack *ps){
    return (ps->top==NULL);
}

void push(struct stack *ps, char symbol, int position){ // push x onto stack -> insert node in the front
    listPointer p = (listPointer) malloc(sizeof(struct listNode));
    p->symbol = symbol;
    p->position = position;
    p->link = ps->top; // top == NULL
    ps->top = p;
}

struct listNode pop(struct stack *ps){ // pop stack and return the popped element -> delete node in the front
    if(empty(ps)) {
        printf("stack is empty");
    }
    listPointer p = ps->top;
    struct listNode poppedElement = *p;
    ps->top = p->link;
    return poppedElement;
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
    
    int position = 0;

    while (1) {
        char symb = getchar();

        if (symb == '\n' || symb == EOF) {
            break;
        }
        
        if (symb == '(' || symb == '[' || symb == '{'){
            
            push(&S, symb, position);

        } else if (symb == ')' || symb == ']' || symb == '}') {// symb = )
            struct listNode topEle = pop(&S);
            if (topEle.symbol == otherside(symb)){
                printf("%c%d, %d%c\n", otherside(symb), topEle.position, position, symb);
            } else {
                printf("位置編號 %d 的右括號 %c 沒有可配對的左括號 %c\n", position, symb, otherside(symb));
            }   
        
        }
        position++;
    }

    if (empty(&S)) {
        return 0;
    } else {
        while (!empty(&S)) {
            struct listNode topEle = pop(&S);
            printf("位置編號 %d 的左括號 %c 沒有可配對的右括號 %c\n", topEle.position, topEle.symbol, otherside(topEle.symbol));
        }
    }

    return 0;
}
//(((a+b)]*[[[c+d)]