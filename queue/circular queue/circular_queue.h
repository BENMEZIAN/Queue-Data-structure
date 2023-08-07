#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct queue {
    Node* front;
    Node* rear;
}queue;

void init(queue* q){
	q->front = NULL;
    q->rear = NULL;
}

int isEmpty(queue* q){
	
    if(q->front == NULL && q->rear == NULL){
    	return 1;
	}else{
		return 0;
	}
}

void enqueue(queue* q, int val) {
    
	Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    
    q->rear->next = q->front;
}

int dequeue(queue* q) {
    
	if (isEmpty(q)) {
        printf("This Queue is empty\n");
        return -1;
    }

    Node* temp = q->front;
    int data = temp->data;

    q->front = q->front->next;
    q->rear->next = q->front;
    free(temp);

    // If the queue becomes empty after dequeue
    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

void printQueue(queue* q) {
    
	if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    Node* temp = q->front;

    printf("Circular queue: ");
    do{
	    printf ("%d->", temp->data);
	    temp = temp->next;
	}while (temp != q->front);
	
    printf("\n");
}
