#include <stdio.h>

int sum(int n)
{

	int s=0;
	
	int i,j;
	for(i=1;i<=n;i++)
	{
		int fac=1,j=1;
	
		for(j=1;j<=i;j++)
		{
			fac*=j;
		}		

		s+= fac;
	}

	return s;
}


int main()
{
	int n;
	printf("Enter the number : ");
	scanf("%d",&n);

	printf("The Sum of Series is : %d \n",sum(n));

}
