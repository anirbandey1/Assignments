
#include <stdio.h>
#include <stdlib.h>
//This is the code for bst

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

/* Function prototypes */
void printCurrentLevel(TreeNode* root, int level);
int height(TreeNode* node);
TreeNode* newNode(int data);
 
/* Function to print level order traversal a tree*/
void printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
/* Print nodes at a current level */
void printCurrentLevel(TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->val);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(TreeNode* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void levelorderPrint(TreeNode* root)
{

	printf("Level Order Traversal : ");
	printLevelOrder(root);
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



int search(TreeNode *root,int key){

	if(root==NULL)return 0;

	TreeNode*cur=root;
	if(key==cur->val) return 1;
    if (search(root->left,key) == 1) return 1;
    if (search(root->right,key) ==1) return 1;

	return 0;


}	



TreeNode* insertNode(){

	int data;
	scanf("%d",&data);

	if(data==-1) return NULL;

	TreeNode* node = newTreeNode(data);

	node->left = insertNode();
	node->right = insertNode();

	return node;

}

TreeNode* inputBT()
{
    TreeNode* root = NULL;

    printf("Enter values for the binary tree, enter -1 to stop: \n");
	root = insertNode();

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
	printf("Enter 5 to print the Levelorder Traversal \n");
	printf("Enter 6 to Count number of elements \n");
	printf("Enter 7 to Search for an element \n");
	printf("Enter 8 to Insert multiple elements \n");	
	printf("Enter 10 to Exit the Program \n");	

}


int main(){


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
				levelorderPrint(root);
				break;
			case 6:	
				temp = count(root);
				printf("Count of nodes : %d \n",temp);
				break;
			case 7:
				data=getData();
				if(search(root,data)==1){
					printf("%d is PRESENT in the Binary Tree \n",data);
				}else{
					printf("%d is NOT PRESENT in the Binary Tree \n",data);
				}
				break;
			case 8:
                root = inputBT();
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
