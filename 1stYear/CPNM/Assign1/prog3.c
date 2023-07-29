#include <stdio.h>

int main()
{

	int a1,b1,a,b;
	printf("Enter the two numbers : ");
	scanf("%d %d",&a1,&b1);

	a= a1>b1?a1:b1;
	b= a1>b1?b1:a1;
	
	printf("Fractional Value : %d %d/%d \n", a/b , a%b , b );
	float res = (float) a/b;
	printf("Real Value : %0.2f \n ",res);




	return 0;
}
