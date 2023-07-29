#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct Queue{
    int size;;
    Node *front,*rear;
}Queue;

Node *newNode(int data){
    Node *node=(Node*)malloc(1*sizeof(Node));
    if(node==NULL){
        printf("Queue Overflow \n");
        return NULL;
    }
    node->val=data;
    node->next=NULL;
    return node;
}

Queue *newQueue(){
    Queue *q=(Queue*)malloc(1*sizeof(Queue));
    if(q==NULL){
        printf("Queue Overflow \n");
        return NULL;
    }
    q->size=0;
    q->front=q->rear=NULL;
    return q;
}

void enqueue(Queue *q,int data){
    if(q==NULL){
        printf("No Queue provided \n");
        return ;
    }

    Node *node = newNode(data);
    if(node==NULL){
        printf("Queue is FULL \n");
        return ;
    }

    if(q->size==0){
        q->front=q->rear=node;
        q->size++;
        return;
    }

    q->rear->next=node;
    q->rear=node;
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

    Node *node=q->front;
    int data=node->val;
    if(q->size==1){
        q->front=q->rear=NULL;
        free(node);
        q->size--;
        return data;
    }

    q->front=node->next;
    free(node);
    q->size--;
    return data;
    
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
    Node *cur=q->front;
    while(cur)
    {
        printf("%d ",cur->val);
        cur=cur->next;
    }
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
