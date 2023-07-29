#include <iostream>
using namespace std;

inline int add(int a,int b,int c){
	return (a+b+c);
}

int main(){

	int a,b,c,sum;
	cout<<"Enter three numbers : ";
	cin>>a>>b>>c;

	sum=add(a,b,c);
	cout<<"Sum = "<<sum<<endl;

	return 0;
}
