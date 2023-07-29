#include <iostream>
#include <cmath>
using namespace std;

class Point{
	float x,y,z;
	
public:
	Point(float a, float b,float c){
		x=a;
		y=b;
		z=c;
	}
	void display(){
		cout<<"Point : ("<<x<<","<<y<<","<<z<<")"<<endl;
	}
	float dist(Point ob1,Point ob2){
		float d= pow(ob1.x-ob2.x,2)+pow(ob1.y-ob2.y,2)+pow(ob1.z-ob2.z,2);
		d=sqrt(d);
		return d;
	}
};

int main(){
	Point Pt1(1,1,1),Pt2(2,2,2);
	float dis=Pt1.dist(Pt1,Pt2);

	cout<<"Distance between ";
	Pt1.display();
	cout<<" and ";
	Pt2.display();
	cout<<" is "<<dis<<endl;

	return 0;
}
