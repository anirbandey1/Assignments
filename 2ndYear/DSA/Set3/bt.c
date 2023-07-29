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





TreeNode* insertNode(TreeNode* node, int data) {
    if (node == NULL) {
        return newTreeNode(data);
    } else {
        if (data <= node->val) {
            node->left = insertNode(node->left, data);
        } else {
            node->right = insertNode(node->right, data);
        }
        return node;
    }
}




TreeNode* inputTree(){



    TreeNode* root = NULL;
    int data;

    printf("Enter values for the binary tree, enter -1 to stop: \n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        root = insertNode(root, data);
    }

	return root;

};

int main(){


	TreeNode* root=NULL;
	root=  inputTree();
	





	return 0;
}
