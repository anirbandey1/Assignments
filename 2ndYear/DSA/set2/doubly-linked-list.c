#include <stdio.h>
#include <stdlib.h>

// C implementation
typedef struct Node{
    int val;
    struct Node *prev,*next;
}Node;

Node *newNode(int data){
    Node *node=(Node*)malloc(1*sizeof(Node));
    if(node==NULL){
        printf("STACK OVERFLOW \n");
        return NULL;
    }
    node->val=data;
    node->prev=node->next=NULL;
    return node;
}

Node *insertEnd(Node *head,int data){

    Node *node=newNode(data);

    if(head==NULL){
        return node;
    }

    Node *ptr=head;
    while(ptr->next){
        ptr=ptr->next;
    }
    ptr->next=node;
    node->prev=ptr;
    return head;


}

Node *deleteEnd(Node *head)
{
    if(head==NULL){
        printf("Doubly Linked List is Empty \n");
        return NULL;
    }
    Node *ptr=head,*prev=NULL;
    while(ptr->next){
        ptr=ptr->next;
    }
    prev=ptr->prev;
    if(prev==NULL){
       free(ptr);
       return NULL;
    }

    free(ptr);
    prev->next=NULL; 
    
    return head;


}
void printDList(Node *head)
{
    if(head==NULL){
        printf("No Doubly Linked List Provided \n");
        return ;
    }

    printf("DOUBLY LINKED LIST : ");
    while(head)
    {
        printf("%d ",head->val);
        head=head->next;
    }
}

int dlistSize(Node *head)
{
    if(head==NULL){
        //printf("No Doubly Linked List Provided \n");
        return 0;
    }

    int cnt=0;
    while(head)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
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
    printf("Press 1 to Print the Doubly-Linked-List \n");
    printf("Press 2 to Insert an element at the beginning of the Doubly-Linked-List \n");
    printf("Press 3 to Delete an element from the end of the Doubly-Linked-List \n");
    printf("Press 4 to Print the Doubly-Linked-List size \n");
    printf("Print 9 to Exit \n");
}

int main()
{

    Node *head=NULL;
    int ch = -1;
    int data = -1;
    while (ch != 9)
    {
        prompt();
        ch = getChoice();
        switch (ch)
        {
        case 1:
            printDList(head);
            break;
        case 2:
            data = getData();
            head=insertEnd(head, data);
            break;
        case 3:
            head = deleteEnd(head);
            break;
        case 4:
            data = dlistSize(head);
            printf("Doubly-Linked-List size is %d \n", data);
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
