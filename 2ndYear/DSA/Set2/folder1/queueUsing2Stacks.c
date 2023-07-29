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

//    printf("Stack : ");
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



typedef struct Queue{
    int size;
    Stack *st1,*st2;
}Queue;

Queue *newQueue(){
    Queue *q=(Queue*)malloc(1*sizeof(Queue));
    if(q==NULL){
        printf("Queue Overflow \n");
        return NULL;
    }
    q->size=0;
    q->st1=newStack();
    q->st2=newStack();
    return q;
}

void enqueue(Queue *q,int x){
    if(q==NULL){
        printf("No Queue provided \n");
        return ;
    }

	int val;
	while(stackSize(q->st1)>0)
	{
		val=pop(q->st1);
		push(q->st2,val);
	}
	
	push(q->st1,x);

	while(stackSize(q->st2)>0)
	{
		val=pop(q->st2);
		push(q->st1,val);
	}
	
	q->size++;
}
int dequeue(Queue *q)
{
    if(q==NULL){
        printf("No Queue provided \n");
        return -1;
    }

    if(q->size==0){
        printf("Queue is Empty \n");
        return -1;
    }

	if(stackSize(q->st1)==0){
	    printf("Queue is Empty \n");
        return -1;
	}
	
	int val = pop(q->st1);
	q->size--;
	return val;
	 
}
void printQueue(Queue *q){
    if(q==NULL){
        printf("No Queue provided \n");
        return ;
    }

    if(q->size==0){
        printf("Queue is Empty \n");
        return ;
    }

    printf("QUEUE : "); 
    printStack(q->st1);
    printf("\n");
}
int queueSize(Queue *q)
{
    if(q==NULL){
        printf("No Queue provided \n");
        return -1;
    }
    return q->size;
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
    printf("Press 1 to Print the Queue \n");
    printf("Press 2 to Enqueue an element into the Queue \n");
    printf("Press 3 to Dequeue an element from the Queue \n");
    printf("Press 4 to Print the Queue size \n");
    printf("Print 9 to Exit \n");
}



int main()
{

    Queue *q = newQueue();
    int ch = -1;
    int data = -1;
    while (ch != 9)
    {
        prompt();
        ch = getChoice();
        switch (ch)
        {
        case 1:
            printQueue(q);
            break;
        case 2:
            data = getData();
            enqueue(q, data);
            break;
        case 3:
            data = dequeue(q);
            printf("%d was dequeued \n", data);
            break;
        case 4:
            data = queueSize(q);
            printf("Queue size is %d \n", data);
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
