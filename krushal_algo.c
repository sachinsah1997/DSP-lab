#include <stdio.h>

int parent[9];

int find_parent (int vertex){
  while (parent[vertex])
    vertex = parent[vertex];
  return vertex;
}

int compare_parent (int vertexp1, int vertexp2){
  if (vertexp1 != vertexp2){
      parent[vertexp2] = vertexp1;
      return 1;
    }
  return 0;
}

void main (){

  int n_edeges,n_vertices, cost[9][9];
  int i, j;
  
  printf ("Enter the no. of vertices : ");
  scanf ("%d", &n_vertices);
  printf ("Enter the no of edges : ");
  scanf ("%d", &n_edeges);

  //setting initial values to infinity
  for (i = 1; i <= n_vertices; i++){
      for (j = 1; j <= n_vertices; j++){
    cost[i][j] = 999;
  }
  }

  printf ("Enter Vertices and its values in order V1 V2 cost : \n");
  int count_egde = 1, v1, v2, weight; 
  while (count_egde <= n_edeges){
      scanf ("%d %d %d", &v1, &v2, &weight);
      cost[v1][v2] = cost[v2][v1] = weight;
      count_egde++;
    }
    
    
  printf ("The edges of Minimum Cost Spanning Tree are : \n");
  count_egde = 1;
  int temp1, temp2, min, mincost = 0;
  while (count_egde < n_vertices){
      for (i = 1, min = 999; i <= n_vertices; i++){
      for (j = 1; j <= n_vertices; j++){
        if (cost[i][j] < min){
        min = cost[i][j];
        v1 = temp1 = i;
        v2 = temp2 = j;
      }
      }
    }
    
      temp1 = find_parent (temp1);
      temp2 = find_parent (temp2);
      
      if (compare_parent (temp1, temp2)){
       printf ("%d edge (%d,%d) =%d\n", count_egde++, v1, v2, min);
       mincost += min;
      }
      cost[v1][v2] = cost[v2][v1] = 999;
    }
    
    printf ("\n\tMinimum Spanning Tree cost = %d\n", mincost);
}