#include <iostream>
using namespace std;

int add(int x,int y=0,int z=0){
	return (x+y+z);
}

int main()
{
	int a,b,c,sum=0;
	cout<<"Enter three variables : ";
	cin>>a>>b>>c;

	cout<<"With Three Variables"<<endl;
	sum=add(a,b,c);
	cout<<"Sum = "<<sum<<endl;

	cout<<"With TWo Variables"<<endl;
	sum=add(a,b);
	cout<<"Sum = "<<sum<<endl;

	cout<<"With One Variable"<<endl;
	sum=add(a);
	cout<<"Sum = "<<sum<<endl;

	return 0;
}
