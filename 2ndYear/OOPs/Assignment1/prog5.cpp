#include <iostream>
#include <stdio.h>

using namespace std;


float CtoF(float C){

return (9*C)/5 + 32;

}

int main()
{

	cout<<"Conversion Table : "<<endl;
	for(float C=0.0f;C<=100;C++)
	{
		float F=CtoF(C);
		printf("%.3f degree Celsius = %.3f Farenheit \n",C,F);
	}

	return 0;
}
