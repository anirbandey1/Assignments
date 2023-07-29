#include <stdio.h>
#include <stdlib.h>

int main(){

	int n, *A;
	
	printf("Enter the LENGTH of array = ");
	scanf("%d",&n);
	
	A= (int *)calloc(n,sizeof(int));

	printf("Enter the %d elements : ",n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",A+i);
	}

	int min=A[0],max=A[0];
	for(i=0;i<n;i++)
        {
                if(A[i]>max)
			max=A[i];

		if(A[i]<min)
			min=A[i];
        }

	printf("RANGE = %d \n",max-min);

	return 0;
}
