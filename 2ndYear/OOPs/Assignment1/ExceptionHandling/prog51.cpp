#include <iostream>
using namespace std;


int main(){

	int x;
	cout<<"Enter a number : "<<endl;
	cin>>x;

	try{

		if(x<0){
			throw x;
		}else if(x>0){
			throw "Number is positive";
		}else{
			cout<<"Number is zero : No error";
		}
	}
	catch(int y){
		cout<<"The number is negative";

	}
	catch(const char* str){
		cout<<str;
	} 


};
