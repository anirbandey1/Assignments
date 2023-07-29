#include <stdio.h>
#include <stdlib.h>
#define n 3
void inputMatrix(int A[n][n])
{
        int w;
        printf("\nEnter the Matrix of Order %dx%d \n",n,n);

        int i,j;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&w);
                         A[i][j]=w;

                }

        }
        printf("\n");

}

void printMatrix(int A[n][n])
{
        printf("\n");

        int i,j;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        printf("%d ",A[i][j]);

                }
                printf("\n");
        }
        printf("\n");
}

void TransposeMatrix(int A[n][n],int B[n][n]){

	int i,j;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        B[j][i]=A[i][j];

                }
        }
}

int main(){

        int A[n][n];
        int B[n][n];

        printf("\nEnter the Matrix : \n");
        inputMatrix(A);
        
        printf("Transpose of the Matrix : \n");
        TransposeMatrix(A,B);
        printMatrix(B);

        return 0;
}
             
