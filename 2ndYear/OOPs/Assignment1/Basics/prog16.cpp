#include <iostream>
using namespace std;

void print(int vec[],int n){
	cout<<"Array : ";
	for(int i=0;i<n;i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

void print(int mat[3][3],int n,int m){
	cout<<"Matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int vec[]={3,6,4,1};
	int mat[][3]=
	{{1,2,3},
	{4,5,6},
	{7,8,9}};

	print(vec,4);
	print(mat,3,3);

	return 0;
}
