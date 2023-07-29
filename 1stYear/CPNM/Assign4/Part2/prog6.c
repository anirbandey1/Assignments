#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack ;

Stack *StackNew();
void StackDelete(Stack *);
int push(Stack *, int);
int pop(Stack *,int *);
void DisplayStack(Stack *);



Stack *StackNew(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top=NULL;
    return s;
}

int push(Stack *s,int val){
    if(s==NULL)
        return -1;

    Node *node = (Node *)malloc(sizeof(Node));
    if(node==NULL){
        printf("Stack Overflow \n");
        return -1;
    } 
    node->val=val;
    node->next=s->top;

    s->top=node;
    return 0;
}

int pop(Stack *s,int *data){

    if(s==NULL)
        return -1;

    if(s->top == NULL){
        printf("STACK UNDERFLOW \n");
        return -1;
    }
    if(data==NULL)
        return -1;
    
    *data=s->top->val;
    Node *node=s->top;
    s->top=s->top->next;
    free(node);

    return 0;
}
void DisplayStack(Stack *s){
    if(s==NULL){
        printf("STACK NOT DECLARED \n");
        return ;
    }
    Node *node=s->top;
    printf("STACK : ");
    while(node){
        printf("%d ",node->val);
        node=node->next;
    }
    printf("\n");

}
int main(){

    Stack *s=StackNew();
    int retVal=-1;
    
    printf("Push elements : %d %d %d \n",-50,30,12);
    push(s,-50);
    push(s,30);
    push(s,12);
    DisplayStack(s);
    printf("Pop an element from the TOP \n");
    pop(s,&retVal);
    DisplayStack(s);
    return 0;
}
