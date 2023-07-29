class Base1{

};

class Base2{

};

class Derived:private Base1,private Base2{


};

int main(){
	Base1 *b1=new Base1();
	Base2 *b2=new Base2();
	Derived *d=new Derived();

	return 0;
}
