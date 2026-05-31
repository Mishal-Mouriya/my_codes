#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* next;
};

struct node* temp,*new1,*node,*head;

//Helper function to create nodes
struct node* createnode(int key)
{
    struct node* new1=(struct node*)malloc(sizeof(struct node));
    
}