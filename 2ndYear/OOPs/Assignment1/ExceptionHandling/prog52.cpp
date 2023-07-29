#include <iostream>
using namespace std;

class A
{
	int a;
public:
	A(int x=0):a(x){}

	void throwError();


	class B
	{
		char *message;
	public:
		B( char* ch){
			message=ch;
		}
		void display(){
			cout<<"Error : "<< message <<endl;
		}
	};

};


void A::throwError(){
	throw B("This is the error message"); 
}

int main(){

	A ob1;
	
	try{
	ob1.throwError();

	}catch (A::B err){
		err.display();
	}

	return 0;
}
