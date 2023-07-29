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
    return node;
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


int evaluatePostfix(char* exp)
{
    // Create a stack of capacity equal to expression size
    Stack *st = newStack();
    int i;
 
    int val1,val2;
    // See if stack was created successfully
    if (st==NULL) return -1;
 
    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (exp[i]>='0' && exp[i]<='9')
            push(st, exp[i] - '0');
 
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            val1 = pop(st);
            val2 = pop(st);
            switch (exp[i])
            {
            case '+': push(st, val2 + val1); break;
            case '-': push(st, val2 - val1); break;
            case '*': push(st, val2 * val1); break;
            case '/': push(st, val2/val1); break;
            }
        }
    }
    return pop(st);
}

int main()
{

    Stack *st = newStack();

    printf("Enter the PostFix expression : ");
    char exp[100];
    scanf("%[^\n]%*c",exp);
    puts(exp);

    int ans=evaluatePostfix(exp);
    printf("The answer is = %d \n",ans);

    return 0;
}
