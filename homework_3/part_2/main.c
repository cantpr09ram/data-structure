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
        printf("%2d ", pq->A[w]);
        if((w+1)% 10 == 0 ){
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
        addq(&RQ, m = deleteq(&Q));
    }
    printf("%d\n", m);
    printq(&Q);
    //question 2
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
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
        addq(&RQ, m = deleteq(&Q));
    }
    printf("%d\n", m);
    
    printq(&Q);
    //question 3
    //411440430 bo-chain
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    printf("assign integer m the 1st element from the bottom of the queue\n");
    for(i=0;i<30;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    while(!isEmpty(&Q)){
        addq(&RQ, m = deleteq(&Q));
    }
    printf("%d\n", m);
    
    printq(&Q);
    //question 4
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    printf("assign integer m the 2nd element from the bottom of the queue\n");
    for(i=0;i<30 ;i++){
        k = rand()%100;
        addq(&Q, k);
        //printf("%d, %d\n", Q.front, Q.rear);
    }
    printq(&Q);
    
    for (i=0;i<30 - 2 + 1; i++){
        if(isEmpty(&Q)){
            printf("1-element queue");
            exit(3);
        }
        addq(&RQ, m = deleteq(&Q));
    }
    printf("%d\n", m);
    
    printq(&Q);
    return 0;
    //printf("assign integer m the 4th element from the bottom of the stack, leaveing stack unchange");
}

