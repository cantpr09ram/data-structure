#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

typedef struct listNode *listPointer;
struct listNode {
    int data;
    listPointer link;
};
//411440430 \u8b19
// Function to insert a node at the beginning of the list
void insert(listPointer *ptr, int x) {
    listPointer newNode = (listPointer)malloc(sizeof(struct listNode));
    newNode->data = x;

    if (*ptr == NULL) {
        newNode->link = NULL;
        *ptr = newNode;
    } else {
        newNode->link = *ptr;
        (*ptr) = newNode;
    }
}

// Function to insert a node in a sorted manner
void insertnum(listPointer *ptr, int x) {
    listPointer newNode = (listPointer)malloc(sizeof(struct listNode));
    newNode->data = x;

    if (*ptr == NULL || x <= (*ptr)->data) {
        newNode->link = *ptr;
        *ptr = newNode;
    } else {
        listPointer current = *ptr;
        while (current->link != NULL && x > current->link->data) {
            current = current->link;
        }

        newNode->link = current->link;
        current->link = newNode;
    }
}

// Function to delete the first node of the list and return its data
int delete(listPointer *ptr) {
    listPointer temp = (*ptr);
    if (!temp) {
        printf("Nothing to delete!\n");
        exit(1);
    } else {
        int data = temp->data;
        (*ptr) = temp->link;
        free(temp);
        return data;
    }
}
//411440430 \u8b19
int deleteC(listPointer *ptr) {
    listPointer temp = (*ptr);

    if (!temp) {
        printf("Nothing to delete!\n");
        exit(1);
    } else {
        int data = temp->data;
        listPointer nextNode = temp->link;

        if (nextNode == temp) {
            // Only one node in the circular list
            free(temp);
            (*ptr) = NULL;
        } else {
            // Find the node pointing to temp
            while (nextNode->link != temp) {
                nextNode = nextNode->link;
            }
            // Update the link to skip temp
            nextNode->link = temp->link;
            // Update the head if temp is the head of the circular list
            if ((*ptr) == temp) {
                (*ptr) = temp->link;
            }
            free(temp);
        }
        return data;
    }
}


// Function to concatenate two lists
listPointer concatenate(listPointer ptr1, listPointer ptr2) {
    if (!ptr1) return ptr2;

    listPointer temp = ptr1;
    while (temp->link != NULL) {
        temp = temp->link;
    }

    temp->link = ptr2;
    return ptr1;
}
//411440430 \u8b19
// Function to invert a list
listPointer invert(listPointer lead) {
    listPointer middle, trail;
    middle = NULL;
    while (lead != NULL) {
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    return middle;
}

// Function to convert a list to a circular linked list
listPointer Lin2Cir(listPointer p) {
    if (p == NULL) return NULL;

    listPointer temp = p;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = p;
    return p;
}

// Function to print the elements of a list
void printList(listPointer first) {
    listPointer temp = first;
    int count = 0;
	
	if(temp == NULL) return;
	
    while (temp != NULL) {
        printf("%2d ", temp->data);
        temp = temp->link;
        count++;

        if (count % 10 == 0) printf("\n");
    }
    printf("\n");
}
//411440430 \u8b19
void RandNPush(listPointer *ptr, int N_size) {
    while (N_size != 0) {
        int number = rand() % 100;
        insertnum(ptr, number);
        N_size--;
    }
}

void printC(listPointer p){
    int count =0;
    listPointer temp;
    temp=p->link;
    while(temp!=p){
        printf("%2d,",temp->data);
        temp=temp->link;
        count++;
        if(count%10 == 0){
            printf("\n");
        }
    }
    printf("%2d",temp->data);
    if(count%10 == 0){
        printf("\n");
    }
}

listPointer prevList = NULL;

listPointer deepCopy(listPointer original) {
    listPointer newHead = NULL;

    while (original != NULL) {
        insertnum(&newHead, original->data);
        original = original->link;
    }
    return newHead;
}


int main() {
	listPointer list = NULL;
	//411440430 \u8b19
    // (1) Insert 50 random numbers
	srand((unsigned)time(NULL));
    RandNPush(&list, 50);
    prevList = deepCopy(list);

    printf("(1) List after inserting 50 random numbers:\n");
    printList(list);
    
    // (2) Invert the list
    list = invert(list);
	printf("(2) List after inverting:\n"); 
	printList(list);
	list = invert(list);

	// (3) Delete odd numbers
	printf("(3) oddList:\n");
	listPointer oddList = NULL, evenList = NULL;
	listPointer temp = list;
	int deletedData;
	while(temp != NULL){
		deletedData = delete(&temp);
		if(deletedData % 2 == 1){
			insertnum(&oddList, deletedData);
		} else {
			insertnum(&evenList, deletedData);
		}
	}
	printList(oddList);
	
	printf("\n(3) evenList:\n");
	printList(evenList);
	//411440430 \u8b19
	// (4) Concatenate oddList to the front of the original list
	printf("\n(4) List after concatenating oddList to the front:\n");
	list = concatenate(oddList, evenList);
	printList(list);
	
	// (5) Convert the list to a circular linked list
	printf("\n(5) List after convering to a circular linked list\n");
	Lin2Cir(list);
	printC(list);
	printf("\n");
	// (6) Delete every sixth element in the circular list
	printf("\n(6) Deleted node with data every 6th element:\n");
    temp = prevList;
	Lin2Cir(temp);
	int i = 0, cnt = 0;
	while (temp != NULL) {
	    i++;
	    if (i % 6 == 0) {
	        printf("%2d ", temp->data);
	        deletedData = deleteC(&temp);
	        if (++cnt % 10 == 0) printf("\n");
	    } else {
	        temp = temp->link;
	    }
	}
   	
    return 0;
}
