#include <iostream>
using namespace std;

int  fact(const int n){

	int x=1;
	if(n<=1)return 1;

	for(int i=2;i<=n;i++)
	{
		x*=i;
	}
	return x;

}

int main(){

	int n;
	cout<<"Enter a number : ";
	cin>>n;
	cout<<n<<"! = "<<fact(n)<<endl;

	return 0;
}
