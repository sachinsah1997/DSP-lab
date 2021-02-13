#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct Graph {
  int numVertices;
  int *visited;
  struct node** array;
};

struct node* createNode(int vertex) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createGraph(int numVertices) {
 
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;
  graph->visited = calloc(numVertices , sizeof(int));
  graph->array = calloc(numVertices , sizeof(struct node*));

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) {
  
  //undirected graph is ginumVerticesen
  // Add edge from s to d
  struct node* newNode = createNode(d);
  newNode->next = graph->array[s];
  graph->array[s] = newNode;

  // Add edge from d to s
  newNode = createNode(s);
  newNode->next = graph->array[d];
  graph->array[d] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {

  printf("\nAdjacent List :\n");
  for (int vertex = 0; vertex < graph->numVertices; vertex++) {
    
    struct node* temp = graph->array[vertex];
    
    printf("Vertex %d", vertex+1);  
    while (temp) {
      printf(" -> %d", temp->vertex+1);
      temp = temp->next;
    }
    printf("\n");
  }
}

// Function for DFS search.
void dfs(struct Graph* graph,int vertex){
    // Set the vertex v visited.
    graph->visited[vertex] = 1;

    // Check for all adjacent vertices of vertex v.
    struct node *array_head = graph->array[vertex];
    while (NULL != array_head)
    {
        // If unvisited adjacent vertex found call dfs recursively
        if (graph->visited[array_head->vertex] == 0)
            dfs(graph ,array_head->vertex);
        array_head = array_head->next;
    }
}


int main() {

    FILE *fp;
    char* filename = "/home/sachinsah/Documents/UOH Study/DSP LAB/21012021/inputfile.txt";
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    int numVertices,numEdges;
    fscanf(fp, "%d %d", &numVertices, &numEdges);
    printf("No of vertices : %d \nNo of edges : %d\n",numVertices, numEdges);

    struct Graph* graph = createGraph(numVertices);
   
    while (numEdges>0){
        int srcVertex, destVertex;        
        fscanf(fp, "%d %d", &srcVertex, &destVertex);
        addEdge(graph, srcVertex-1, destVertex-1);
        numEdges--;
    }

    fclose(fp);
    printGraph(graph);

    int component_count = 0;
    for (int vertex = 1; vertex < graph->numVertices; vertex++)
    {
        if (graph->visited[vertex] == 0)
        {
            dfs(graph,vertex);
            component_count++;
        }
    }

    free(graph);
    printf("\nNo of Connected Components : %d\n", component_count);
    
    return 0;
}