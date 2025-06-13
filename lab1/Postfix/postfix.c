#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <math.h>
#define MAX 100
struct stack
{
    int TOS;
    float data[MAX];
};
void push(struct stack *s, float element)
{
    if (s->TOS >= MAX - 1)
    {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->TOS += 1;
    s->data[s->TOS] = element;
}
float pop(struct stack *s)
{
    if (s->TOS < 0)
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->data[s->TOS--];
}
int main()
{
    float op1, op2;
    float result;
    int choice;
    struct stack s = {-1};
    char exp[100];
    printf("Enter the postfix expression: \n");
    fgets(exp, 100, stdin);
    char *token = strtok(exp, " ");
    while (token != NULL)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            push(&s, atof(token));
        }
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            switch (token[0])
            {
            case '^':
                result = pow(op2, op1);
                break;
            case '*':
                result = op2 * op1;
                break;
            case '/':
                result = op2 / op1;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '+':
                result = op2 + op1;
                break;
            }
            push(&s, result);
        }
        token = strtok(NULL, " ");
    }
    if (s.TOS == 0)
        printf("The result of the given postfix expression is %f \n", result);
    else
        printf("Invalid postfix expression.");
    return 0;
}
