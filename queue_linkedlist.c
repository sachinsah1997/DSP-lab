#include <stdio.h> 
#include <stdlib.h> 

// This is structure to hold the element and the pointer to the next element.
struct node { 
	int value; 
	struct node* next; 
}; 

// this will show the front pointer and be use in future reference.
struct node *front = NULL;
// this will show the last pointer and be use in future reference.
struct node *rear = NULL;

// This method will perform enqueue operation in queue
void enqueue(int value) 
{ 
	struct node* element = (struct node*)malloc(sizeof(struct node));
	element -> value = value;
	element -> next = NULL; 
	
	printf("%d inserted\n",value);
	// if queue is empty, then new node is set to front and rear both 
	if (front == NULL && rear == NULL){ 
		front = rear = element; 
		return; 
	}else{
		rear -> next = element;
		rear = element;
	} 
} 

// This method will perform dequeue operation in queue
void dequeue(){

	struct node *temp;
	temp = front;
 
	if (front == NULL && rear == NULL){
		printf("queue is empty \n");
	}else{
		front = front-> next;
	}
	printf("%d deleted\n",temp -> value);  
	temp = NULL; 
} 

// This will show all the elements of the queue.
void display(){
    
    struct node *temp;
    temp = front;

    if(front == NULL){
        printf("queue is empty\n");
    }else{
        printf("queue : ");
        while(temp != NULL){
            printf("%d ", temp-> value);
            temp = temp -> next;
        }
        printf("\n");
    }
}

int main(){

	display();

	enqueue(100); 
	enqueue(101); 
	enqueue(102); 
	enqueue(103); 
	enqueue(104);

	display(); 
	
	dequeue();
	dequeue();

	display(); 
	
	return 0; 
} 
