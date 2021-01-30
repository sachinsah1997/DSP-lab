#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct Graph {
  int numVertices;
  struct node** adjLists;
};

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
 
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));

  for (int i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) {
  
  //undirected graph is given
  // Add edge from s to d
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;

  // Add edge from d to s
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {

  printf("\nAdjacent List :\n");
  for (int v = 0; v < graph->numVertices; v++) {
    
    struct node* temp = graph->adjLists[v];
    
    printf("Vertex %d", v+1);  
    while (temp) {
      printf(" -> %d", temp->vertex+1);
      temp = temp->next;
    }
    printf("\n");
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

    int V,E;
    fscanf(fp, "%d %d", &V, &E);
    printf("No of vertices : %d \nNo of edges : %d\n",V, E);

    struct Graph* graph = createGraph(V);
   
    int count=0;
    while (count<E){
        int srcV, destV;
        fscanf(fp, "%d %d", &srcV, &destV);
        addEdge(graph, srcV-1, destV-1);
        count++;
    }
    fclose(fp);
    printGraph(graph);
    
    return 0;
}