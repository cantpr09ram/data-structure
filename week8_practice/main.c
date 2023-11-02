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

int main(){
    Q.front = Q.rear = RQ.front = RQ.rear = -1;
    srand(time(NULL));
    int k, i;
    for(i=0;i<15;i++){
        k = rand()%100;
        addq(&Q, k);
    }
    printf("generate random 15 number into Q queue and print them\n");
    for(i=0;i<15;i++){
        if(i == 14){
            printf("%14d <-rear\n",Q.A[i]);
        }else{
            printf("%14d \n",Q.A[i]);
        }
    }
    //assign integer k the 2nd element from the top of the struct Q, leaveing Q unchange
    for (i=0;i<2;i++){
        if(isEmpty(&Q)){
            printf("1-element queue");
            exit(3);
        }
        addq(&RQ, k = deleteq(&Q));
    }
    printf("\n");
    printf("QStion 1: k= %d\n", k);

    while(!isEmpty(&Q)){
        addq(&RQ, k=deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, k=deleteq(&RQ));
    }  
    //assign integer k the 9th element from the top of the struct Q, leaveing Q unchange
    for (i=0;i<9;i++){
        if(isEmpty(&Q)){
             printf("1-element queue");
             exit(4);
        }else{
            addq(&RQ, k = deleteq(&Q));
        }
    }
    printf("\n");
    printf("QStion 2: k= %d\n", k);

    while(!isEmpty(&Q)){
        addq(&RQ, k=deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, k=deleteq(&RQ));
    }   

    //assign integer k the bottom element from the top of the queue, leaveing Q unchange
    //411440430 bo-chain

    for(i=0;i<15;i++){
        addq(&RQ, k = deleteq(&Q));
    }
    printf("\n");
    printf("QStion 3: k= %d\n", k);

    while(!isEmpty(&Q)){
        addq(&RQ, k=deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, k=deleteq(&RQ));
    }
    //assign integer k the 2nd element from the bottom of the stack, leaveing S unchange
    int bottom;
    addq(&RQ, bottom = deleteq(&Q));
    while (isEmpty(&Q)){
        printf("1-element queue");
        exit(5);
    }
    while(!isEmpty(&Q)){
        k = bottom;
        addq(&RQ, bottom = deleteq(&Q));
    }
    printf("QStion 4: k= %d\n", k);

    while(!isEmpty(&Q)){
        addq(&RQ, k=deleteq(&Q));
    }
    while(!isEmpty(&RQ)){
        addq(&Q, k=deleteq(&RQ));
    }
    //print the stack from top to bottom, leaveing S unchange
    addq(&RQ, k = deleteq(&Q));
    printf("\n");
    printf("QStion 5:   %d <-front\n",k);
    while(!isEmpty(&Q)){
        
        addq(&RQ, k = deleteq(&Q));
        printf("          %4d\n",k);
    }

    while(!isEmpty(&RQ)){
        addq(&Q, k=deleteq(&RQ));
    }
}