#include <iostream>
#define wsize 20
using namespace std;

class Person{
	char *name;
	int age;
	int height;

public:
Person(char *a,int b,int c){
	a=new char[wsize];
	strcpy(name,a);
	age=b;
	height=c
}

void printDetails(){
	cout<<name<<endl;
	

}
};

class Student:Person(){




}
