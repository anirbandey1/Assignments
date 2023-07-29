#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode* newTreeNode(int data)
{
	TreeNode *node= (TreeNode*)malloc(1*sizeof(TreeNode));
	node->val=data;
	node->left=NULL;
	node->right=NULL;
}

void preorder(TreeNode*node){

	if(node==NULL) return;

	printf("%d ",node->val);
	preorder(node->left);
	preorder(node->right);
}

void preorderPrint(TreeNode* root){
	if(root==NULL){
		printf("The root of the node is NULL");
		return;
	}

	printf("Preorder Traversal : ");
	preorder(root);
	printf("\n");
}

void inorder(TreeNode*node){

	if(node==NULL) return;

	inorder(node->left);
	printf("%d ",node->val);
	inorder(node->right);
}

void inorderPrint(TreeNode* root){
	if(root==NULL){
		printf("The root of the node is NULL");
		return;
	}

	printf("Inorder Traversal : ");
	inorder(root);
	printf("\n");
}


void postorder(TreeNode*node){

	if(node==NULL) return;

	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->val);
}

void postorderPrint(TreeNode* root){
	if(root==NULL){
		printf("The root of the node is NULL");
		return;
	}

	printf("Postorder Traversal : ");
	postorder(root);
	printf("\n");
}


int main(){

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

	preorderPrint(root);
	inorderPrint(root);
	postorderPrint(root);

	return 0;
}
