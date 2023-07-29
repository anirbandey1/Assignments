#include <iostream>
using namespace std;

class Rectangle{
	float l,b;
public:
	Rectangle(float x,float y){
		l=x;
		b=y;		
	}
	float area(){
		return l*b;
	}
	void display(){
		cout<<"Rectangle : "<<endl;
		cout<<"Length = "<<l<<endl;
		cout<<"Breadth = "<<b<<endl;
		cout<<"Area = "<<area()<<endl;	
		cout<<endl;
	}


};

int main(){

	Rectangle ob1(1,3),ob2(2,4),ob3(5,6),ob4(1.5,3.4);
	ob1.display();
	ob2.display();
	ob3.display();
	ob4.display();

	return 0;
}
