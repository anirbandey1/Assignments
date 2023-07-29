#include <iostream>
#include <stdlib.h>
#define PI 3.1415
using namespace std;

class Shape2D{
public:
	Shape2D(){;}
	virtual float area()=0;
	virtual float perimeter()=0;
	virtual void disp()=0; 
};

class Circle: virtual public Shape2D{
	float r;
public:
	Circle(float r):Shape2D(){
		this->r=r;
	}
	float area(){
		return PI*r*r;
	}
	float perimeter(){
		return 2*PI*r;
	}
	void disp(){
		cout<<"Circle"<<endl;
                cout<<"Radius : "<<r<<endl;
                cout<<"Area : "<<area()<<endl;
                cout<<"Perimeter : "<<perimeter()<<endl;
		cout<<endl;
	}
};


class Rectangle:virtual public Shape2D{
	float l,b;
public:
	Rectangle(float l,float b):Shape2D(){
		this->l=l;
		this->b=b;
	}
	float area(){
		return l*b;
	}
	float perimeter(){
		return 2*(l+b);
	}
	void disp(){
		cout<<"Rectangle"<<endl;
		cout<<"Length : "<<l<<endl;
		cout<<"Breadth : "<<b<<endl;
		cout<<"Area : "<<area()<<endl;
		cout<<"Perimeter : "<<perimeter()<<endl;
		cout<<endl;
	}
};

int main(){

	Shape2D *ob[5];

	for(int i=0;i<3;i++){
		ob[i]=new Circle(i+2);
	}
	for(int i=3;i<5;i++){
		ob[i]=new Rectangle(i+3,i+5);
	}
	for(int i=0;i<5;i++){
		ob[i]->disp();
	}

	return 0;
}
