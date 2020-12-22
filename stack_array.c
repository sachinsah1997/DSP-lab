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
void insert(int value){
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

	printf("Stack elements :");
	for(int i=0;i<=top;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
}

// this methos will perform pop operation on stack.
int delete(){
	if(isStackEmpty())
		printf("\n Stack is Empty \n");
	else
		printf("%d is popped \n", A[top]);
		top--;
	
	return A[top-1];
}

int main()
{
	insert(0);
	insert(1);
	insert(2);
	insert(3);

	display();

	delete(); 			
	delete(); 		
	
	display();	

return 0;
}