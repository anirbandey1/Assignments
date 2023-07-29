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
Matrix *addMatrix(Matrix *m1, Matrix *m2)
{
    int n1, n2, n3, rows, cols;

    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        printf("Incompatiles Matrices : Addition not Possible \n");
        return NULL;
    }

    n1 = m1->size;
    n2 = m2->size;
    n3 = n1 + n2;

    Matrix *m3 = newMatrix(n3, rows, cols);
    int i, j, k;
    i = j = k = 0;

    int *vis = (int *)calloc(n2, sizeof(int));
    for (i = 0; i < n1; i++)
    {
        m3->a[k].row = m1->a[i].row;
        m3->a[k].col = m1->a[i].col;
        m3->a[k].data = m1->a[i].data;
        for (j = 0; j < n2; j++)
        {
            if (m1->a[i].row == m2->a[j].row && m1->a[i].col == m2->a[j].col)
            {
                vis[j] = 1;
                m3->a[k].data += m2->a[j].data;
            }
        }
        k++;
    }

    for (j = 0; j < n2; j++)
    {
        if (!vis[j])
        {
            m3->a[k] = m2->a[j];
            k++;
        }
    }

    m3->size = k;
    m3->a = realloc(m3->a, k * sizeof(Node));
    return m3;
}
int main()
{

    Matrix *m1, *m2, *m3;
    int n1, n2, rows, cols;
    printf("Enter the Sizes of 2 Sparse Matrices : ");
    scanf("%d%d", &n1, &n2);
    printf("Enter the number of Rows and Columns : ");
    scanf("%d%d", &rows, &cols);

    printf("Enter the First Sparse Matrix :- \n");
    m1 = fillMatrix(n1, rows, cols);
    printf("Enter the Second Sparse Matrix :- \n");
    m2 = fillMatrix(n2, rows, cols);

    printf("First Matrix :- \n");
    printMatrix(m1);
    printf("Second Matrix :- \n");
    printMatrix(m2);

    m3 = addMatrix(m1, m2);

    printf("Addition Matrix :- \n");
    printMatrix(m3);

    return 0;
}