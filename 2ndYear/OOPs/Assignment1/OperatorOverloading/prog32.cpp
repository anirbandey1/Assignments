#include <iostream>
using namespace std;

class Quadratic{
	float a,b,c;
	// ax^2+bx+c=0
public:
	Quadratic(float a,float b=0,float c=0)
	{
		this->a=a;
		this->b=b;
		this->c=c;
	}
	Quadratic operator + (const Quadratic &ob2)
	{
		Quadratic ob3;
		ob3.a=a+ob2.a;
		ob3.b=b+ob2.b;
		ob3.c=c+ob3.c;
		return ob3;
	}
	float compute(float x){
		return a*x*x+b*x+c;
	}	

	friend ostream & operator <<(ostream &,const Quadratic &);
	friend istream & operator >>(instream &,Quadratic &);
		
};


ostream & operator <<(ostream &os,const Quadratic &ob){
	os<<"Quadratic Polynomial is : "<<ob.a<<"x^2 + "<<ob.b<<"x + "<<ob.c<<endl;
	return os;
}

istream & operator >>(instream &in,Quadratic &ob){
	cout<<"Enter the coefficient of x^2 : ";
	in>>ob.a;
	cout<<"Enter the coefficient of x^1 : ";
	in>>ob.b;
	cout<<"Enter the constant term : ";
	in>>ob.c;

	return in;

}


int main(){

	Quadratic q(1);
	cin>>q;
	cout<<q;


	return 0;
}


