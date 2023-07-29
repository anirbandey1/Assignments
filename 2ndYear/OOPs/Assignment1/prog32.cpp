#include <iostream>
using namespace std;

class Quadratic{
	float a,b,c;
	// ax^2+bx+c=0

	Quadratic(){
		this->a=this->b=this->c=0;
	}
	Quadratic(float a,float b,float c)
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
};

int main(){




	return 0;
}


