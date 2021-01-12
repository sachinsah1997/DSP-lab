#include <stdio.h>
#include <stdbool.h>

//total no. of vertics
#define v 5

//graph adjacent matrix
int graph[v][v];

int traverse_list[v];

//tract if vertex is visited
bool visited[v];

// to tract which to be visited next
int queue[v];
int rear = -1;
int front = -1;

// function to add item into queue
void enqueue(int item) { 
   queue[++rear] = item; 
} 

// function to delete item from the queue
int dequeue() { 
   return queue[front++]; 
} 

void traverse(){

    //counter to count no of vertices visited
    int count;
    // count less than no of vertices.
    while(count<v){

        // print current queue
        printf("Queue status : ");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    
        //select the rear element to traverse
        int vertex = dequeue();    
        
        for(int i=0; i<v; i++){
        
        //check if the vertex has any adjacent vertices which is not visited.
        //if there then add into the queue.
        if(graph[vertex][i] == 1 && visited[i] == false){
            enqueue(i);
        }
      }
      
      //if vertex itself is not visited then set to visited and add in the traverse list.
      if(visited[vertex] == false){
            visited[vertex] = true;
            printf("vertex visited : %d \n", vertex);
            traverse_list[count] = vertex;
            count++;
      }
    }
}

void main(){

	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){

			/*set intial value to zero as there is no connection
			 so that further we can come to know that there is connection
			  by setting it 1. */
			graph[i][j] = 0;
		}
	}

	// enter no of egdes in the graph
	int n;
	printf("enter no of connected egdes : ");
	scanf("%d",&n);

    int count=1;
    printf("connection : \n");
    for(int i=0; i<n; i++){
            int from,to;
            printf("%d ---> ",count);
            scanf(" %d %d", &from, &to);
            
            //set 1 in matrix to know its connected
            // for undirected graph 1->2 edge connection then obivously 2->1 connected 
            graph[from][to] = 1;
            // for directed graph we have to remove this.
            graph[to][from] = 1;
            // counter to count no of connection
            count++;
    }
    
    //initially we will start from 0 node so we add it to stack.
    queue[++rear] = 0;
    front=rear;
    
    // function implementing bfs approach
    traverse();
    
    //to print traversed list
    printf("Traverse List : ");
    for(int i = 0; i<v; i++){
        printf("%d ", traverse_list[i]);
    }
}