#include <iostream>
using namespace std;

class Integer{
	int x; //stores a integer for this class	
public:
	Integer(int val=0){
		x=val;
	}

	Integer operator+(const Integer &ob){
		Integer temp;
		temp.x=x+ob.x;
		return temp;

	}

	Integer operator++(int){
		//the argument acts as a flag it has no other significance
		Integer t;
		t.x=x++;
		return t;

		//the above lines will call the constructor an extra time 
		//this inefficiency can be avoided by using the 'this' object 

	}
	operator int (){
		return x;
	}

	friend ostream & operator << (ostream &os,const Integer &ob);
	
	

};

	ostream & operator << (ostream &os,const Integer &ob){
		os<<ob.x;
		return os;
	}


int main(){

	Integer a=4,b=a,c;
	c=a+b++;
	int i=a;
	cout<<a<<b<<c;

	return 0;
}
