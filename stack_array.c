#include <stdio.h>

// We have create empty array with size 10 consider it an empty stack with size 10.
int A[10];

// this variable will keep track of top element index.
int top=-1;

// size of the array.
int size_A = sizeof(A)/sizeof(A[0]);

// this method will check if stack is empty or not.
int isStackEmpty(){
	if(top==-1)
		return 1;
	else
		return 0;
}

// this method will perform push operation on stack.
void push(int value){
	if(isStackEmpty())
		top = 0;
	else if( top == size_A )
		printf("\n Stack is Full \n");
	else
		top++;
	
	printf("%d is pushed \n", value);
	A[top] = value;
}

// this method will display all the element in the stack.
void display(){

	if(isStackEmpty()){
        printf("Stack is empty\n");
    }else{
	printf("Stack :");
	for(int i=top;i>=0;i--){
		printf(" %d",A[i]);
	}
	printf("\n");
  }
}

// this methos will perform pop operation on stack.
int pop(){
	if(isStackEmpty())
		printf("\n Stack is Empty \n");
	else
		printf("%d is popped \n", A[top]);
		top--;
	
	return A[top-1];
}

int main(){
	
	//initially stack
	display();

	push(0);
	push(1);
	push(2);
	push(3);

	display();

	pop(); 			
	pop(); 		
	
	display();	

return 0;
}