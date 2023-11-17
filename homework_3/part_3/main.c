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
    int lastOperationIsDeleteq;
    int TotalinQueue;
}queue;

queue Q, RQ;

int isEmpty(queue *pq) {
    return (pq->front == pq->rear);
};

bool isFull(queue *pq) {
    return(pq -> front==(pq->rear+1)%SIZE);
};

void addq(queue *pq, int data){
    if(isFull(pq)){
        printf("Queue is full.\n");
        exit(1);
    }
    pq->TotalinQueue++;
    pq->lastOperationIsDeleteq = 0;
    pq->rear = (pq->rear + 1) % SIZE;
    pq->A[pq->rear] = data;
};

int deleteq(queue *pq) {
    if(isEmpty(pq)){
        printf("Queue is empty.\n");
        exit(2); 
    }
    pq->TotalinQueue --;
    pq->lastOperationIsDeleteq = 1;
    pq->front = (pq->front + 1) % SIZE;
    return pq->A[pq->front];
}

void printq(queue *pq) {
    int w;
    for(int w = pq->front+1; w < pq->rear+1; w++){
        printf("%2d ", pq->A[w]);
        if((w - pq->front)% 10 == 0  || w == pq->rear){
            printf("\n");
        }
    }
}

int main(void){
    srand(time(NULL));
    int k, i, m;
    
    //411440430 bo-chain
    // question 1
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 3th element from the top of the queue\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    for (i=0;i<3;i++){
        if(isEmpty(&Q)){
            printf("1-element queue");
            exit(3);
        }
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);
    printq(&Q);
    // question 2
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 3th element from the top of the queue, leaveing queue unchange\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    for (i=0;i<3;i++){
        if(isEmpty(&Q)){
            printf("1-element queue");
            exit(3);
        }
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);
    while(!isEmpty(&Q)){
        addq(&RQ, deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, deleteq(&RQ));
    }
    printq(&Q);
    //question 3
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 10th element from the top of the queue\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    for (i=0;i<10;i++){
        if(isEmpty(&Q)){
            printf("1-element queue");
            exit(3);
        }
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);
    
    printq(&Q);

    //question 4
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 10th element from the top of the queue, leaveing queue unchange\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    for (i=0;i<10;i++){
        if(isEmpty(&Q)){
            printf("1-element queue");
            exit(3);
        }
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);
    while(!isEmpty(&Q)){
        addq(&RQ, deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, deleteq(&RQ));
    }
    printq(&Q);
    //question 5
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 1st element from the bottom of the queue\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(!isEmpty(&Q)){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);
    
    printq(&Q);

    //question 6
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 1st element from the bottom of the queue, leaveing queue unchange\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(!isEmpty(&Q)){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);

    while(!isEmpty(&Q)){
        addq(&RQ, deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, deleteq(&RQ));
    }
    printq(&Q);
    //qustion 7
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 2nd element from the bottom of the queue\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(Q.TotalinQueue >= 2){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);
    
    printq(&Q);

    //question 8
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 2nd element from the bottom of the queue, leaveing queue unchange\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(Q.TotalinQueue >= 2){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);

    while(!isEmpty(&Q)){
        addq(&RQ, deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, deleteq(&RQ));
    }
    printq(&Q);

    //qustion 9
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 3th element from the bottom of the queue\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(Q.TotalinQueue >= 3){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);
    
    printq(&Q);

    //question 10
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 3th element from the bottom of the queue, leaveing queue unchange\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(Q.TotalinQueue >= 3){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);

    while(!isEmpty(&Q)){
        addq(&RQ, deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, deleteq(&RQ));
    }
    printq(&Q);

    //qustion 11
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 4th element from the bottom of the queue\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(Q.TotalinQueue >= 4){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);
    
    printq(&Q);

    //question 12
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    Q.TotalinQueue = RQ.TotalinQueue = 0;
    printf("assign integer m the 4th element from the bottom of the queue, leaveing queue unchange\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(Q.TotalinQueue >= 4){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("%d\n", k);

    while(!isEmpty(&Q)){
        addq(&RQ, deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, deleteq(&RQ));
    }
    printq(&Q);
    return 0;
}