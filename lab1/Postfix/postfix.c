#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>
#define MAX_SIZE 100


typedef struct stack {
    int top;
    float data[MAX_SIZE];
} Stack;

float push(Stack *stack, int value) {
    // stack->top += 1;
    return stack->data[++stack->top] = value;
}

float pop(Stack *stack) {
    return stack->data[stack->top--];
}

int main() {
    Stack s = {-1};
    float op1, op2, result = 0;
    char exp[100];

    printf("Enter the postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " \n");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&s, atof(token));
        } else {
            op1 = pop(&s);
            op2 = pop(&s);
            switch (token[0]) {
                case '^': result = pow(op2, op1); break;
                case '*': result = op2 * op1; break;
                case '/': result = op2 / op1; break;
                case '-': result = op2 - op1; break;
                case '+': result = op2 + op1; break;
                default:
                    printf("Unknown operator: %s\n", token);
                    return 1;
            }
            push(&s, result);
        }
        token = strtok(NULL, " \n");
    }

    if (s.top == 0)
        printf("The result of the given expression is: %.2f\n", pop(&s));
    else
        printf("Invalid postfix expression.\n");

    return 0;
}
