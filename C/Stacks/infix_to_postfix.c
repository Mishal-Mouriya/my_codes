//#6 THINGS TO LEARN FROM THIS CODE



#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;


void push(char x)
{
//since size is full there is no overflow condition
    stack[++top] = x;                               //#1
}


char pop() 
{
    if (top == -1) return -1;
    return stack[top--];                            //#2
}


//precedence you can set tem bth to equal also
int precedence(char c)
 {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0; // For '('
}



int main() 
{

    char exp[100];
    char x;
    printf("Enter your infix expression: ");
    scanf(" %[^\n]", exp);                            //#3      
    char *e = exp;//important pointer mechanices      //#4

    while (*e != '\0') 
    {
        if (isalnum(*e)) 
        {
            printf("%c", *e);
        } 

        else if (*e == '(') 
        {
            push(*e);
        } 
        
        else if (*e == ')')         
        {
            while ((x = pop()) != '(')                //#5
            {
                printf("%c", x);
            }
        } 
        
        else 
        {                                              //#6 ENTIRE LOGIC    
            // Operator logic: pop if stack top has higher or equal precedence
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) 
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    // Final cleanup: pop remaining elements
    while (top != -1)
    {
        printf("%c", pop());
    }
    
}
