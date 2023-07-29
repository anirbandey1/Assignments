#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node* next;
}Node;

Node* newNode(int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->val=data;
	node->next=NULL;
}

Node* inputList(Node* head){

	int i,n,data;
	printf("Enter the size of Linked List : ");
	scanf("%d",&n);

	printf("Enter %d elements : ",n);
	scanf("%d",&data);
	head = newNode(data);

	Node* ptr=head;	
	for(i=1;i<n;i++)
	{
		scanf("%d",&data);
		ptr->next=newNode(data);	
		ptr=ptr->next;
	}
	return head;


}

void printList(Node* head){

	printf("LINKED LIST : ");
	while(head)
	{
		printf("%d ",head->val);
		head=head->next;
	}
	printf("\n");
}

int count(Node*head){

	int cnt=0;
	while(head){
		head=head->next;
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

Node *insertBeg(Node*head,int data){

	Node* node = newNode(data);
	node->next=head;
	return node;
}

Node *insertEnd(Node*head,int data){
	
	Node* node = newNode(data);
	Node *prev, *ptr;
	prev=NULL;
	ptr=head;

	while(ptr)
	{
		prev=ptr;
		ptr=ptr->next;
	}
	prev->next = node;

	return head;
}

Node *insert(Node*head,int data,int pos)
{
	if(pos==0){
		head=insertBeg(head,data);
		return head;
	}

	Node *prev,*ptr;
	prev=NULL;
	ptr=head;

	int i;
	for(i=0;i<pos;i++)
	{
		prev=ptr;
		ptr=ptr->next;
	}

	Node *node=newNode(data);
	prev->next=node;
	node->next=ptr;

	return head;
}

Node *delete(Node*head,int key){

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
int main(){

	Node* head;
	head = inputList(head);
	printList(head);

	head = reverseList(head);
	printList(head);

	int data,pos;

	printf("Insert at Beginning \n");
	printf("Data : ");
	scanf("%d",&data);

	head = insertBeg(head,data);
	printList(head);

	int cnt=count(head);
	printf("Count = %d \n",cnt);

	printf("Insert at End \n");
        printf("Data : ");
        scanf("%d",&data);

	head = insertEnd(head,data);
	printList(head);


	printf("Insert at a Given Position \n");
        printf("Data : ");
        scanf("%d",&data);
        printf("Position : ");
        scanf("%d",&pos);

	head = insert(head,data,pos);
	printList(head);


	printf("Delete at a  \n");
        printf("Data : ");
	scanf("%d",&data);

	head=delete(head,data);
	printList(head);
	
	return 0;
}
