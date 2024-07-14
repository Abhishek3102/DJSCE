#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void prefixToPostfix(char prefix[], char postfix[]) {
    int length = strlen(prefix);
    char stack[MAX];
    int top = -1;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            // Pop two operands from the stack and concatenate them with the operator.
            char operand1 = stack[top--];
            char operand2 = stack[top--];
            postfix[++top] = operand1;
            postfix[++top] = operand2;
            postfix[++top] = prefix[i];
        } else {
            // Push operands onto the stack.
            stack[++top] = prefix[i];
        }
    }
    postfix[++top] = '\0'; // Null-terminate the postfix expression.
}

int main() {
    char prefix[MAX];
    char postfix[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
