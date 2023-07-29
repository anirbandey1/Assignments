#include <stdio.h>

int max(int a,int b,int c){
	int maxi=a;
	maxi=b>maxi?b:maxi;
	maxi=c>maxi?c:maxi;
	return maxi;
}
int max(int *A,int n){
	int maxi=A[0];
	for(int i=0;i<n;i++){
		maxi= A[i]>maxi?A[i]:maxi;
	}
	return maxi;
}
int main(){
	int a=3,b=5,c=4;
	int arr[]={6,2,1,5,7,2};
	int n=6;

	int max1=max(a,b,c);
	int max2=max(arr,n);

	printf("Max of %d, %d, %d is %d \n",a,b,c,max1);
	printf("Max of Array is %d \n",max2);

	return 0;
}

