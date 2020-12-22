#include <stdio.h>
#include <stdlib.h>

#define N 100     
// A and B will act as two stack. A will use for dequeue operation and B will used
int A[N], B[N];
// This variable will keep track of top element of A and B stack.
int top1 = -1, top2 = -1;
int count = 0;
   
    // This method is used to push the element in the A stack.
    void push1(int value){

    	if(top1 == N-1){
    		printf("Queue is overflow\n");
    	}else{
    		top1++;
    		A[top1] = value;	
    	} 
    }

    // This method is used to push the element in the B stack.
    void push2(int value){
     	
     	if(top2 == N-1){
    		printf("Queue is overflow\n");
    	}else{
    		top2++;
    		B[top2] = value;	
    	} 
    }

    // this method is used to pop the element from the A stack.
    int pop1(){
        return(A[top1--]);
    }

    // this method is used to pop the element from the B stack.
    int pop2(){
        return(B[top2--]);
    }  

    // This method is used to add an element into the queue using A stack
    void enqueue(int value){

    	// this method will add element into A stack.
        push1(value);
        //this will keep count of how many elements are inserted in A stack.
        count++;
    }

     

    /*Function to delete an element from the queue using stack*/
    void dequeue(){

       if(top1 == -1 && top2 == -1){
       		printf("Queue is empty\n");
       }
       else{
       	//this will copy all element of A stack to B stack in order to perform dequeue operation.
       		for (int i=0;i<count; i++){
            //pop elements from stack A.
            int temp = pop1();
            //push the elements popped from Stack A.
            push2(temp);	
    		}
       }
       //this will remove top element of Stack B.
       int pop = pop2();
       printf("Dequeue operation performed : %d\n", pop);
      // As element decreases after pop opeartion
       count--;

      	// now again element are copying from stack B to stack A after performing dequeue operation.
       for(int i=0; i<count; i++){
       		int temp = pop2();
       		push1(temp);
       }
    }

    /*Function to display the elements in the stack*/
    void display(){

    	printf("Queue elements : ");
        int i;
        for (i = 0;i < count;i++){
            printf(" %d ", A[i]);
        }
        printf("\n");
    }
     

    int main(){
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