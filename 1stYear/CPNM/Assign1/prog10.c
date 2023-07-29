#include <stdio.h>
#include <stdlib.h>

void reverse(int A[],int n)
{
	int i,j,temp;
	for(i=0,j=n-1 ; i<j ; i++,j--)
	{
		temp=A[i],A[i]=A[j],A[j]=temp;
	}
}

int main()
{
	int *A, n;

	printf("Enter SIZE of array : ");
	scanf("%d",&n);

	A=(int *)calloc(n,sizeof(int));

	printf("Enter %d elements : ",n);

	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",A+i);
	}

	reverse(A,n);

	printf("The Reversed Array is : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");

	return 0;
}
