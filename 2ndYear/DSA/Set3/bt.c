#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *newTreeNode(int data){

	TreeNode *node = (TreeNode*)malloc(1*sizeof(TreeNode));
	node->val=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}


TreeNode* inputTree(){

	int m;
	printf("The size of input : ");
	scanf("%d",&m);


	printf("Enter the elements : ");
	int A=(int*)malloc(m*sizeof(int));
	int i=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",A+i);
	}





};

int main(){


	TreeNode* root=NULL;
	root=  inputTree();
	





	return 0;
}
