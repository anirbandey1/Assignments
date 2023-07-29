#include <iostream>
using namespace std;

// Stack with necessary Exception Handling

class Stack{
	int capacity;
	int size;
	int *arr;
public:
	Stack(int cap){
		if(cap<=0){
			throw "Capcity of Stack is less than or equal to zero";
		}

		capacity=cap;
		size=0;
		arr = new int [capacity];
	}

	void push(int data){
		if(size==capacity){
			throw "Stack Overflow";
		}	

		arr[size++]=data;


	}

	int pop(){
		if(size==0){
			throw "Stack Underflow";
		}
		
		return arr[--size];
	}

	void display(){

		if(size==0){
			cout<<"Stack is empty"<<endl;
		}

		cout<<"STACK : ";
		for(int i= size-1;i>=0;i--){
			cout<<arr[i]<<" ";
		}
		cout<<endl;

	}




};


int main(){

	int data;

	try{
		Stack st(10);
	//	data = st.pop();
	
		st.push(3);
		st.display();

		st.push(5);
		st.display();

	
		data = st.pop();
		st.display();

		data = st.pop();
		st.display(); 	
	
		data = st.pop();
		st.display();
	
		data = st.pop();
		st.display(); 	

	}catch(const char* str){
		cout<<"Error : "<< str <<endl;
	}

	return 0;

}
