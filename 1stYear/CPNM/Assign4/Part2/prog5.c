#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node *next;

}Node;

Node *NewNode(int data){

	Node *node=(Node *)malloc(sizeof(Node));
	node->next=NULL;
	node->val=data;
}

Node *input(){

	int a,n;
	Node *list,*ptr;
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	printf("Enter the elementsof LINKED LIST : \n");
	scanf("%d",&a);
	list=NewNode(a);
	ptr=list;

	while(n-- > 1)
	{
		scanf("%d",&a);
		Node *node=NewNode(a);
		ptr->next=node;
		ptr=ptr->next;
	}

	return list;
}

void Display(Node *list){

	if(!list) return ;
	
	printf("LINKED LIST : ");
	while(list)
	{
		printf("%d ",list->val);
		list=list->next;
	}
	printf("\n");
}

Node *AddBegin(Node *list,int data){
	Node *node=NewNode(data);
	node->next=list;
	return node;
}

Node *AddEnd(Node *list,int data){

	Node *ptr,*prev;
	ptr=list;
	prev=NULL;

	while(ptr)
	{
		prev=ptr;
		ptr=ptr->next;
	}

	Node *node=NewNode(data);
	prev->next=node;

	return list;

}

Node *Insert(Node *list,int data,int pos){

	if(list==NULL){
		return NewNode(data);
	}

	if(pos==0){
		list=AddBegin(list,data);
		return list;
	}

	Node *ptr,*prev;
	ptr=list;
	prev=NULL;
	while(pos-->0){
		prev=ptr;
		ptr=ptr->next;
	}

	Node *node= NewNode(data);
	prev->next=node;
	node->next=ptr;

	return list;
}

Node *DeleteBegin(Node *list){

	if(list==NULL)return NULL;

	Node* ptr=list;
	list=list->next;
	free(ptr);

	return list;
}

Node *Delete(Node *list,int pos){

	if(list==NULL) return NULL;

	//addition
	if(list->next==NULL)
		return NULL;

	Node *ptr,*prev;
	ptr=list;
	prev=NULL;
	while(pos-- >0)
	{
		prev=ptr;
		ptr=ptr->next;
	}

	if(ptr==NULL)
		return list;
	else{
		prev->next=ptr->next;
		free(ptr);
		return list;

	}

}
int main(){

	Node *list;
	list=input();
	Display(list);

	printf("Add at Beginnning : %d \n",-6);
	list=AddBegin(list,-6);
	Display(list);

	printf("Add at End : %d \n",-90);
	list=AddEnd(list,-90);
	Display(list);

	printf("Insert %d at Position %d \n",10,3);
	list=Insert(list,10,3);
	Display(list);

	printf("Delete Node at Position %d \n",2);
	list=Delete(list,2);
	Display(list);

	return 0;
}

