#include <iostream>
using namespace std;

class Complex{
	float x,y;
	
public:
	Complex(float a=0,float b=0){
		x=a;
		y=b;
	}
	float getReal(){
		return x;
	}
	float getImg(){
		return y;
	}
	void setReal(float a){
		x=a;
	}
	void setImg(float b){
		y=b;
	}
	void display(){
		cout<<"Complex no. : "<<x<<" + "<<y<<"i"<<endl;
	}
	Complex add(Complex ob1,Complex ob2){
		Complex ob3;
		ob3.setReal(ob1.getReal()+ob2.getReal());
		ob3.setImg(ob1.getImg()+ob2.getImg());
		return ob3;
	}
};

int main(){
	Complex ob1(3,4), ob2(-1,2);
	Complex ob3=ob1.add(ob1,ob2);
	cout<<"Addition of ";
	ob1.display();
	cout<<" and ";
	ob2.display();
	cout<<" is ";
	ob3.display();
	cout<<endl; 

	return 0;
}
