#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 

// This structure is used to build structure for stack.
struct Stack{ 
  int top; 
  unsigned capacity; 
  int* array; 
}; 

// this method will create stack.
struct Stack* createStack( unsigned capacity ){ 
  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

  if (!stack) return NULL; 

  stack->top = -1; 
  stack->capacity = capacity; 
  stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

  if (!stack->array) return NULL; 

  return stack; 
} 

//this method to check if stack empty or not.
int isEmpty(struct Stack* stack){ 
  return stack->top == -1 ; 
} 

//this method is used to see the top element on the stack.
int peek(struct Stack* stack){ 
  return stack->array[stack->top]; 
} 

//this method is used to delete the top element of the stack.
int pop(struct Stack* stack){ 
  if (!isEmpty(stack)) 
    return stack->array[stack->top--] ; 
  return '$'; 
} 

//this method is used to add element in the stack.
void push(struct Stack* stack,int op){ 
  stack->array[++stack->top] = op; 
} 

// This method is used to process and returns value of a given postfix expression 
int evaluatePostfix(char* exp){ 
  
  // Createds a stack of capacity equal to expression size 
  struct Stack* stack = createStack(strlen(exp)); 
  int i; 

  // See if stack was created successfully 
  if (!stack) return -1; 

  // Scan all characters one by one 
  for (i = 0; exp[i]; ++i) 
  { 
    //if the character is blank space then continue 
    if(exp[i]==' ')continue; 
    
    // this will scan for the operand having more digits. It collect whole operand and will store in stack.
    else if (isdigit(exp[i])){ 
      int num=0; 
      
      //extract full number'or we can say digits.
      while(isdigit(exp[i])){ 
      num=num*10 + (int)(exp[i]-'0'); 
        i++; 
      } 
      i--; 
      
      //push the element in the stack 
      push(stack,num); 
    } 
    
    // If the scanned character is an operator, pop two elements from stack apply the operator 
    else{ 
      int val1 = pop(stack); 
      int val2 = pop(stack); 
      
      switch (exp[i]){ 
      case '+': push(stack, val2 + val1); break; 
      case '-': push(stack, val2 - val1); break; 
      case '*': push(stack, val2 * val1); break; 
      case '/': push(stack, val2/val1); break; 
      
      } 
    } 
  } 
  return pop(stack); 
} 

int main(){ 
  char exp[] = "150 150 + 4 / 10 * 70 +"; 
  printf ("The Evaluted Answer : %d\n", evaluatePostfix(exp)); 
  return 0; 
}   