#include <stdio.h>
#define true 1
#define false 0
#define MAX_SIZE 5


typedef struct stack {
    int top;
    int data[MAX_SIZE];
} Stack;

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1 ? true : false;
}

int isEmpty(Stack *stack) {
    return stack->top == -1 ? true : false;
}

int push(Stack *stack, int value) {
    // stack->top += 1;
    stack->data[++stack->top] = value;
    return true;
}

int pop(Stack *stack) {
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    return stack->data[stack->top];
}

int main() {
    int choice, value;
    Stack S = {.top = -1};

    do {
        printf("1.PUSH \n2.POP \n3.PEEK \n4.IsFull \n5.IsEmpty \n6.EXIT\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&S)) {
                    printf("STACK OVERFLOW!!\n");
                } else {
                    printf("Enter the value to be pushed: ");
                    scanf("%d", &value);
                    push(&S, value);
                    printf("Pushed %d onto the stack\n", value);
                }
                break;

            case 2:
                if (isEmpty(&S)) {
                    printf("STACK UNDERFLOW!!\n");
                } else {
                    printf("Popped %d from the stack\n", pop(&S));
                }
                break;

            case 3:
                if (isEmpty(&S)) {
                    printf("STACK IS EMPTY!!\n");
                } else {
                    printf("%d is the top of stack\n", peek(&S));
                }
                break;

            case 4:
                printf("Is Full: %s\n", isFull(&S) ? "Yes" : "No");
                break;

            case 5:
                printf("Is Empty: %s\n", isEmpty(&S) ? "Yes" : "No");
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}