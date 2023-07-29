#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

class State{
public:
	string name;
	int eng;	//engineering college
	int med;	//medical college
	int mng;	//management college
	int uni;


	State(){
		name="";
		eng=med=mng=uni=0;
	}
	

	int total(){
		return eng+med+mng+uni;
	}	
	
	void display(){
		cout<<"Name of State : "<<name<<endl;
		cout<<"No. of Engineering colleges : "<<eng<<endl;
                cout<<"No. of Medical colleges : "<<med<<endl;
                cout<<"No. of Management colleges : "<<mng<<endl;
                cout<<"No. of Universities : "<<uni<<endl;
	}

	State* highest(State *states,int n){
		int maxi=states[0].total();
		State *ptr=&states[0];
		for(int i=0;i<n;i++)
		{
			if(states[i].total()>maxi)
			{
				maxi=states[i].total();
				ptr=&states[i];
			}
		}
		return ptr;
	}


};


int main(){

	int n;
	cout<<"Enter number of states : ";
	cin>>n;
	
	State *states=(State*)malloc(n*sizeof(State));
	for(int i=0;i<n;i++)
	{
		cout<<"Enter details of state "<<(i+1)<<endl;
		cout<<"Name : ";
		getline(states[i].name);
		cout<<"No. of Engineering colleges : ";
		cin>>states[i].eng;
		cout<<"No. of Medical colleges : ";
                cin>>states[i].med;
		cout<<"No. of Management colleges : ";
                cin>>states[i].mng;
		cout<<"No. of Universities : ";
                cin>>states[i].uni;
	}

	states[0].display();


	return 0;
}
