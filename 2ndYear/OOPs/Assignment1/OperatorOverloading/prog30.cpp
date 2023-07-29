#include <iostream>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Point{
	float x,y;
public:
	Point(float a=0,float b=0){
		x=a;
		y=b;
	}
	float operator - (Point const &obj){
		float dist=0;
		dist+= (x-obj.x)*(x-obj.x);
		dist+= (y-obj.y)*(y-obj.y);
		dist=sqrt(dist);
		return dist;
	}
	void display(){
		cout<< 	"( "<<x<<" , "<<y<<")"<<" )";
	}
};

int main(){

	Point Pt1(3,4) , Pt2(0,0);
	float dist= Pt1-Pt2;
	
	cout<<"Distance between ";
	Pt1.display();
	cout<<" and ";
	Pt2.display();
	cout<<" is "<<dist<<endl;



	return 0;
}
