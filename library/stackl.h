#ifndef __STACKL_H__
#define __STACKL_H__

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct Stack
{
    int size;
    Node *top;
} Stack;

Node *newNode(int data);
Stack *newStack();
void push(Stack *st, int data);
int pop(Stack *st);
void printStack(Stack *st);
int stackSize(Stack *st);

#endif   /*  __STACKL_H__ */

