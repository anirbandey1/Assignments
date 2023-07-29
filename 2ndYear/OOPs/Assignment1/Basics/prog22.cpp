#include <iostream>
#include <stdlib.h>
using namespace std;

class IntArray{
	int n;
	int *a;

public:
IntArray(){
	n=0;
	a=NULL;
}
IntArray(int sz){
	n=sz;
	a=new int[n];
}
/*
IntArray(const IntArray &arr){
	n=arr.n;
	free(a);
	a=new int[n];
	
	for(int i=0;i<n;i++)
	{
		a[i]=arr.a[i];
	}
}
*/

void input(){
	cout<<"Enter the Size of Array : ";
	cin>>n;
	a=new int[n];
	cout<<"Enter the Array : ";

	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
}

void print(){
	// cout<<"Array of size "<<n<<" : ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void reverse(){

	for(int i=0,j=n-1;i<j;i++,j--)
	{
		swap(a[i],a[j]);
	}
}

void sort(){
	for(int i=0;i<n;i++)
	{
		int pos=i;
		for(int j=i+1;j<n;j++)
		{

			if(a[j]<a[pos])
				pos=j;
		}
		swap(a[i],a[pos]);
	}
}
IntArray operator + (const IntArray &arr2){
	int  maxi= n>arr2.n ? n : arr2.n;
	IntArray arr3;
	arr3.n=maxi;
	arr3.a=new int[arr3.n];
	
	for(int i=0;i<arr3.n;i++)
	{
		int el=0;
		if(i<n)el+=a[i];
		if(i<arr2.n)el+=arr2.a[i];

		arr3.a[i]=el;
	}

	return arr3;
}

};

void swap(int &x,int &y){
	int t=x;
	x=y;
	y=t;
}
int main(){

	IntArray arr1,arr2;
	cout<<"First array"<<endl;
	arr1.input();

	cout<<"Original Array : ";
	arr1.print();

	arr2=IntArray(arr1);
	
	cout<<"Duplicate Array : ";
	arr2.print();


	arr2.reverse();
	cout<<"Reverse Array : ";
	arr2.print();


	arr2.sort();
	cout<<"Sorted Array : ";
	arr2.print();	

	IntArray arr3=arr1+arr2;
	cout<<"Addition of original array and sorted array  : "<<endl;
	cout<<"Sum Array : ";
	arr3.print();
	
	
	return 0;

}
