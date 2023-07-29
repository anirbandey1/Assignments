#include <stdio.h>
#define MAX 20

void fillArray(int a[],int n){
	printf("Enter %d elements : ",n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void printArray(int a[],int n){
	printf("ARRAY : ");
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void del(int a[],int n,int k){
	int i;
	for(i=k;i<n-1;i++){
		a[i]=a[i+1];
	}
}
int main(){

	int A[MAX];
	int n=10;
	fillArray(A,n);
	printArray(A,n);
	del(A,n,3);
	printf("Delete 3rd index \n");
	n--;
	printArray(A,n);
	del(A,n,6);
	printf("Delete 6");
	n--;
	printArray(A,n);
	printf("5th element is %d \n",A[5]);

	return 0;
}



