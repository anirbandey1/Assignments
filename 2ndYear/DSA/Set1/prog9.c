#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int row, col,ind, data;
} Node;

typedef struct Matrix
{
    int size, rows, cols;
    Node *a;
} Matrix;

Node *newNode(int x, int y, int z,int cols)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->row = x;
    node->col = y;
    node->ind= x*cols+y;
    node->data = z;
    return node;
}

Matrix *newMatrix(int n, int x, int y)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->size = n;
    m->a = (Node *)malloc(n * sizeof(Node));
    m->rows = x;
    m->cols = y;
}

Matrix *fillMatrix(int n, int rows, int cols)
{

    Matrix *m = newMatrix(n, rows, cols);
    int i, x, y, z;
    for (i = 0; i < n; i++)
    {
        printf("Enter Row,Column,Data : ");
        scanf("%d%d%d", &x, &y, &z);
        m->a[i] = *newNode(x, y, z,cols);
    }
    return m;
}

void printMatrix(Matrix *m)
{
    int i = 0, n = m->size;

    printf("Sparse Matrix :- \n");
    for (i = 0; i < n; i++)
    {
        printf("Index = %d, Row = %d, Column = %d, Data = %d \n",m->a[i].ind, m->a[i].row, m->a[i].col, m->a[i].data);
    }
}

int main()
{

    Matrix *m;
    int n, rows, cols;
    printf("Enter the Size of the Sparse Matrix : ");
    scanf("%d", &n);
    printf("Enter the number of Rows and Columns : ");
    scanf("%d%d", &rows, &cols);

    printf("Enter the Sparse Matrix :- \n");
    m = fillMatrix(n, rows, cols);
    printf("The Sparse Matrix :- \n");
    printMatrix(m);

    return 0;
}

/*
	Conversion formula

	index = row*cols+col;
	
	col = index % cols;
	row = index / cols;
*/
