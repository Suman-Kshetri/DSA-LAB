#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAX_SIZE 100


typedef struct stack {
    int top;
    int data[MAX_SIZE];
} Stack;

float push(Stack *stack, int value) {
    // stack->top += 1;
    return stack->data[++stack->top] = value;
}

float pop(Stack *stack) {
    return stack->data[stack->top--];
}

int main(){
    Stack s = {-1};
    float op1, op2, result;
    char exp[100];
    printf("Enter the postfix expression: ");\
    scanf("%s", exp);
    char *token = strtok(exp, " ");
    while(token != NULL)
    {
        if(isdigit(token[0]))
        {
            push(&s, token[0]);
        }
        else{
            op1 = pop(&s);
            op2 = pop(&s);
            switch(token[0])
            {
                case '^': return pow(op1, op2); break;
                case '*':
                case '/':
                case '-':
                case '+':
            }
        }
    }
    
    return 0;
}
