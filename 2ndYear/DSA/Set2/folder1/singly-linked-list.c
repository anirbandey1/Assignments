#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node* next;
}Node;

Node* newNode(int data){
	Node* node=(Node*)malloc(sizeof(Node));
    if(node==NULL){
        printf("STACK OVERFLOW \n");
        return NULL;
    }
	node->val=data;
	node->next=NULL;
    return node;
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

    if(head==NULL){
        printf("Linked List is Empty \n");
        return ;
    }
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









/*
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
*/

/*
int main(){

	Node* head;
        head = inputList(head);
        printList(head);

	int data=0,pos=0;

	char ch='10';
	while(ch!='9')
	{

		if(ch=='1'){


		}

	}
	
	return 0;
}
*/

int getData()
{
    printf("Enter the data : ");
    int data = -1;
    scanf("%d", &data);
    return data;
}

int getPos()
{
    printf("Enter the position : ");
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
	printf("Press 1 to Print the List \n");
	printf("Press 2 to Count the Number of Elements \n");
	printf("Press 3 to Reverse the List \n");
   	printf("Press 4 to Insert at the Beginning \n");
	printf("Press 5 to Insert at the End \n");
	printf("Press 6 to Insert at a particular position \n");
	printf("Press 7 to Delete the node with a particular value \n");
    printf("Press 9 to Exit");
    printf("\n");
}



int main()
{

    Node *head=NULL;
    head=inputList(head);
    int ch = -1;
    int data = -1,pos=0;
    while (ch != 9)
    {
        prompt();
        ch = getChoice();
        switch (ch)
        {
        case 1:
            printList(head);
            break;
        case 2:
            data=count(head);
            printf("Size of Linked List : %d \n",data);
            break;
        case 3:
            head=reverseList(head);
            printf("The List has been REVERSED \n");
            break;
        case 4:
            data = getData();
            head=insertBeg(head,data);
            break;
        case 5:
            data = getData();
            head=insertEnd(head,data);
            break;
        case 6:
            data = getData();
            pos = getPos();
            head = insert(head,data,pos);
            break; 
        case 7:
            data = getData();
            head = delete(head,data);
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
