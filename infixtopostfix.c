#include<stdio.h>
#include<ctype.h>

char stack[100], eval_stack[100];
int top = -1, eval_top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

void eval_push(char x){
    eval_stack[++eval_top] = x;
}

char eval_pop(){
    if(eval_top == -1)
        return -1;
    else
        return eval_stack[eval_top--];
}



int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}


void EvalPostfix(char postfix[]){

    int i;
    char ch;
    int val;
    int A, B;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            eval_push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
           
            A = eval_pop();
            B = eval_pop();

            switch (ch){
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }
            eval_push(val);
        }
    }
    printf(" \n postfix expression evaluation : %d \n", eval_pop());
}

int main(){
    
    char infix[]="1+3+4*4", postfix[100];
    char *e, x;
    printf("Infix expression : %s\n", infix);
    e = infix;
    
    int count = -1;
    while(*e != '\0'){
        
        if(isdigit(*e))
            postfix[++count]=*e;
        else if(*e == '(')
            push(*e);
        else if(*e == ')'){
            
            while((x = pop()) != '(')
                postfix[++count] = x;
        }
        else{
            
            while(priority(stack[top]) >= priority(*e))
                postfix[++count] = pop();
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
        postfix[++count] = pop();
    
    printf("PostFix Expression : %s", postfix);
    
    EvalPostfix(postfix);
    
    return 0;
} 