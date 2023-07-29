#include <iostream>
//#include <stdlib.h>
using namespace std;

class A{
	int a;
public:
	A(int x=0):a(x){}

	void *operator new (size_t sz){
		//void *temp = malloc(sz);

		// void *temp = ::new int[sz];
		void *temp = ::operator new (sz);

		char ch='0';
		for(int i=0;i<sz;i++){
			((char*)temp)[i]=ch;
		}

		return temp;
	}

	void operator delete(void *ptr){
		if(ptr){
			cout<<"Hi"<<endl;
			::delete(ptr);
		}

	}

};

int main(){

	A *ptr= new A(23);
	delete(ptr);

	return 0;
}
