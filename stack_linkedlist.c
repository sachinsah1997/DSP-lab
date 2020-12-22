#include<stdio.h>
#include<stdlib.h>


// This is structure to hold the element and the pointer to the next element.
struct node{ 
    char value; 
    struct node* next; 
};

// this will show the top pointer and be use in future reference.
struct node *top=0;

// This method will add new element on the top of the stack.
void insert(char value){
    struct node* element = (struct node*)malloc(sizeof(struct node)); 
    element -> value = value; 
    element -> next = top;  
    top = element; 
    printf("Insert operation performed: %d\n",top -> value);

}
// Remove element from the top of the stack
void delete(){
    if(top != NULL){
        printf("Popped operation performed: %d\n",top -> value);
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

    if(top == 0){
        printf("Stack is empty\n");
    }else{
        printf("stack : ");
        while(temp != 0){
            printf("%d ", temp-> value);
            temp = temp -> next;
        }
        printf("\n");
    }
}

int main(){    
    insert(100);
    insert(101);
    insert(102);
    insert(103);
    display();
    delete();
    delete();
    display();
    return 0;
}