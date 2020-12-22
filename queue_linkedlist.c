#include <stdio.h> 
#include <stdlib.h> 

// This is structure to hold the element and the pointer to the next element.
struct node { 
	int value; 
	struct node* next; 
}; 

// this will show the front pointer and be use in future reference.
struct node *front = 0;
// this will show the last pointer and be use in future reference.
struct node *rear = 0;

// This method will perform enqueue operation in queue
void insert(int value) 
{ 
	struct node* element = (struct node*)malloc(sizeof(struct node));
	element -> value = value;
	element -> next = 0; 
	
	printf("enqueue operation performed : %d\n",value);
	// if queue is empty, then new node is set to front and rear both 
	if (front == 0 && rear == 0){ 
		front = rear = element; 
		return; 
	}else{
		rear -> next = element;
		rear = element;
	} 
} 

// This method will perform dequeue operation in queue
void delete() 
{ 
	struct node *temp;
	temp = front;
 
	if (front == 0 && rear == 0){
		printf("queue is empty \n");
	}else{
		front = front-> next;
	}
	printf("Dequeue operation performed : %d\n",temp -> value);  
	temp = NULL; 
} 

// This will show all the elements of the queue.
void display(){
    
    struct node *temp;
    temp = front;

    if(front == 0){
        printf("queue is empty\n");
    }else{
        printf("queue : ");
        while(temp != rear){
            printf("%d ", temp-> value);
            temp = temp -> next;
        }
        printf("\n");
    }
}
void main() 
{ 
	insert(100); 
	insert(101); 
	insert(102); 
	insert(103); 
	insert(104);
	display(); 
	delete();
	delete();
	display(); 
	 
} 
