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
}queue;

queue Q, RQ;

int isEmpty(queue *pq) {
    return (pq->front == pq->rear && pq -> lastOperationIsDeleteq);
};

bool isFull(queue *pq) {
    return(pq->front == pq->rear && !pq->lastOperationIsDeleteq);
};

void addq(queue *pq, int data){
    if(isFull(pq)){
        printf("Queue is full.\n");
        exit(1);
    }
    pq->lastOperationIsDeleteq = 0;
    pq->rear = (pq->rear + 1) % SIZE;
    pq->A[pq->rear] = data;
};

int deleteq(queue *pq) {
    if(isEmpty(pq)){
        printf("Queue is empty.\n");
        exit(2); 
    }
    pq->lastOperationIsDeleteq = 1;
    pq->front = (pq->front + 1) % SIZE;
    return pq->A[pq->front];
}

void printq(queue *pq) {
    int w;
    for(w = pq->front+1; w < pq->rear+1; w++){
        printf("%2d ", pq->A[w]);
        if((w - pq->front)% 9 == 0  || w == pq->rear){
            printf("\n");
        }
    }
}
//-------------------------------------------------------------------
//question 3.1
//
//(a)
//[ | | | | |(front)| | |(rear)]
/*
int isEmpty(queue *pq) {
    return ((pq->front+3 % size) == pq->rear && pq -> lastOperationIsDeleteq);
};
//[ 0(frront)|1|2|3(rear)|4|5|6|7|8]
bool isFull(queue *pq) {
    return((pq->front+3 % size) == pq->rear && !pq->lastOperationIsDeleteq);
};
*/

//(b)
//[ | |(front)| (rear)| | ]
/*
int isEmpty(queue *pq) {
    return ((pq->front+5 % size) == pq->rear && pq -> lastOperationIsDeleteq);
};
//[0|1|2|3|4(front)|5|6|7|8(rear)]
bool isFull(queue *pq) {
    return((pq->front+5 % size) == pq->rear && !pq->lastOperationIsDeleteq);
};
*/
int main(void){
    srand(time(NULL));
    int k, i, m;
    
    //411440430 bo-chain
    // question 1
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    RQ.lastOperationIsDeleteq = 0;
    for(i=0;i<18;i++){
        k = rand()%100+1;
        addq(&Q, k);
       printf(" %d", k);
       if((i+1)%9 == 0){
        printf("\n");
       }
    }
    printq(&Q);
    
    for (i=0;i<10;i++){
        if(isEmpty(&Q)){
            printf("1-element queue");
            exit(3);
        }
        addq(&RQ, k = deleteq(&Q));
    }
    printf("question 3.2 (b) n = %d\n", k);
    while(!isEmpty(&Q)){
         addq(&RQ, deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
         addq(&Q, deleteq(&RQ));
    }
    printq(&Q);
    
    return 0;
}
