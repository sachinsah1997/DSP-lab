#include <stdio.h>
#define MAX 50

    // we have taken array of size 50 consider it as queue with size 50.
    int A[MAX];
    // rear variable is used to trace last pointer till where queue is filled.
    int rear = - 1;
    // front variable is used to trace front pointer.
    int front = - 1;

    // this method will do Enqueue operation in the queue.
    void enqueue(int value){

        if(rear == MAX-1){
            printf("Queue is in Overflow \n");
        }
        else if(front == -1 && rear == -1){
    
                front = rear = 0;
                printf("%d inserted\n",value );
                A[rear] = value;
        }else{
               printf("%d inserted\n",value );
               rear++;
               A[rear] = value;
        }
    }

    // this method will do dequeue operation in the queue.
    void dequeue(){

        if(front == -1 || rear == -1){
            printf("Queue is in Underflow \n");
            return ;
        }
        else if(front==rear){
            printf("%d deleted\n", A[front]);
            front = rear = -1;
        }else{
            printf("%d deleted\n", A[front]);
            front++;
        }
    }

    // this method will retrieve all the elements in the queue from first to last.
    void display(){

        int i;
        if(front == -1){
            printf("Queue is empty \n");
        }
        else{
            printf("Queue is : ");
            // this will traverse from first to last in FIFO manner.
            for (i = front; i <= rear; i++){
                printf("%d ", A[i]);
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