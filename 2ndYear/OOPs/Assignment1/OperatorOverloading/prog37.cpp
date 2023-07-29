#include <iostream>
using namespace std;

class Index{

	int val;
public:

	Index(int data){
		val=data;
	}

	operator int(){
		return val;
	}

	int get(){
		return val;
	}
};

class Integer{
	int val;
public:

	Integer(){
		val=0;		
	}

	Integer (Index ob){
		val=ob.get();
	}
};

int main(){

	Index in(4),out(10);
	int x=in;
	int y=in+out;
	in=2;
	Integer i;
	i=in;


	return 0;
	
}
