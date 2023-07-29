#include <iostream>
using namespace std;

class INT{
	int i;
public:
	INT(int a):i(a){}
	~INT(){}
}


int main(){
	int x=3;
	INT y=x;
	y++=++y;
	x=y;

	return 0;
}
