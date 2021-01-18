#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

struct node {
  int key;
  struct node *left, *right;
};

// Stack type 
struct Stack 
{ 
    int size; 
    int top; 
    struct Node* *array; 
}; 

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Inorder Traversal
void preorder(struct node *root) {
  if (root != NULL) {

    // Traverse root
    printf("%d ", root->key);

    // Traverse left
    preorder(root->left);

    // Traverse right
    preorder(root->right);
  }
}

struct Stack* createStack(int size) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->size = size; 
    stack->top = -1; 
    stack->array = (struct Node**) malloc(stack->size * sizeof(struct Node*)); 
    return stack; 
} 
  
int isFull(struct Stack* stack) 
{  return stack->top - 1 == stack->size; } 
  
int isEmpty(struct Stack* stack) 
{  return stack->top == -1; } 
  
void push(struct Stack* stack, struct node* node) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = node; 
} 
  
struct node* pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top--]; 
} 

struct node* peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top]; 
} 
  
// An iterative function to do postorder traversal 
void postOrderIterative(struct node* root) { 
    
    if (root == NULL) 
        return; 
      
    struct Stack* stack = createStack(MAX_SIZE); 
    do{ 

        while (root) { 

            if (root->right) 
                push(stack, root->right); 
            push(stack, root); 
  
            root = root->left; 
        } 
  
       
        root = pop(stack); 
  
      
        if (root->right && peek(stack) == root->right) { 
            pop(stack); 
            push(stack, root);  
            root = root->right; 
                        
        } 
        else { 
            printf("%d ", root->key); 
            root = NULL; 
        } 
    } while (!isEmpty(stack)); 
} 

struct node *insert(struct node *node, int key) {
 
  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

int main() {
  int n;  
  scanf("%d", &n);
  
  struct node *root = NULL;
  for(int i=0; i<n; i++){
      int temp;
      scanf("%d",&temp);
      root = insert(root, temp);
  }
  
  preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postOrderIterative(root);
}