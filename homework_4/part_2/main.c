#include <stdio.h>
#include <stdlib.h>
//411440430 \u8b19
typedef struct listNode *listPointer;
struct listNode {
    int data;
    listPointer link;
};

struct queue {
    listPointer front, rear;
} Q, Q1;

listPointer front = NULL, rear = NULL;

int emptys(struct queue *pq){
    return (pq->front == NULL); 
}

void addq(struct queue *pq, int x){
    listPointer p = (listPointer)malloc(sizeof(struct listNode));
    p->data = x;
    p->link = NULL;
    if(emptys(pq)){
        pq->front = p;
    } else {
        pq->rear->link = p;
    }
	pq->rear = p;
}

int deleteq(struct queue *pq){
    if(emptys(pq)){
        printf("the queue is empty");
        exit(2);
    }
    listPointer p = pq->front;
    int x = p->data; 
    pq->front = p->link; // one-node queue => front = NULL(no need to change rear)
    free(p);
    return x;
}

void prints(struct queue *pq){
    int counter = 0;
    listPointer temp = pq->front;
    while (!(temp == NULL)) {
        counter++;
        printf("%2d ",temp->data);
        if((counter) % 10 == 0){
            printf("\n");
        }
        temp = temp->link;
    }
    
}

int main(void) {
    struct queue Q, Q1;
    int i, m, k;
	//411440430 \u8b19
    //question 1
    printf("assign integer m 2nd element from the bottom of the queue\n");
    Q.front = Q1.front = Q.rear = Q1.rear = NULL; // Initialize two queue
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&Q, k);
    }

    prints(&Q);
    int arr[10] = {0};
    int j;

    while(!emptys(&Q)){
        addq(&Q1, m = deleteq(&Q));
        for(j=0; j<1; j++){
            arr[1-j] = arr[1-j-1];
        }
        arr[0] = m;
    }
    printf("%d \n", arr[1]);

    prints(&Q);
    //question 2
    printf("assign integer m 2nd element from the bottom of the queue, leaveing queue unchange\n");
    Q.front = Q1.front = Q.rear = Q1.rear = NULL; // Initialize two queue
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&Q, k);
    }

    prints(&Q);

    while(!emptys(&Q)){
        addq(&Q1, m = deleteq(&Q));
        for(j=0; j<1; j++){
            arr[1-j] = arr[1-j-1];
        }
        arr[0] = m;
    }
    printf("%d \n", arr[1]);

    while(!emptys(&Q1)){
        addq(&Q, deleteq(&Q1));
    }
    prints(&Q);
    //question 3
    printf("assign integer m 3th element from the bottom of the queue\n");
    Q.front = Q1.front = Q.rear = Q1.rear = NULL; // Initialize two queue
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&Q, k);
    }

    prints(&Q);
   
    while(!emptys(&Q)){
        addq(&Q1, m = deleteq(&Q));
        for(j=0; j<2; j++){
            arr[2-j] = arr[2-j-1];
        }
        arr[0] = m;
    }
    printf("%d \n", arr[2]);

    //question 4
    printf("assign integer m 3th element from the bottom of the queue, leaveing queue unchange\n");
    Q.front = Q1.front = Q.rear = Q1.rear = NULL; // Initialize two queue
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&Q, k);
    }

    prints(&Q);
    

    while(!emptys(&Q)){
        addq(&Q1, m = deleteq(&Q));
        for(j=0; j<2; j++){
            arr[2-j] = arr[2-j-1];
        }
        arr[0] = m;
    }
    printf("%d \n", arr[2]);

    while(!emptys(&Q1)){
        addq(&Q, deleteq(&Q1));
    }
    prints(&Q);
    //question 5
    printf("assign integer m 4th element from the bottom of the queue, leaveing queue unchange\n");
    Q.front = Q1.front = Q.rear = Q1.rear = NULL; // Initialize two queue
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&Q, k);
    }

    prints(&Q);

    while(!emptys(&Q)){
        addq(&Q1, m = deleteq(&Q));
        for(j=0; j<3; j++){
            arr[3-j] = arr[3-j-1];
        }
        arr[0] = m;
    }
    printf("%d \n", arr[3]);

    prints(&Q);
    //question 6
    printf("assign integer m 4th element from the bottom of the queue, leaveing queue unchange\n");
    Q.front = Q1.front = Q.rear = Q1.rear = NULL; // Initialize two queue
    for(i=0;i<50;i++){
        k = rand()%100;
        addq(&Q, k);
    }

    prints(&Q);
    

    while(!emptys(&Q)){
        addq(&Q1, m = deleteq(&Q));
        for(j=0; j<3; j++){
            arr[3-j] = arr[3-j-1];
        }
        arr[0] = m;
    }
    printf("%d \n", arr[3]);

    while(!emptys(&Q1)){
        addq(&Q, deleteq(&Q1));
    }
    prints(&Q);
    return 0;
}
