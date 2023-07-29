#include <stdio.h>

int main()
{

	float b;

	printf("Enter the Basic Salary : ");
	scanf("%f",&b);

	float dearness,rent,gross;
	dearness = b*0.6;
	rent = b*0.15;
	gross = b + dearness + rent;
	
	printf("The Gross Salary : %0.2f \n",gross);

	return 0;
}
