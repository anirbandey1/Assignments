#include <iostream>
#include <stdlib.h
using namespace std;

class Table{
	int r,c;

	int **a;
public:
	Table(int row,int col){
		r=row;
		c=col;

		a=(**int)malloc(r*sizeof(int*));
		for(int i=0;i<r;i++)
		{
\			a[i]=(int*)calloc(c,sizeof(int));
		}
	}


	int& operator[][](int,int);

	friend ostream & operator << (ostream &os,const Table &t);
	

};


ostream & operator << (ostream &os,const Table  &t){
	
	os<<endl;
	for(int i=0;i<t->r;i++)
	{
		for(int j=0;j<c;j++)
		{
			os<<t[i][j]<<" ";
		}
		os<<endl;
	}
	os<<endl;
	//os<<ob.x;
	return os;
}


int& operator[][](int ind1,int ind2){

	if(ind1>=r || ind1<0 || ind2>=c ||ind2<0){
		cout<<"The indexes specified are out of bounds of the table"<<endl;
		exit(0);
	}

	return a[ind1][ind2];

}



int main(){

	Table t(4,5),t1(4,5);
	cin>>t;
	t[0][0]=5;
	int x=t[2][3];
	t1=t;
	cout<<t<<"\n"<<t1;


	return 0;
}
