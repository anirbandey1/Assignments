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

int peek(Stack *st)
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

    int data = st->top->val;
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

int isEmpty(Stack *st){
     if (st == NULL)
    {
        printf("No Stack Provided \n");
        return -1;
    }

    return st->size>0;	

}

// A utility function to check if
// the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z')
           || (ch >= 'A' && ch <= 'Z');
}
 
// A utility function to return
// precedence of a given operator
// Higher returned value means
// higher precedence
int Prec(char ch)
{
    switch (ch) {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 
// The main function that
// converts given infix expression
// to postfix expression.
int infixToPostfix(char* exp)
{
    int i, k;
 
    // Create a stack of capacity
    // equal to expression size
   // struct Stack* stack = createStack(strlen(exp));
     Stack *st = newStack();
    if (st==NULL) // See if stack was created successfully
        return -1;
 
    for (i = 0, k = -1; exp[i]; ++i) {
 
        // If the scanned character is
        // an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(st, exp[i]);
 
        // If the scanned character is an ‘)’,
        // pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')') {
            while (!isEmpty(st) && peek(st) != '(')
                exp[++k] = pop(st);
            if (!isEmpty(st) && peek(st) != '(')
                return -1; // invalid expression
            else
                pop(st);
        }
 
        else // an operator is encountered
        {
            while (!isEmpty(st)
                   && Prec(exp[i]) <= Prec(peek(st)))
                exp[++k] = pop(st);
            push(st, exp[i]);
        }
    }
 
    // pop all the operators from the stack
    while (!isEmpty(st))
        exp[++k] = pop(st);
 
    exp[++k] = '\0';
    printf("%s", exp);
}

int main()
{
    printf("Enter the Infix expression : ");
    char exp[100];
    scanf("%[^\n]%*c",exp);
    puts(exp);

    int ans=infixToPostfix(exp);
    printf("Return value : %d \n",ans);
    printf("The Postfix is = ");
    puts(exp);

    return 0;
}

