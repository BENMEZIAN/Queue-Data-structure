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
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(queue* q) {
    
	if (isEmpty(q)) {
        printf("This Queue is empty\n");
        return -1;
    }

    Node* temp = q->front;
    int data = temp->data;

    q->front = q->front->next;
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

    printf("Queue: ");
    Node* curr = q->front;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
