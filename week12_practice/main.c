#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

typedef struct listNode *listPointer;

struct listNode{
    char symbol;
    int position;
    listPointer link;
};

listPointer top = NULL;

bool isEmpty() {
    return (top == NULL);
}

void push(char symbol, int position) {
    listPointer temp = (listPointer)malloc(sizeof(struct listNode));

    temp->position = position;
    temp->symbol = symbol;
    temp->link = top;

    top = temp;
}

struct listNode pop() {
    if (isEmpty()){
        printf("stack is empty\n");
        exit(2);
    }

    listPointer temp = top;
    struct listNode poppedElement = *temp;
    top = temp->link;
    free(temp);
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
            
            push(symb, position);

        } else if (symb == ')' || symb == ']' || symb == '}') {// symb = )
            struct listNode topEle = pop();
            if (topEle.symbol == otherside(symb)){
                printf("%c%d, %d%c\n", otherside(symb), topEle.position, position, symb);
            } else {
                printf("位置編號 %d 的右括號 %c 沒有可配對的左括號 %c\n", position, symb, otherside(symb));
            }   
        
        }
        position++;
    }

    if (isEmpty()) {
        return 0;
    } else {
        while (!isEmpty()) {
            struct listNode topEle = pop();
            printf("位置編號 %d 的左括號 %c 沒有可配對的右括號 %c\n", topEle.position, topEle.symbol, otherside(topEle.symbol));
        }
    }

    return 0;
}
//(((a+b)]*[[[c+d)] 
