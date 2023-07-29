#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int row, col, data;
} Node;

typedef struct Matrix
{
    int size, rows, cols;
    Node *a;
} Matrix;

Node *newNode(int x, int y, int z)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->row = x;
    node->col = y;
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
        m->a[i] = *newNode(x, y, z);
    }
    return m;
}

void printMatrix(Matrix *m)
{
    int i = 0, n = m->size;

    printf("Sparse Matrix :- \n");
    for (i = 0; i < n; i++)
    {
        printf("Row = %d, Column = %d, Data = %d \n", m->a[i].row, m->a[i].col, m->a[i].data);
    }
}

void nonZeroInRow(Matrix *m)
{
    int i, j, *row;
    row = (int *)calloc(m->rows + 1, sizeof(int));
    for (i = 0; i < m->size; i++)
    {
        j = m->a[i].row;
        row[j]++;
    }

    printf("No. of non-zero elements in :- \n");
    for (i = 1; i <= m->rows; i++)
    {
        printf("Row %d is %d \n", i, row[i]);
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
    nonZeroInRow(m);

    return 0;
}