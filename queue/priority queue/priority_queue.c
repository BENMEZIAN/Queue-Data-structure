#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"


int getch();

int main() {
	
	PriorityQueue pq;
    int choice,n,p;
    
    while(1){
    	system("cls");
    	printf("-----------Priortiy queue operations-------------\n");
    	printf("1.Init queue\n");
        printf("2.Enqueue\n");
        printf("3.Dequeue\n");
        printf("4.Empty or not\n");
        printf("5.Print queue\n");
		printf("6.Exit\n");
    	printf("----------------------------------------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: init(&pq);
            break;
                        
			case 2: printf("enter an element to enqueue:");
					scanf("%d",&n);
					printf("enter its priority:");
					scanf("%d",&p);
					enqueue(&pq,n,p);
            break;
                
            case 3: dequeue(&pq);
            break;
                
            case 4: if(isEmpty(&pq) == 1){
                		printf("queue is empty\n");
					}else{
						printf("queue is not empty\n");
					}
            break;
                
            case 5: printQueue(&pq);
            break;
                
			case 6: exit(0);
            break;
						   
            default: printf("Wrong Choice\n");
            break;
        }
		
		getch();
	}
    
    
    return 0;
}

