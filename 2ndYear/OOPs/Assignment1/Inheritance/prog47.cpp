#include <iostream>
using namespace std;

class Person{
public:
	Person(){
		cout<<"Parameterless constructor of Person"<<endl;
	}
	void disp(){
		cout<<"Person"<<endl;
	}
};

class Employee:virtual public Person{
public:
	Employee(){
		cout<<"Parameterless constructor of Employee"<<endl;
	}
	void disp(){
		cout<<"Employee"<<endl;	
	}
};

class Student:virtual public Person{
public:
	Student(){
		cout<<"Parameterless constructor of Student"<<endl;
	}
	void disp(){
		cout<<"Student"<<endl;
	}
};

class Manager:public Employee,public Student{
public:
	Manager(){
		cout<<"Parameterless constructor of Manager"<<endl;
	}
};

int main(){

	Person *ob= new Manager();
	ob->disp();

	return 0;
}
