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