#include <iostream>
using namespace std;

void swap(int &x,int &y){
	int temp;
	temp=x,x=y,y=temp;
}

int main()
{
	int a,b;
	cout<<"Enter two numbers : ";
	cin>>a>>b;

	swap(a,b);
	cout<<"After swapping,"<<endl;
	cout<<"The two numbers are : "<<a<<"  "<<b<<endl;

	return 0;
}
