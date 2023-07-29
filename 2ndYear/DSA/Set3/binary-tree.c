#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    TreeNode* val;
    struct Node *next;
} Node;

typedef struct Stack
{
    int size;
    Node *top;
} Stack;

typedef struct TreeNode{
    int val;
    struct TreeNode *left,*right;
}TreeNode;

typedef struct BinaryTree{
    int size;
    TreeNode *root;
}BinaryTree;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(1 * sizeof(Node));
    if (node == NULL)
    {
        printf("STACK OVERFLOW \n");
        return NULL;
    }
    node->val = data;
    node->next = NULL;
}

Stack *newStack()
{
    Stack *st = (Stack *)malloc(1 * sizeof(Stack));
    if (st == NULL)
    {
        printf("STACK OVERFLOW \n");
        return NULL;
    }
    st->size = 0;
    st->top = NULL;
    return st;
}

void push(Stack *st, int data)
{
    if (st == NULL)
    {
        printf("No Stack Provided \n");
        return;
    }
    Node *node = newNode(data);

    node->next = st->top;
    st->top = node;
    st->size++;
}

int pop(Stack *st)
{
    if (st == NULL)
    {
        printf("No Stack provided \n");
        return -1;
    }
    if (st->top == NULL)
    {
        printf("Stack is Empty \n");
        return -1;
    }

    Node *node = st->top;
    int data = node->val;
    st->top = st->top->next;
    free(node);
    st->size--;
    return data;
}

int stackSize(Stack *st)
{
    if (st == NULL)
    {
        printf("No Stack Provided \n");
        return -1;
    }

    return st->size;
}
// Tree starts from  here



TreeNode *newTreeNode(int data)
{
    TreeNode *node = (TreeNode *)malloc(1 * sizeof(TreeNode));
    if (node == NULL)
    {
        printf("STACK OVERFLOW \n");
        return NULL;
    }
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

BinaryTree *newBinaryTree()
{
    BinaryTree *bt = (BinaryTree *)malloc(1 * sizeof(BinaryTree));
    if (bt == NULL)
    {
        printf("STACK OVERFLOW \n");
        return NULL;
    }

    bt->size = 0;
    bt->root = NULL;
    return bt;
}

BinaryTree *createBinaryTree()
{
    BinaryTree *bt= newBinaryTree();
}
void preorder(BinaryTree *bt)
{
    if (bt == NULL)
    {
        printf("No Binary Tree provided \n");
        return;
    }
    if (bt->size == 0)
    {
        printf("Binary Tree is empty \n");
        return;
    }

    printf("Preorder Traversal : ");

    Stack *st = newStack();
    push(st,bt->root);
    
    TreeNode *cur=NULL;
    while(stackSize(st)>0)
    {
        cur=pop(st);
        printf("%d ",cur->val);

        if(cur->left){
            push(st,cur->left);
        }
        if(cur->right){
            push(st,cur->right);
        }
    }
}
int treeSize(BinaryTree *bt)
{
    if (bt == NULL)
    {
        printf("No Binary Tree provided \n");
        return;
    }
    return bt->size;
}

int main()
{
    BinaryTree *bt= createBinaryTree();
    return 0;
}
