#include<stdio.h>
#include<stdlib.h>


// This is structure to hold the element and the pointer to the next element.
struct node{ 
    int value; 
    struct node* next; 
};

// this will show the top pointer and be use in future reference.
struct node *top=NULL;

// This method will add new element on the top of the stack.
void push(int value){
    struct node* element = (struct node*)malloc(sizeof(struct node)); 
    element -> value = value; 
    element -> next = top;  
    top = element; 
    printf("%d is pushed\n",top -> value);

}
// Remove element from the top of the stack
void pop(){
    if(top != NULL){
        printf("%d is popped\n",top -> value);
        struct node* temp = top;
        top = top -> next;
        temp= NULL;
    }
    else{
        printf("The stack is empty.\n");
    }
}

// This will show all the elements of the stack.
void display(){
    
    struct node *temp;
    temp = top;

    if(top == NULL){
        printf("Stack is empty\n");
    }else{
        printf("Stack : ");
        while(temp != NULL){
            printf("%d ", temp-> value);
            temp = temp -> next;
        }
        printf("\n");
    }
}

int main(){    
    
    //initially stack
    display();

    push(100);
    push(101);
    push(102);
    push(103);

    display();
    
    pop();
    pop();
    
    display();

    return 0;
}