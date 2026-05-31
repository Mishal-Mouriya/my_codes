#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push (simple)
void push(char x) {
    stack[++top] = x;
}

// Pop (VERY simple now)
char pop() {
    return stack[top--];
}

// Precedence
int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

// Print stack
void printStack() {
    if (top == -1) {
        printf("-");
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
}

// Main logic
void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;

    printf("\nSymbol\tStack\t\tPostfix\n");

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // '('
        else if (ch == '(') {
            push(ch);
        }

        // ')'
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 &&
                  ((precedence(stack[top]) > precedence(ch)) ||
                  (precedence(stack[top]) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }
            push(ch);
        }

        // Print trace
        printf("%c\t", ch);
        printStack();
        printf("\t\t%s\n", postfix);
    }

    // Empty remaining stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("(end)\t-\t\t%s\n", postfix);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression:\n");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix expression:\n%s\n", postfix);

    return 0;
}