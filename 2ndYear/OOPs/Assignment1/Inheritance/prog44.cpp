#include <iostream>
#include <cmath>
#define PI 3.1415
using namespace std;

class Shape{
public:
	Shape(){;}
	virtual void disp()=0;
};
class TwoDShape:virtual public Shape{
public:
	TwoDShape(){;}
	virtual void disp()=0;
	virtual float getArea()=0;


};
class ThreeDShape:virtual public Shape{
public:
	ThreeDShape(){;}
	virtual void disp()=0;
	virtual float getArea()=0;
	virtual float getVolume()=0;

};

class Circle:virtual public TwoDShape{
	float r;
public:
	Circle(float r){
		this->r=r;
	}
	float getArea(){
		return PI*r*r;		
	}
	void disp(){
		cout<<"Circle"<<endl;
		cout<<"Radius : "<<r<<endl;
		cout<<"Area : "<<getArea()<<endl;
		cout<<endl;
	}

};

class Triangle:virtual public TwoDShape{
	float a,b,c;
public:
	Triangle(float a,float b,float c){
		this->a=a;
		this->b=b;
		this->c=c;
	}
	float getArea(){
		float s=(a+b+c)/2;
		return  sqrt( s*(s-a)*(s-b)*(s-c) );
	}
	 void disp(){
                cout<<"Triangle"<<endl;    
                cout<<"Sides : "<<a<<", "<<b<<", "<<c<<endl;
                cout<<"Area : "<<getArea()<<endl;
                cout<<endl;
        }


};

class Ellipse:virtual public TwoDShape{
	float a,b;
public:
	Ellipse(float a,float b){
		this->a=a;
		this->b=b;
	}
	float getArea(){
		return PI*a*b;
	}
	void disp(){
                cout<<"Ellipse"<<endl;    
                cout<<"Semi-Major axis : "<<a<<endl;
		cout<<"Semi-Minor axis : "<<b<<endl;
                cout<<"Area : "<<getArea()<<endl;
                cout<<endl;
        }


};

class Sphere:virtual public ThreeDShape{
	float r;
public:
	Sphere(float r){
		this->r=r;
	}
	float getArea(){
		return 4*PI*r*r;
	}
	float getVolume(){
		return (4.0/3.0)*PI*r*r*r;
	}
	void disp(){
                cout<<"Sphere"<<endl;    
                cout<<"Radius : "<<r<<endl;
                cout<<"Area : "<<getArea()<<endl;
                cout<<"Volume : "<<getVolume()<<endl;
                cout<<endl;
        }


};

class Cube:virtual public ThreeDShape{
        float a;
public:
        Cube(float a){
                this->a=a;
        }
	float getArea(){
		return 6*a*a;
	}
	float getVolume(){
		return a*a*a;
	}
        void disp(){       
                cout<<"Cube"<<endl;
                cout<<"Side : "<<a<<endl;
                cout<<"Area : "<<getArea()<<endl;
                cout<<"Volume : "<<getVolume()<<endl;
                cout<<endl;
        }
};

int main(){

	Shape *ob[5];
	ob[0]=new Circle(4);
	ob[1]=new Triangle(2,3,4);
	ob[2]=new Ellipse(5,6);
	ob[3]=new Sphere(4);
	ob[4]=new Cube(3);

	for(int i=0;i<5;i++)
	{
		ob[i]->disp();
	}

	return 0;
}
