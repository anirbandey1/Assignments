#include <iostream>
#include <cstring>
using namespace std;

class GradeCard{
	char *name;
	int roll;
	int sem;
	int sub_size;
	char **subject;
	int *marks;

public :

/*
GradeCard(){
	name=NULL:
	roll=0;
	sem=0;
	sub_size=0;
	subject=NULL;
	marks=NULL;	
}
*/

GradeCard(char *name,int roll,int sem,int sub_size,char **subject,int *marks)
{
	strcpy(this->name,name);
	this->roll=roll;
	this->sem=sem;
	this->sub_size;
	
	this->subject=new char*[sub_size];
	this->marks=new int[sub_size];
	
	for(int i=0;i<sub_size;i++)
	{
		strcpy(this->subject[i],subject[i]);
		this->marks[i]=marks[i];
	}
}

void print(){

	cout<<"Name : "<<name<<endl;
	cout<<"Roll : "<<roll<<endl;
	cout<<"Semester : "<<sem<<endl;
	cout<<"No. of Subjects : "<<sub_size<<endl;
	
	for(int i=0;i<sub_size;i++)
	{
		cout<<"Subject "<<i+1<<" : "<<subject[i]<<" ,  Marks : "<<marks[i]<<endl; 

	}
}

}; //class


int main(){

	char *name="eg_name";
	int roll=1;
	int sem=3;
	int sub_size=2;
	char **subject=new char*[sub_size];
	for(int i=0;i<sub_size;i++)
	{
		subject[i]=new char[20];
	}
	int *marks=new int[sub_size];
	
	subject[0]="Maths";
	marks[0]=-5;

	subject[1]="Chems";
	marks[1]=-100;

	GradeCard ob(name,roll,sem,sub_size,subject,marks);
	ob.print();



}


