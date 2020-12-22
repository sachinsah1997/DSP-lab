#include<stdio.h>
#include<stdlib.h>

int n;
int Top = -1, postIndex;


void push(int value, int s[]){
     
    if(Top==n-1){
        printf("\nOverflow!!");
    }
    else{
        Top=Top+1;
        s[Top]=value;
    }
}

void pop(int s[]){
    
    if(Top==-1){
        
        printf("\nUnderflow!!");
    }
    else{
        printf("\nPopped element:  %d",s[Top]);
        Top=Top-1;
    }
}

// A utility function to search data in in[] 
int search (int in[], int data, int n){
  int i = 0;
  for (i = 0; i < n; i++)
    if (in[i] == data)
      return i;
  return i;
}

// Fills preorder traversal of tree with given 
// inorder and postorder traversals in a stack 
void fillPre (int in[], int post[], int inStrt, int inEnd, int s[], int n, int postIndex, int Top){
  
  if (inStrt > inEnd)
    return;

  // Find index of next item in postorder traversal in 
  // inorder. 
  int val = post[postIndex];
  int inIndex = search (in, val, n);
  postIndex--;

  // traverse right tree 
  fillPre (in, post, inIndex + 1, inEnd, s, n, postIndex, Top);

  // traverse left tree 
  fillPre (in, post, inStrt, inIndex - 1, s, n, postIndex, Top);

  push(val,s);
}

// This function basically initializes postIndex 
// as last element index, then fills stack with 
// reverse preorder traversal using printPre 
void printPreMain (int in[], int post[], int n, int s[]){
    

  int len = n;
  postIndex = len - 1;  
  fillPre (in, post, 0, len - 1, s, n, postIndex, Top);
  int sLength = sizeof(s) / sizeof(s[0]);
  
  while (sLength > 0){
      printf("%d",s[Top]);
      pop(s,Top);
    }
}

int main (){

  int n;
   int Top=-1;
    int postIndex = 0;

  int value;
  
  printf ("Enter the no. of element : ");
  scanf ("%d", &n);

  int post[n], in[n], s[n];
  printf ("Enter the Inorder :");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &value);
      in[i] = value;
    }

  printf ("Enter the Postorder :");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &value);
      post[i] = value;
    }

  printPreMain (in, post, n, s);

  return 0;
}
