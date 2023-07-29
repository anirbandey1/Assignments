#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = data;
    node->next = NULL;
}

Node *fillList(int n)
{
    if(n<=0)return NULL;

    Node *node,*head;
    int x;

    printf("Enter the digits : ");
    scanf("%d",&x);
    head=newNode(x);
    node=head;
    
    n--;
    while (n-- > 0)
    {
        scanf("%d",&x);
        node->next=newNode(x);
        node=node->next;
    }
    return head;
}
void print(Node* node)
{
    if(node==NULL){
        printf("Empty Number \n");
        return ;
    }
    printf("Number : ");
    while (node)
    {
        printf("%d ",node->val);
        node=node->next;
    }
    printf("\n");
}

Node* reverseList(Node *head)
{
    Node *pre,*ptr,*next;
    ptr=head;
    pre=next=NULL;

    while(ptr)
    {
        next=ptr->next;
        ptr->next=pre;
        pre=ptr;
        ptr=next;
    }
    return pre;
}
Node *addList(Node *l1, Node *l2)
{
    Node *dummy,*ptr,*node;
    dummy=newNode(-1);
    ptr=dummy;
    node=NULL;

    int carry=0;

    while(l1 || l2 || carry)
    {
        int sum=0;
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        sum=sum%10;

        node=newNode(sum);
        ptr->next=node;
        ptr=ptr->next;
    }

    Node* start=dummy->next;
    dummy->next=NULL;
    start=reverseList(start);
    return start;
}
int main()
{
    int n1,n2;
    printf("Enter no. of digits in the two numbers : ");
    scanf("%d%d",&n1,&n2);

    Node *h1,*h2,*h3;
    printf("Enter the first number \n");
    h1=fillList(n1);
    printf("Enter the second number \n");
    h2=fillList(n2);

    printf("First Number \n");
    print(h1);
    printf("Second Number \n");
    print(h2);

    h1=reverseList(h1);
    h2=reverseList(h2);

    h3=addList(h1,h2);
    printf("Sum of two numbers :- \n");
    print(h3);

    h1=reverseList(h1);
    h2=reverseList(h2);

    return 0;
}