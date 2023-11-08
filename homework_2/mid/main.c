好笑嗎
u8b19
隱形

哈密蛤 — 2023/10/20 01:13
圖片
哈密蛤 — 2023/10/20 09:17
如果我想開始刷leetcode的題目
你覺得我要用哪個程式語法去寫
C++,C,python,JAVA
好笑嗎 — 2023/10/23 12:26
你有在寫電子學的題目嗎?
好笑嗎 — 2023/10/30 21:10
大哥求救組合語言作業
        AREA    prog1, CODE, READWRITE
        ENTRY

data1    DCW 0x8ECC, 0xFE37, -149
data2    DCD 0xFE37, 1, 5, 20
data3    DCB 0XCF, 23, 39, 0x54, 250
data4    DCWU 0x1234
data5    DCB 255
data6    DCDU 0x12345678, -4321
data7    DCB 0xA3
        ALIGN 4,3
data8    DCWU 0xFC25
        ALIGN
data9     DCB "MVP_N.Jokic", 0
data10     DCW 0xEF12

stop    B    stop
        END
這樣寫是對的嗎?
哈密蛤 — 2023/10/30 22:21
對
然後要去找位置
好笑嗎 — 2023/10/30 22:22
不懂
哈密蛤 — 2023/10/30 22:27
他不是每次都要你去節到記憶體那裏
就是要去從那裏找
好笑嗎 — 2023/10/30 23:17
了解
好笑嗎 — 2023/11/01 14:59
問個問題
哈密蛤 — 2023/11/01 15:00
?
好笑嗎 — 2023/11/01 15:00
BIC 歸零的位數是用二進位算嗎？
還有 ORR 的 set 是什麼意思？ 
哈密蛤 — 2023/11/01 15:05
那是第幾題
好笑嗎 — 2023/11/01 15:06
圖片
你錯過了來自 
哈密蛤
 長達幾秒的通話。
 — 2023/11/07 21:56
好笑嗎 — 2023/11/07 21:57
怎麼了？
哈密蛤 — 2023/11/07 21:58
問你個問題
好笑嗎 — 2023/11/07 21:58
嘿
哈密蛤 — 2023/11/07 21:58
我現在在跟別人組隊參加數位轉型&淨零轉型競賽
還差一個人
要三個人
你有興趣嗎🥺
好笑嗎 — 2023/11/07 21:59
啥活動啊?
哈密蛤 — 2023/11/07 22:00
現在只有6個隊伍報名
https://enroll.tku.edu.tw/course.aspx?cid=FKLX20231212
決賽會取10隊
12號截止報名
他要3個人
我們只有兩個人
不是特別難的比賽
哈密蛤 — 昨天 14:37
資料結構考古題翻譯
第一部分：

   (1) 使用 rand()%100+1 生成6個隨機數字，將這些數字依次輸出（每個數字之間用一個空格分隔，在同一行顯示），並將這些數字依次壓入一個創建的堆疊（結構體堆疊S）中。
   (2) 為整數x賦值為堆疊S中從頂部數過來的第11個元素，然後輸出x的值。
   (3) 再次使用 rand()%100+1 生成21個隨機數字，將這些數字依次輸出（每個數字之間用一個空格分隔，每行顯示7個數字），並將這些數字依次壓入堆疊S中。
   (4) 為整數y賦值為堆疊S中從頂部數過來的第11個元素，然後輸出y的值，但不改變S的內容。
   (5) 為整數z賦值為堆疊S中從底部數過來的第2個元素，然後輸出z的值，但不改變S的內容。
   (6) 為整數w賦值為堆疊S中從底部數過來的第3個元素，然後輸出w的值，但不改變S的內容。
   (7) 輸出堆疊S中從頂部到底部的所有數字（每個數字之間用一個空格分隔，每行顯示7個數字）。

第二部分：

   (1) (a) 使用 rand()%100+1 生成21個隨機數字，將這些數字依次輸出（每個數字之間用一個空格分隔，每行顯示7個數字），並將這些數字依次加入一個創建的隊列中。
   (b) 將整數w賦值為隊列尾部的第2個元素，然後輸出w的值。
   (2) (a) 使用 rand()%100+1 生成21個隨機數字，將這些數字依次輸出（每個數字之間用一個空格分隔，每行顯示7個數字），然後將這些數字依次添加到一個創建的隊列中。
   (b) 將整數w賦值為隊列尾部的第3個元素，然後輸出w的值。
   (3) (a) 使用 rand()%100+1 生成21個隨機數字，將這些數字依次輸出（每個數字之間用一個空格分隔，每行顯示7個數字），然後將這些數字依次添加到一個創建的隊列（結構體隊列Q）中。
   (b) 將整數m賦值為隊列頭部的第11個元素，然後輸出m的值，但不改變Q的內容。
   (c) 輸出從隊列頭部到尾部的所有數字（每個數字之間用一個空格分隔，每行顯示7個數字）。

修改括號匹配程式：

   (1) 修改程式以包括三種類型的括號：()、[]和{}。輸入表達式{(a+b)c]}}/{[d[e+f]。輸出應為：
   
   (1,5)
   在第8個位置的右括號]沒有匹配的左括號[
   {0,9}
   在第10個位置的右括號}沒有匹配的左括號{
   [16,20] 
   在第13個位置的左括號[沒有匹配的右括號]
   在第12個位置的左括號{沒有匹配的右括號}
   

   (2) 修改程式以僅包括兩種類型的括號：()和[]。輸入表達式(((a+b)]*[[[c+d)。輸出應為：
   
   (2,6)
   在第7個位置的右括號]沒有匹配的左括號[
   在第15個位置的右括號)沒有匹配的左括號(
   [10,16] 
   在第9個位置的左括號[沒有匹配的右括號]
   在第0個位置的左括號(沒有匹配的右括號)
   
附件檔案類型：document
411440422__.docx
19.22 KB
好笑嗎 — 昨天 15:23
https://orly.nanmu.me/
O'RLY Cover Generator
Generate your O'RLY Cover here to entertain yourself and friends.
圖片
哈密蛤 — 昨天 15:51
附件檔案類型：document
1c70fefac7cc5dfd.docx
21.62 KB
第二部分：
(1) 撰寫一個程式，按以下步驟執行（使用 lastOperationIsdeleteq）：
(a) 使用 rand()%100+1 來取得 21 個隨機數，按以下方式輸出這些數字（一個接一個，中間以空格分隔，每行顯示 7 個數字），然後依次將這些數字壓入一個已創建的佇列。
(b) 指定整數 w 為佇列尾端往前數第 2 個元素，然後輸出 w 的值。
(2) 撰寫一個程式，按以下步驟執行（使用 TotalInQueue）：
(a) 使用 rand()%100+1 來取得 21 個隨機數，按以下方式輸出這些數字（一個接一個，中間以空格分隔，每行顯示 7 個數字），然後逐個將這些數字添加到一個已創建的佇列中。
(b) 指定整數 w 為佇列尾端往前數第 3 個元素，然後輸出 w 的值。
(3) 撰寫一個程式，按以下步驟執行（使用 sacrificing an element space）：
(a) 使用 rand()%100+1 來取得 21 個隨機數，按以下方式輸出這些數字（一個接一個，中間以空格分隔，每行顯示 7 個數字），然後逐個將這些數字添加到一個已創建的佇列（結構體佇列 Q）中。
(b) 指定整數 m 為 Q 的頭部往下數第 11 個元素，然後輸出 m 的值，同時不改變 Q 的狀態。
(c) 按以下方式輸出 Q 中的數字（一個接一個，中間以空格分隔，每行顯示 7 個數字），依次從 Q 的頭部到尾端輸出這些數字
哈密蛤 — 昨天 17:45
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
//411440422 Travis Chan
int top = -1;

struct element {
    char type;
    int pos;
};

struct element stack[SIZE];

int full() {
    return top == 99;
}

int empty() {
    return top == -1;
}

void push(struct element *p) {
    if(full()) {
        printf("the stack is full\n");
        exit(1);
    }
    stack[++top].type = p->type;
    stack[top].pos = p->pos;
}

struct element *pop() {
    if(empty()) {
        printf("the stack is empty\n");
        exit(1);
    }
    return &stack[top--];
}

char other_side(char x) {
    if(x == '(') return ')';
    if(x == ')') return '(';
    if(x == '[') return ']';
    if(x == ']') return '[';
    if(x == '{') return '}';
    if(x == '}') return '{';
}

//411440422 Travis Chan 

int main(void) {
    char symb;
    int pos = 0;
    struct element data;
    struct element *p;    
    while((symb = getchar())!="\n") {
        if(symb == '(' || symb == '[' || symb == '{') {
            data.type = symb;
            data.pos = pos;
            push(&data);
        }
    }
    return 0;
}
好笑嗎 — 昨天 17:58
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
                printf("位置編號 %d 的右括號 %c 沒有可配對的左括號 %c\n", position, symb, otherside(symb));
            }   
        
        }
        position++;
    }

    if (isEmpty(top)) {
        return 0;
    } else {
        while (!isEmpty(top)) {
            printf("位置編號 %d 的左括號 %c 沒有可配對的右括號 %c\n", stack[top--].position, stack[top].element, otherside(stack[top].element));
        }
    }

    return 0;
}
 
https://github.com/cantpr09ram/data-structure/blob/master/homework_2/part_2/main.c
GitHub
data-structure/homework_2/part_2/main.c at master · cantpr09ram/dat...
Contribute to cantpr09ram/data-structure development by creating an account on GitHub.
data-structure/homework_2/part_2/main.c at master · cantpr09ram/dat...
哈密蛤 — 昨天 21:16
圖片
好笑嗎 — 今天 00:25
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

... (還剩 6 行)
收起
main.c
3 KB
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

struct parenthesis {
展開
main.c
3 KB
簡單來說我們下午的時候是把 pop() 出去的東西在撿回來 但是  pop()  出來的可能是垃圾(在如果stack是空的情況下) 
解決的方法一個是用 peek() 一個是放會去之前檢查
﻿
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
main.c
3 KB