#include <stdio.h>

#define V 6
#define INF 999

void printShortestPathMatrix(int matrix[V][V]);

void floydWarshallStep(int matrix[V][V]) {

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
    printf("Iteration %d\n", k+1);
    printShortestPathMatrix(matrix);
    printf("\n");
  }
}

void printShortestPathMatrix(int matrix[V][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {

  int matrix[V][V] = {{0, 5, 6, INF, INF, INF},
                     {5, 0, 8, 3, 4, INF},
                     {6, 8, 0, INF, 6, INF},
                     {INF, 3, INF, 0, 3, 7},
                     {INF, 4, 6, 3, 0, 7},
                     {INF, INF, INF, 7, 7, 0}};
  floydWarshallStep(matrix);

  printf("Sortest path matrix :\n");
  printShortestPathMatrix(matrix);
}