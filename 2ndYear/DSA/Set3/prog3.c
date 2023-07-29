#include <stdio.h>
#include <stdlib.h>
//This is the code for bst

//Global veriables 
int index=0;

typedef struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;


int search(TreeNode *root,int key);


TreeNode* newTreeNode(int data)
{
	TreeNode *node= (TreeNode*)malloc(1*sizeof(TreeNode));

	if(NULL==node){
		printf("Stack Overflow : Memory could not be allocated for the node");
		return NULL;
	}
	node->val=data;
	node->left=NULL;
	node->right=NULL;

	return node;
}

void preorder(TreeNode*node){

	if(NULL==node) return;

	printf("%d ",node->val);
	preorder(node->left);
	preorder(node->right);
}

void preorderPrint(TreeNode* root){
	if(NULL==root){
		printf("The root of the node is NULL \n");
		return;
	}

	printf("Preorder Traversal : ");
	preorder(root);
	printf("\n");
}

void inorder(TreeNode*node){

	if(NULL==node) return;

	inorder(node->left);
	printf("%d ",node->val);
	inorder(node->right);
}

void inorderPrint(TreeNode* root){
	if(NULL==root){
		printf("The root of the node is NULL \n");
		return;
	}

	printf("Inorder Traversal : ");
	inorder(root);
	printf("\n");
}


void postorder(TreeNode*node){

	if(NULL==node) return;

	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->val);
}

void postorderPrint(TreeNode* root){
	if(NULL==root){
		printf("The root of the node is NULL \n");
		return;
	}

	printf("Postorder Traversal : ");
	postorder(root);
	printf("\n");
}

int count(TreeNode*node){
	if(NULL==node){
		return 0;
	}

	return 1 + count(node->left) + count(node->right);
}

void fillInorder(TreeNode*node,int in[],int i)
{
	if(NULL==node){
		return ;
	}

	fillInorder(node->left,in,i);


}

void inorderUtil(TreeNode*node,int nodes[]){

	if(NULL==node){
		return;
	}

	inorderUtil(node->left,nodes);
	nodes[index++]=node->val;
	inorderUtil(node->right,nodes);

}
void inorderSucPre(TreeNode*root,int key){

	if(NULL==root){
		printf("Root of the BST is NULL \n");
		return;
	}

	if(search(root,key)==0){
		printf("%d is Not Present in the BST \n",key);
		return ;
	}

	int n=count(root);
	
	int nodes[n];
	index=0;
	inorderUtil(root,nodes);

	int i=0;
	printf("Inorder Successor and Predecessor \n");
	for(i=0;i<n;i++)
	{
		if(nodes[i]==key) break;
		//printf("%d ",nodes[i]);
	}

	if(i>0){
		printf("Inorder Predecessor is %d \n",nodes[i-1]);
	}
	if(i<n-1){
		printf("Inorder Successor is %d \n",nodes[i+1]);
	}
	printf("\n");
}


int search(TreeNode *root,int key){

	if(root==NULL)return 0;

	TreeNode*cur=root;
	while(cur)
	{
		if(key==cur->val){
			return 1;
		}
		else if(key<cur->val){
			cur=cur->left;
		}
		else{
			cur=cur->right;
		}
	}

	return 0;


}	
TreeNode* insert(TreeNode*root,int key)
{
	TreeNode *node= newTreeNode(key);
	if(NULL==root){
		return node;
	}

	TreeNode*cur,*prev;
	prev=NULL;
	cur=root;

	while(cur)
	{
		prev=cur;
		if(key==cur->val){
			return root;
			// element is already present so no need to insert it in the array
		}
		else if(key<cur->val){
			cur=cur->left;
		}
		else{
			cur=cur->right;
		}

	}
	
	if(key<prev->val){
		prev->left= node;
	}
	else{
		prev->right= node;
	}
	return root;

}


TreeNode * insertMany(TreeNode *root)
{

	int i,n,*arr ;
	printf("Enter the number of elements to be inserted : ");
	scanf("%d", &n);

	if(n<=0) return root;

	arr = calloc(n,sizeof(int));

	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", arr+i);
	}

	for(i=0;i<n;i++)
	{
		root = insert(root,arr[i]);
	}

	return root;

}

/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
TreeNode* minValueNode(TreeNode* node)
{
    TreeNode* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
TreeNode* deleteNode(TreeNode* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->val)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        TreeNode* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->val = temp->val;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
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

void prompt(){

	printf("Enter 1 to print the Number of Nodes \n");
	printf("Enter 2 to print the Preorder Traversal \n");
	printf("Enter 3 to print the Inorder Traversal \n");
	printf("Enter 4 to print the Postorder Traversal \n");
	printf("Enter 5 to Insert an element \n");
	printf("Enter 6 to Search for an element \n");
	printf("Enter 7 to Print the Inorder Successor and Predecessor of an element \n");
	printf("Enter 8 to Delete an Element \n");
	printf("Enter 9 to Insert multiple elements \n");	
	printf("Enter 10 to Exit the Program \n");	

}


int main(){

/*
	TreeNode *root=newTreeNode(0);
	TreeNode *n1=newTreeNode(1);
	TreeNode *n2=newTreeNode(2);
	TreeNode *n3=newTreeNode(3);
	TreeNode *n4=newTreeNode(4);
	TreeNode *n5=newTreeNode(5);
	TreeNode *n6=newTreeNode(6);
	TreeNode *n7=newTreeNode(7);
	TreeNode *n8=newTreeNode(8);

	root->left=n1;
	root->right=n2;

	n1->left=n3;
	n1->right=n4;
	n2->left=n5;
	n2->right=n6;

	n3->left=n7;
	n3->right=n8;
*/
/*
	TreeNode *root=NULL;
	int i=0,n=5;
	int temp;
	for(i=1;i<n;i++){
		scanf("%d",&temp);
		root = insert(root,temp);
	}
	//insert(root)
	preorderPrint(root);
	inorderPrint(root);
	postorderPrint(root);

*/

	printf("\nBinary Search Tree \n\n");

	TreeNode* root=NULL;
	
	int choice=-1;
	int data=-1;
	int temp=-1;

	do{
		prompt();
		choice=getChoice();
	
		switch(choice)
		{
						
			case 1:
				temp=count(root);
				printf("Count of nodes : %d \n",temp);
				break;
			case 2:
				preorderPrint(root);
				break;
			case 3:
				inorderPrint(root);
				break;
			case 4:
				postorderPrint(root);
				break;
			case 5:	
				data=getData();
				root=insert(root,data);
				break;
			case 6:
				data=getData();
				if(search(root,data)==1){
					printf("%d is PRESENT in the BST \n",data);
				}else{
					printf("%d is NOT PRESENT in the BST \n",data);
				}
				break;
			case 7:
				data=getData();
				inorderSucPre(root,data);
				break;
			case 8:
				data=getData();
				root = deleteNode(root,data);
				break;
			case 9:
				root = insertMany(root);
				break;
			case 10:
				exit(0);
				break;

			default:
				printf("Please enter a Valid Choice \n");
				break;
		}

	}while(choice!=10);

	return 0;
}
