#include <stdio.h>
#include <string.h>

void swap(char **a,char **b)
{
	char *temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{

	char *a,*b;
	printf("Enter first string : ");
	scanf("%s",a);
	printf("Enter second string : ");
	scanf("%s",b);

	swap(&a,&b);
	printf("Character arrays are swapped \n");
	
	printf("First string : ");
	printf("%s \n",a);
	printf("Second string : ");
	printf("%s \n",b);	
	
	return 0;
}
