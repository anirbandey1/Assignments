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

Node *insertBeg(Node*head,int data){

	Node* node = newNode(data);
	node->next=head;
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
Node *insert(Node*head,int data,int pos)
{
	if(pos==1){
		head=insertBeg(head,data);
		return head;
	}

	Node *prev,*ptr;
	prev=NULL;
	ptr=head;

	int i;
	for(i=1;i<pos;i++)
	{
		prev=ptr;
		ptr=ptr->next;
	}

	Node *node=newNode(data);
	prev->next=node;
	node->next=ptr;

	return head;
}

Node* delete(Node*head,int key){

	Node*prev,*ptr,*temp;
	prev=NULL;
	ptr=head;

	if(ptr->val==key){
		temp=ptr;
		ptr=ptr->next;
		free(temp);
		return ptr;
	}

	while(ptr && ptr->val!=key)
	{
		prev=ptr;
		ptr=ptr->next;
	}

	if(ptr){
		temp=ptr;
		prev->next=ptr->next;
		free(ptr);
	}

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

Node* reverseList(Node* head){

	Node *prev,*ptr,*next;
	ptr=head;
	prev=next=NULL;

	while(ptr)
	{
		next=ptr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=next;
	}
	return prev;
}
int getPos(){
   printf("Enter the position : ");
   int pos=0;
   scanf("%d",&pos);
   return pos;
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
    printf("Press 2 to Insert an element at the end of the Doubly-Linked-List \n");
    printf("Press 3 to Insert an element at the beginning of the Doubly-Linked-List \n");
    printf("Press 4 to Insert an element at a particular position : \n");
    printf("Press 5 to Delete an element from the end of the Doubly-Linked-List \n");
    printf("Press 6 to Delete an element with a particular value \n");
    printf("Press 7 to Print the Doubly-Linked-List size \n");
    printf("Press 8 to Reverse the Doubly-Linked-List \n");
    printf("Print 9 to Exit \n");
}

int main()
{

    Node *head=NULL;
    int ch = -1;
    int data = -1,pos=0;
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
            data=getData();
            head=insertBeg(head,data);
            break;
       case 4:
            data=getData();
            pos=getPos();
            head=insert(head,data,pos);
            break;
        case 5:
            head = deleteEnd(head);
            break;
        case 6:
            data=getData();
            head=delete(head,data);
            break;
        case 7:
            data = dlistSize(head);
            printf("Doubly-Linked-List size is %d \n", data);
            break;
	case 8:
            head = reverseList(head);
            printf("Doubly Linked List has been Reversed \n");
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
