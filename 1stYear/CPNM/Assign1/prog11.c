#include <stdio.h>
#include <stdlib.h>
#define n 3
void inputMatrix(int A[n][n])
{
	int w;
	printf("\n Enter the Matrix of Order %dx%d \n",n,n);

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

void AddMatrix(int A[n][n],int B[n][n],int C[n][n])
{
        printf("\n");

        int i,j;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                       	C[i][j] = A[i][j] + B[i][j];

                }         
        }
}

void SubtractMatrix(int A[n][n],int B[n][n],int C[n][n])
{
        printf("\n");

        int i,j;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {	
                        C[i][j] = A[i][j] - B[i][j];
                }      
        }
}

void ProductMatrix(int A[n][n], int B[n][n], int C[n][n])
{
	int i,j,k;

          for(i=0;i<n;i++)
          {
                  for(j=0;j<n;j++)
                  {
			C[i][j]=0;
                  	for(k=0;k<n;k++){
			        C[i][j] += A[i][k] * B[k][j];
			}
                  }
          }
}

int main(){

	int A[n][n];
	int B[n][n];
	int C[n][n];

	printf("\nEnter the 1st matrix : \n");
	inputMatrix(A);
	printf("\nEnter the 2nd matrix : \n");
	inputMatrix(B);

	printf("Addition Matrix : \n");
	AddMatrix(A,B,C);
	printMatrix(C);	

	printf("Subtract Matrix : \n");
	SubtractMatrix(A,B,C);
	printMatrix(C);

	printf("Product Matrix : \n");
	ProductMatrix(A,B,C);
	printMatrix(C);
}
