#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"


int getch();

int main() {
	
	queue q;
    int choice,n;
    
    while(1){
    	system("cls");
    	printf("-----------Circular queue operations-------------\n");
    	printf("1.Init circular queue\n");
        printf("2.Enqueue\n");
        printf("3.Dequeue\n");
        printf("4.Empty or not\n");
        printf("5.Print queue\n");
		printf("6.Exit\n");
    	printf("----------------------------------------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: init(&q);
                    break;
                        
			case 2: printf("enter an element to enqueue:");
					scanf("%d",&n);
					enqueue(&q,n);
                    break;
                
            case 3: printf("The dequeued element is: %d\n",dequeue(&q));
                    break;
                
            case 4: if(isEmpty(&q) == 1){
                		printf("queue is empty\n");
					}else{
						printf("queue is not empty\n");
					}
                    break;
                
            case 5: printQueue(&q);
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

