#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> 
#define SIZE 100

//411440430 bo-chain
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct {
    int A[SIZE];
    int front, rear;
    
}queue;

queue Q, RQ;

int isEmpty(queue *pq) {
    return (pq->front == pq->rear );
};

bool isFull(queue *pq) {
    return(pq->front == (pq->rear+1)%SIZE);
};

void addq(queue *pq, int data){
    if(isFull(pq)){
        printf("Queue is full.\n");
        exit(1);
    }
    pq->rear = (pq->rear + 1) % SIZE;
    pq->A[pq->rear] = data;
};

int deleteq(queue *pq) {
    if(isEmpty(pq)){
        printf("Queue is empty.\n");
        exit(2); 
    }

    pq->front = (pq->front + 1) % SIZE;
    return pq->A[pq->front];
}
void printq(queue *pq) {
    int w;
    for(w = pq->front+1; w < pq->rear+1; w++){
        printf("%3d ", pq->A[w]);
        if((w - pq->front)% 9 == 0  || w == pq->rear){
            printf("\n");
        }
    }
}

int main(void){
    srand(time(NULL));
    int i, k, length = 0, x, y;
    //411440430 bo-chain
    // question 1
    Q.front = Q.rear = RQ.front = RQ.rear = -1;

    printf("question 3.4 (a)\n");
    for(i=0;i<18;i++){
        k = rand()%100+1;
        addq(&Q, k);
        printf("%3d ", k);
        if((i+1)%9 == 0){
            printf("\n");
        }
        length++;
    }
    
    // question 2
    for (i = 0; i <12; i++){
        if(isEmpty(&Q)){
            printf("%d-element queue\n", i);
        }else{
            x = deleteq(&Q);
        }
    }
    printf("question 3.4 (b) x = %d\n", x);

    //question 3
    printf("question 3.4 (c)\n");
    printq(&Q);
    //question 4
    printf("question 3.4 (d) ");
    for (i = 0; i < 8; i++){
        if(isEmpty(&Q)){
            printf("%d-element queue\n", i);
            exit(6);
        }else{
            y = deleteq(&Q);
        }
        
    }
    printf("y = %d", y);
    return 0;
}
