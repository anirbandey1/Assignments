#include <iostream>
#include <stdio.h>
using namespace std;

class Student{
char *name;
public:
	Student(){
		name=new char[20];
		inputName();
	}
 
	void inputName(){
		cout<<"Enter Name : "<<endl;
 		scanf("%[^\n]%*c",name);
	}
	virtual void disp(){
		cout<<"Name : ";
		cout<<name<<endl;
	}

};

class Engineering:public Student{
public:
	void disp(){
		this->Student::disp();
		cout<<"I am  an Engineering student"<<endl;
	}
	
};

class Medicine:public Student{
public:
	void disp(){
		this->Student::disp();
		cout<<"I am a Medical Student"<<endl;
	}
};

class Science:public Student{
public:
	void disp(){
		this->Student::disp();
		cout<<"I am a Science student"<<endl;
	}

};

int main(){


	Student *st[4];
	st[0]=new Student();
	st[1]=new Engineering();
	st[2]=new Medicine();
	st[3]=new Science();
	
	for(int i=0;i<4;i++)
	{
		st[i]->disp();
	}

	return 0;

}
