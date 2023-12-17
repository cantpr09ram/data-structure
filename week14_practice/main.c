#include <stdio.h>
#include <stdlib.h>


typedef struct listNode *listPointer;
struct listNode {
    int data;
    listPointer link;
};

void insertnum(listPointer *p,int x){
    listPointer temp,r,q;
    temp = (listPointer)malloc(sizeof(struct listNode));
    temp->data=x;
    q=*p;
             
    temp->link=q;
    r->link=temp;	
}

int delete(listPointer *p){
    listPointer temp = NULL;
    int x;
    x=(*p)->data;
    temp=*p;
    if(temp->link!=(*p) && temp->link != NULL)
        *p=temp->link;
	free(temp);
    return x;
}

void insertnum(listPointer *p,int x){
    listPointer temp,r,q;
    temp = (listPointer)malloc(sizeof(struct listNode));
    temp->data=x;
    q=*p;

    while(q!=NULL && x>q->data) {
    	r=q;
    	q=q->link;
    }
    if(q==*p){            
    	temp->link=q;
    	*p=temp;
    }
    else{                
    	temp->link=q;
    	r->link=temp;	
    }    
}

listPointer concatenate(listPointer list1, listPointer list2){
    listPointer temp;
    if(!list1)
        return list2;
    if(!list2)
        return list1;
        
    temp=list1;
    while(temp->link!=NULL){
    	temp=temp->link;
    }
    temp->link=list2;
    return list1;
}

listPointer invert(listPointer p){
    listPointer  middle, trail;
    middle = NULL;
    while (p) {
    	trail = middle;
    	middle = p;
    	p = p->link;
    	middle->link = trail;
    }
    return middle;
}

listPointer Lin2Cir(listPointer p){
    listPointer temp;
    temp=p;
    while(temp->link!=NULL){
    	temp=temp->link;
    }
    temp->link=p;
    return temp;
}

void print(listPointer p){
	int cnt = 0;
    listPointer temp=p;
    while(temp!=NULL){
        printf("%d,",temp->data);
        cnt++;
        temp=temp->link;
        if(cnt % 10 == 0) printf("\n");
    }    
}
