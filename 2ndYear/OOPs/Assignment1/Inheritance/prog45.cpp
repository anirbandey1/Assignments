#include <iostream>
#include <stdio.h>
using namespace std;


class Base{
	char *s;
		
public:
	Base(){	
		cout<<"Default Base constructor"<<endl;	
	}

	virtual void input(){
		cout<<"Enter a string : ";
	//	scanf("%[^\n]%*c",s);
		scanf("%s",s);
	}
	virtual void disp(){
		cout<<s<<endl;
	}

	 virtual ~Base(){
		cout<<"Virtual Destructor of Base "<<endl;
	}

};



class Child:public Base{
	int x;
public:
	Child(){
		cout<<"Default Child constructor"<<endl;
	}
	void input(){
		this->Base::input();
		cout<<"Enter a number"<<endl;
		char garbage;
		scanf("%c",&garbage);
		cin>>x;
	}
	void disp(){
		this->Base::disp();
		cout<<"The number is "<<x<<endl;
	}
	~Child(){
		cout<<"Child destructor"<<endl;
	}
	
};


int main(){

	Base *ob = new Child();
	ob->input();
	ob->disp();
	delete(ob);

	return 0;
}
