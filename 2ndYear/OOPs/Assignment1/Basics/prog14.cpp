#include <iostream>
using namespace std;

inline int add1(int a,int b,int c){
	return (a+b+c);
}

int add2(int a,int b,int c){
	return (a+b+c);
}

int main(){

	int a,b,c,sum;
	cout<<"Enter three numbers : ";
	cin>>a>>b>>c;

	
	cout<<"Using Inline Function"<<endl;
	sum=add1(a,b,c);
	cout<<"Sum = "<<sum<<endl;

	cout<<"Without Using Inline Function"<<endl;
	sum=add2(a,b,c);
	cout<<"Sum = "<<sum<<endl;

	return 0;
}
