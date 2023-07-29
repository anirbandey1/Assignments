#include <iostream>
using namespace std;

class Complex{
	int re,im;
public:
	Complex( int real = 0, int imag = 0 ){
		this->re=real;
		this->im=imag;
	}

	friend ostream & operator << (ostream &os, const Complex &ob){
		os<< ob.re <<" + "<< ob.im <<"i";
		return os;
	}
};

namespace ns1{
	template<class T>
	void swap(T &ob1,T &ob2){
		T ob3=ob1;
		ob1=ob2;
		ob2=ob3;
	}
}



int main(){

	int a=2,b=4;
	ns1::swap(a,b);
	cout<< a <<endl;
	cout<< b <<endl;

	Complex cn1(2,3), cn2(5,6);
	ns1::swap(cn1,cn2);
	cout<< cn1 <<endl;
	cout<< cn2 <<endl;

	// char *str1 = "hello";
	// char *str2 = "world";
	// char *str3 = swap(str1, str2);
	// cout << str3;

	return 0;
}

