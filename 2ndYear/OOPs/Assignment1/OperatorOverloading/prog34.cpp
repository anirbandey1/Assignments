#include <iostream>
#include <stdlib.h>
using namespace std;

class IntArray{
	int sz;
	int *a;

public:
	IntArray(int size){
		sz=size;
		a=(int*)calloc(sz,sizeof(int));
	}

	int& operator[](int);
	friend ostream & operator <<(ostream &os,const IntArray&ob);

};

ostream & operator << (ostream &os,const IntArray&ob){

	os<<endl;
	for(int i=0;i<ob.sz;i++){
		os<<ob.a[i]<<" ";
	}
	os<<endl;
	return os;
}


int& IntArray::operator[](int ind){
	if(ind<0 || ind>=sz){
		cout<<"Index Out Of Bounds Exception"<<endl;
		exit(0);
	}

	return a[ind];


}
int main(){

	IntArray i(10);
	for(int k=0;k<10;k++){
		i[k]=k;
	}
	cout<<i;


	return 0;
}
