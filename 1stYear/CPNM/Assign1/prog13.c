#include <stdio.h>

int main()
{

	int A[5];
	printf("Enter the 5 numbers : ");
	
	int i=0,sum=0,max=-1;
	for(i=0;i<5;i++)
	{
		scanf("%d",A+i);
		sum+=A[i];

		if(A[i]>max)
			max=A[i];
	}

	printf(" Sum = %d \n Max = %d \n",sum,max);

	return 0;

}
