//expression Tree--STATUS COMPLETED WITH 2 MAJOR ERRORS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    char key;
    struct node* left;
    struct node* right;
};

int size;
struct node *temp,*key,*node;
struct node *stack[100];
int top =-1;

void stackdisp()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%c ",stack[i]->key);
    }
    printf("\n");
}

struct node* createnode(char x)
{
    struct node* new1=(struct node* )malloc(sizeof(struct node));
    new1->key=x;
    new1->right=NULL;
    new1->left=NULL;
    return new1;
}


void push(struct node* node)
{
    stack[++top]=node;
    
}


struct node* pop()
{
    
    return stack[top--];
}


int ifop(char x)
{
    if(x=='/' || x=='+' || x=='-' || x=='^' || x=='*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


struct node* tree(char arr[])
{
     int i;

    for(i=0;arr[i]!='\0';i++)   
   {
        if(isalnum(arr[i]))
        {
           
            temp=createnode(arr[i]);
            push(temp);            
        }

        if(ifop(arr[i]))
        {
            
            temp=createnode(arr[i]);
            struct node* right=pop();
            struct node* left =pop();
            temp->right=right;  
            temp->left=left;
            push (temp);
        }
        printf("%c               ",arr[i]);
        stackdisp();

    }
    //after this is completed only one element would be reaminign
    
    return pop();
   
}

void inorder(struct node* node)

{
 if(node!=NULL)
 {
    inorder(node->left);
    printf("%c",node->key);
    inorder(node->right);
 }
}


int main()
{
    int i;
    printf("Enter the postfix expression>");
    char string[100];
    scanf("%[^\n]s",string);
    printf("\n");
    //checking whether it got value
    size=0;
    for(i=0;string[i]!='\0';i++)
    {
        size++;
        printf("%c",string[i]);
    }
    printf("\n");
    //
    printf("character     stack");
     printf("\n");
    struct node* root=tree(string);
    printf("\n");
    inorder(root);
    

    
}

