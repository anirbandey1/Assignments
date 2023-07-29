#include <iostream>
using namespace std;

class INT{
	int i;
public:
	 INT(int a):i(a){}
	 
	//~INT(){}



	//the constructor and destructor above are part of the question
	operator int();
	INT operator++();
	INT operator++(int);
	INT& INT::operator=(const INT &ob){
};


INT::operator int(){
	return this->i;

}
// preincrement operator
INT INT::operator++(){

	INT t(0);
	t.i=++i;
	return t;
}

//post increment operator
INT INT::operator++(int){
	INT t(0);
	t.i=i++;
	return t;



}


int main(){
	int x=3;
	INT y=x;
	y++=++y;
	x=y;

	return 0;
}
