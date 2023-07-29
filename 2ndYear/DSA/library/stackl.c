#include <stdio.h>
#include <stdlib.h>

#include "stackl.h"

// typedef struct Node
// {
//     int val;
//     struct Node *next;
// } Node;

// typedef struct Stack
// {
//     int size;
//     Node *top;
// } Stack;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(1 * sizeof(Node));
    node->val = data;
    node->next = NULL;
}

Stack *newStack()
{
    Stack *st = (Stack *)malloc(1 * sizeof(Stack));
    st->size = 0;
    st->top = NULL;
    return st;
}

void push(Stack *st, int data)
{
    Node *node = newNode(data);

    node->next = st->top;
    st->top = node;
    st->size++;
}

int pop(Stack *st)
{

    if (st->top == NULL)
    {
        printf("Stack Underflow \n");
        return -1;
    }

    Node *node = st->top;
    int data = node->val;
    st->top = st->top->next;
    free(node);
    st->size--;
    return data;
}
void printStack(Stack *st)
{

    Node *cur = st->top;
    if (st->top == NULL)
    {
        printf("Stack is Empty \n");
        return;
    }

    printf("Stack : ");
    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
}
int stackSize(Stack *st)
{
    if (st == NULL)
    {
        printf("Stack Pointer is NULL \n");
        return -1;
    }

    return st->size;
}