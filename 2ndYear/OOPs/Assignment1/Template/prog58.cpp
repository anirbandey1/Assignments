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


template<class T>
class Stack{
	int capacity;
	int size;
	T* arr;
public:
	Stack(int cap){
		capacity=cap;
		size=0;
		arr = new T[cap];

	}

	void push(T data){

		if(size==capacity){
			throw "Stack is Full";
		}

		arr[size++]=data;
	}

	T pop(){
		if(size==0){
			throw "Stack is Empty ";
		}

		return arr[--size];
	}

	int getSize() const{
		return this->size;
	}

	int getCapacity() const{
		return this->capacity;
	}

	void display() const{
		if(size==0){
			cout<<"Stack is Empty : Nothing to show"<<endl;
		}

		cout<<"STACK : ";
		for(int i=size-1;i>=0;i--)
		{
			cout<<arr[i];
			if(i!=0){
				cout<<", ";
			}
		}
		cout<<endl;
	}

};


int main(){
	try{

		//Stack contains real integers
		Stack<int>st1(10);

		st1.display();

		for(int i=0;i<5;i++){
			st1.push(i-4);
			st1.display();
		}

		for(int i=0;i<5;i++){
			st1.pop();
			st1.display();
		}

		
		//Stack st2 contains complex numbers
		Stack<Complex> st2(15);
		st2.display();

		for(int i=0;i<5;i++)
		{
			st2.push(Complex(i,(i+2)%3));
			st2.display();

		}	
		
		for(int i=0;i<6;i++)
		{
			st2.pop();
			st2.display();

		}
	
	}catch (const char *error){
		cout<<"Error : "<<error;
	}

	return 0;
}

