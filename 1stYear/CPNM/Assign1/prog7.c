#include <stdio.h>

int Armstrong(int n)
{
	int s=0,k=n;

	while(k>0)
	{
		int d=k%10;
		s+=d*d*d;
		k/=10;
	}

	if(s==n)
		return 1;
	else 
		return 0;

}

int main()
{
	int i=1;

	for(i=1;i<=500;i++)
	{
		if(Armstrong(i))
			printf("%d \n",i);
	}

	return 0;
}
