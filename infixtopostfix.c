#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

// This structure is used to build structure for stack.
struct Stack{ 
  int top; 
  unsigned capacity; 
  int* array; 
}; 

// this method will create stack.
struct Stack* createStack(unsigned capacity){ 
  struct Stack* stack = (struct Stack*) 
    malloc(sizeof(struct Stack)); 

  if (!stack) 
    return NULL; 

  stack->top = -1; 
  stack->capacity = capacity; 

  stack->array = (int*) malloc(stack->capacity * 
                sizeof(int)); 

  return stack; 
} 

//this method to check if stack empty or not.
int isEmpty(struct Stack* stack){ 
  return stack->top == -1 ; 
} 

//this method is used to see the top element on the stack.
char peek(struct Stack* stack){ 
  return stack->array[stack->top]; 
}

//this method is used to delete the top element of the stack. 
char pop(struct Stack* stack){ 
  if (!isEmpty(stack)) 
    return stack->array[stack->top--] ; 
  return '$'; 
}

//this method is used to add element in the stack.
void push(struct Stack* stack, char op){ 
  stack->array[++stack->top] = op; 
} 


// A utility function to check if the given character is operand means character
int isOperand(char ch) 
{ 
  return (ch >= 'a' && ch <= 'z') || 
    (ch >= 'A' && ch <= 'Z'); 
} 

// A utility function to return precedence of a given operator.
// here higher returned value means higher precedence.
int Prec(char ch) 
{ 
  switch (ch) 
  { 
  case '+': 
  case '-': 
    return 1; 

  case '*': 
  case '/': 
    return 2; 

  case '^': 
    return 3; 
  } 
  return -1; 
} 


// This method is used to converts given infix expression to postfix expression. 
int infixToPostfix(char* exp){ 
  int i, k; 

  // Create a stack of capacity equal to expression size 
  struct Stack* stack = createStack(strlen(exp)); 
  if(!stack) // See if stack was created successfully 
    return -1 ; 

  for (i = 0, k = -1; exp[i]; ++i){ 
    
    // If the scanned character is an operand, add it to output. 
    if (isOperand(exp[i])) 
      exp[++k] = exp[i]; 
    
    // If the scanned character is an ‘(‘, push it to the stack. 
    else if (exp[i] == '(') 
      push(stack, exp[i]); 
    
    // If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered. 
    else if (exp[i] == ')'){ 
      while (!isEmpty(stack) && peek(stack) != '(') 
        exp[++k] = pop(stack); 
      if (!isEmpty(stack) && peek(stack) != '(') 
        return -1; // invalid expression       
      else
        pop(stack); 
    } 
    else // an operator is encountered 
    { 
      while (!isEmpty(stack) && 
        Prec(exp[i]) <= Prec(peek(stack))) 
        exp[++k] = pop(stack); 
      push(stack, exp[i]); 
    } 

  } 

  // pop all the operators from the stack 
  while (!isEmpty(stack)) 
    exp[++k] = pop(stack ); 

  exp[++k] = '\0'; 
  printf( "%s", exp ); 
} 

int main(){ 
  char exp[] = "a+b*(c^d-e)^(f+g*h)-i"; 
  infixToPostfix(exp); 
  return 0; 
} 