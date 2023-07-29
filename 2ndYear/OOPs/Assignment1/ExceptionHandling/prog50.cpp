#include <iostream>
#include <stdexcept>
using namespace std;

int main(){

	cout<<"Enter two numbers : ";
	int a,b;
	cin>>a>>b;

	try{
		if(b==0){
			throw 32;
		}
		int c=a/b;
		cout<<"Result of division operator : "<<c<<endl;
	}
	catch(int y){
		cout<<"Cannot divide by zero"<<endl;
	};

	return 0;

}
