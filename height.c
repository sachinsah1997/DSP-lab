#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

int maxDepth(struct node* node){
    
   if (node==NULL)  
       return 0; 
   else { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}  

// Driver code
int main() {
  
  int n;  
  printf("Enter the no. of node : ");
  scanf("%d", &n);
  
  struct node *root = NULL;
  for(int i=0; i<n; i++){
      int temp;
      scanf("%d",&temp);
      root = insert(root, temp);
  }
  
  int depth = maxDepth(root);
  printf("%d", depth);
}