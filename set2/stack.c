#include <stdio.h>
#include <stdlib.h>

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

Node *newNode(int data)
{
    Node *node = (Node *)malloc(1 * sizeof(Node));
    if (node == NULL)
    {
        printf("STACK OVERFLOW \n");
        return NULL;
    }
    node->val = data;
    node->next = NULL;
}

Stack *newStack()
{
    Stack *st = (Stack *)malloc(1 * sizeof(Stack));
    if (st == NULL)
    {
        printf("STACK OVERFLOW \n");
        return NULL;
    }
    st->size = 0;
    st->top = NULL;
    return st;
}

void push(Stack *st, int data)
{
    if (st == NULL)
    {
        printf("No Stack Provided \n");
        return ;
    }
    Node *node = newNode(data);

    node->next = st->top;
    st->top = node;
    st->size++;
}

int pop(Stack *st)
{
    if (st == NULL)
    {
        printf("No Stack provided \n");
        return -1;
    }
    if (st->top == NULL)
    {
        printf("Stack is Empty \n");
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
    if (st == NULL)
    {
        printf("No Stack Provided \n");
        return ;
    }

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
        printf("No Stack Provided \n");
        return -1;
    }

    return st->size;
}

int getData()
{
    printf("Enter the data : ");
    int data = -1;
    scanf("%d", &data);
    return data;
}
int getChoice()
{
    printf("Enter your choice : ");
    int data = -1;
    scanf("%d", &data);
    return data;
}

void prompt()
{
    printf("\n");
    printf("Press 1 to Print the Stack \n");
    printf("Press 2 to Push an element into the Stack \n");
    printf("Press 3 to Pop an element from the Stack \n");
    printf("Press 4 to Print the Stack size \n");
    printf("Print 9 to Exit \n");
}

int main()
{

    Stack *st = newStack();
    int ch = -1;
    int data = -1;
    while (ch != 9)
    {
        prompt();
        ch = getChoice();
        switch (ch)
        {
        case 1:
            printStack(st);
            break;
        case 2:
            data = getData();
            push(st, data);
            break;
        case 3:
            data = pop(st);
            printf("%d was popped \n", data);
            break;
        case 4:
            data = stackSize(st);
            printf("Stack size is %d \n", data);
            break;
        case 9:
            printf("Thank You \n");
            break;
        default:
            printf("Please select a Valid Option ");
            break;
        }
    }

    return 0;
}