#include <stdio.h>

int sumOfDigit(int n)
{

	int s=0;

	while(n>0)
	{
		s+=n%10;
		n/=10;
	}

	return s;
}


int main()
{
	
	int a;
	printf("Enter the number : ");
	scanf("%d",&a);
	printf("Sum Of Digits : %d \n",sumOfDigit(a));

}
