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
    int TotalinQueue;
}queue;

queue Q, RQ;

int isEmpty(queue *pq) {
    return (pq->front == pq->rear && pq->TotalinQueue == 0);
};

bool isFull(queue *pq) {
    return(pq->front == (pq->rear+1)%SIZE && pq->TotalinQueue == SIZE);
};

void addq(queue *pq, int data){
    if(isFull(pq)){
        printf("Queue is full.\n");
        exit(1);
    }
    pq->TotalinQueue += 1;
    pq->rear = (pq->rear + 1) % SIZE;
    pq->A[pq->rear] = data;
};

int deleteq(queue *pq) {
    if(isEmpty(pq)){
        printf("Queue is empty.\n");
        exit(2); 
    }
    pq->TotalinQueue -= 1;
    pq->front = (pq->front + 1) % SIZE;
    return pq->A[pq->front];
}

void printq(queue *pq) {
    int w;
    for(w = pq->TotalinQueue ; w >=0; w--){
        printf("%3d ", pq->A[w]);
        if((w - pq->front)% 9 == 0  || w == pq->rear){
            printf(" \n");
        }
    }
}
int main(void){
    srand(time(NULL));
    int i, m, t, length, k;
    
    //411440430 bo-chain
    // question 1
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("question 3.3 (a)\n");
    for(i=0;i<18;i++){
        k = rand()%100+1;
        addq(&Q, k);
        printf("%3d ", k);
        if((i+1)%9 == 0){
            printf("\n");
        }
    }
    //question 2
    length = Q.TotalinQueue + 1;
    for (i=0; i<length -4; i++){
        if(isEmpty(&Q)){
            printf("%d-element queue",i);
            exit(3);
        }
        k = deleteq(&Q);
    }
    printf("question 3.2 (b) n = %d\n", k);

    while(!isEmpty(&Q)){
         addq(&RQ, deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
         addq(&Q, deleteq(&RQ));
    }
    //question 3
    printf("question 3.2 (c)\n");
    printq(&Q);
    return 0;
}
