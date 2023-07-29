#include <stdio.h>
#include <stdlib.h>

void sort(int A[],int n){

	int i,j,pos,temp;
	
	for(i=0;i<n-1;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[pos])
				pos=j;	
		}

		temp=A[i],A[i]=A[pos],A[pos]=temp;
	}
}

int main(){

        int n,*A;

        printf("Enter the LENGTH of array = ");
        scanf("%d",&n);

        A= (int *)calloc(n,sizeof(int));

        printf("Enter the %d elements : ",n);
        int i;
        for(i=0;i<n;i++)
        {
                scanf("%d",A+i);
        }

   	sort(A,n);
	
	printf("SORTED array : ");
	for(i=0;i<n;i++)
        {
                printf("%d ",A[i]);
        }
	printf("\n");

        return 0;
}

