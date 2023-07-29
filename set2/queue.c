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
        printf("Stack Overflow \n");
        return NULL;
    }
    node->val=data;
    node->next=NULL;
    return node;
}

Queue *newQueue(){
    Queue *q=(Queue*)malloc(1*sizeof(Queue));
    if(q==NULL){
        printf("Stack Overflow \n");
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
        return;
    }

    q->rear->next=node;
    q->rear=node;
}
int dequeue(Queue *q)
{
    if(q==NULL){
        printf("No Queue provided \n");
        return ;
    }

    if(q->size==0){
        printf("Queue is Empty \n");
        return ;
    }

    Node *node=q->rear;
    int data=node->val;
    if(q->size=1){
        q->front=q->rear=NULL;
        free(node);
        return data;
    }

    
}
void printStack(Queue *q){
    if(q==NULL){
        printf("No Queue provided \n");
        return ;
    }

    if(q->size==0){
        printf("Queue is Empty \n");
        return ;
    }

    print("QUEUE : ");
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