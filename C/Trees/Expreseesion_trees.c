                           //Expression tree code


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for isalnum()

// Tree node
struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(char value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Stack for storing nodes
struct Node* stack[100];
int top = -1;

// Push function
void push(struct Node* node)
{
    stack[++top] = node;
}

// Pop function
struct Node* pop()
{
    return stack[top--];
}

// Check if operator
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

// Build expression tree
struct Node* buildTree(char postfix[])
{
    int i = 0;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];

        // If operand (a-z, A-Z, 0-9)
        if (isalnum(ch))
        {
            struct Node* node = createNode(ch);
            push(node);
        }
        else if (isOperator(ch))
        {
            // Create operator node
            struct Node* node = createNode(ch);

            // Pop 2 nodes
            struct Node* right = pop();
            struct Node* left = pop();

            // Attach children
            node->left = left;
            node->right = right;

            // Push back
            push(node);
        }

        i++;
    }

    // Final node is root
    return pop();
}

// Inorder traversal
void inorder(struct Node* root)
{
    if (root == NULL)
        return;

    // Add brackets for clarity
    if (isOperator(root->data)) printf("(");

    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);

    if (isOperator(root->data)) printf(")");
}

// MAIN
int main()
{
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct Node* root = buildTree(postfix);

    printf("Infix expression: ");
    inorder(root);

    return 0;
}