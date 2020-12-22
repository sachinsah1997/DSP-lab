#include<stdio.h>
#define N 10

// this A and B will act as two queue A nd B.
int A[N], B[N];

//this variable will keep tract of pointer of both queue.
int front1=-1,rear1=-1,front2=-1,rear2=-1;
int count=-1;

//this method will display elements of stack
void display(){
    if(front1==-1&&rear1==-1)
        printf("\nStack is empty.");
    else
        {
        printf("Stack element : ");
        //i have printed it from front to rear because queue traverse from front to rear. 
        //stack element will be inverse of it.
        for(int i=front1;i<=count;i++){
            printf("%d ",A[i]);
            }
        }
        printf("\n");
    }

// this method will add element in queue A acts as push element of stack.
void enqueue1(int value){
    if(rear1 > N-1){
        printf("\nQueue is overflow");
        return;
    }
    if(front1 ==-1){
        front1++;
    }
    rear1++;
    count++;
    A[rear1]=value;
}

// this method will add element in queue B acts as push element of stack.
void enqueue2(int value){
    if(rear2 > N-1){
        printf("\nQueue is overflow");
        return;
    }
    if(front2 ==-1){
        front2++;
    }
    rear2++;
    B[rear2]=value;
}

// this method will remove element in queue A acts as pop element of stack.
int dequeue(){
   
   // here we have moved rear-1 element to queue B so that we will escape the last element.
    // so it acts as pop operation of stack.
    while(front1==rear1){
        int temp = A[front1];
        enqueue2(temp);
        front1++;        
    }

    int top_element = A[count];
    //rear1++;
   // front1 = rear1 ;
    count--;
    
    // here we are copying the element of B queue to A queue which we have done to eliminate top element.
    while(front2 < rear2){
        int temp = B[front2];
        enqueue1(temp);
        front2++;        
    }

    return(top_element);
}

//this method will do pop operation.
void pop(){
    int popped = dequeue();
    printf("Popped operation performed : %d\n", popped);
}

//this method will do push operation.
void push(int value){
    enqueue1(value);
}

int main()
{
        push(100);
        push(101);
        push(102);
        push(103);
        push(104);
        display();
        pop();
        pop();
        display();
        return 0;
}