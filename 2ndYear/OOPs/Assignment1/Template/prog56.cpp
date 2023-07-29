#include <iostream>
using namespace std;

class Complex{
	int re,im;

	int mag() const 
	{
		// square of magnitude
		// |z|^2
		return re*re + im*im;		
	}
public:
	Complex( int real = 0, int imag = 0 ){
		this->re=real;
		this->im=imag;
	}

	bool operator < (const Complex &ob) const
	{
		return this->mag() < ob.mag();
	}

	friend ostream & operator << (ostream &os, const Complex &ob){
		os<< ob.re <<" + "<< ob.im <<"i";
		return os;
	}
};

namespace ns1{
	template <class T>
	T max(const T &ob1, const T &ob2){
		T ob3;
		if (ob1<ob2){
			ob3 = ob2;
		}
		else{
			ob3 = ob1;
		}
		return ob3;

	}

}

// template <>
// Complex max(const Complex &ob1, const Complex &ob2){
// 	Complex ob3;
// 	if(ob1.mag() > ob2.mag()){
// 		ob3=ob1;
// 	}else{
// 		ob3=ob2;
// 	}
// 	return ob3;
// 
// }

// template <>
// char* max(const char* &str1, const char* &str2){
// 	char* str3;
// 	if(*str1 > *str2){
// 		str3=str1;	
// 	}else if(){
// 		str3=str2;
// 	}
// 	return str3;
// };

int main(){

	int a=2,b=4;
	int c= ns1::max(a,b);
	cout<< c <<endl;

	Complex cn1(2,3), cn2(5,6);
	Complex cn3= ns1::max(cn1,cn2);
	cout<< cn3 <<endl;

	// char *str1 = "hello";
	// char *str2 = "world";
	// char *str3 = max(str1, str2);
	// cout << str3;

	return 0;
}

