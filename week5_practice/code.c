
#include <stdio.h>      // 包含標準輸入輸出函式庫
#include <stdlib.h>     // 包含標準函式庫，用於動態記憶體配置
struct Triangle {       // 定義結構體 Triangle
    char name;          // 三角形名稱
    int side1;          // 第一條邊
    int side2;          // 第二條邊
    int side3;          // 第三條邊
};

int main() {
    int count = 0;      // 用於計算右角三角形的數量
    int ascii = 0;      // ASCII 碼值，用於為每個三角形分配唯一名稱
    int a, b, c;
    for (a = 1; a <= 5; a++) {        // 外層迴圈，用於生成第一條邊的可能值（1 到 5）
        for (b = 1; b <= 5; b++) {    // 中層迴圈，用於生成第二條邊的可能值（1 到 5）
            for (c = 1; c <= 5; c++) {    // 內層迴圈，用於生成第三條邊的可能值（1 到 5）
                
                if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {    // 判斷是否為右角三角形
                    count++;    // 符合條件的三角形數量加一
                    
                    // 動態配置結構體 Triangle 的記憶體空間
                    struct Triangle *triangle = (struct Triangle *)malloc(sizeof(struct Triangle));
                    triangle->name = (char)(ascii);    // 賦值三角形名稱
                    triangle->side1 = a;    // 賦值第一條邊
                    triangle->side2 = b;    // 賦值第二條邊
                    triangle->side3 = c;    // 賦值第三條邊

                    // 輸出右角三角形的資訊
                    printf("Triangle %c is number %3d a right triangle with sides: {%d, %d, %d}\n",triangle->name, ascii, a, b, c);
                }
                ascii++;    // ASCII 碼值遞增，為下一個三角形準備名稱
            }
        }
    }

    return 0;    // 程式執行完畢，返回 0 表示成功
}