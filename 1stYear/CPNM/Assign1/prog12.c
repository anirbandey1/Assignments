#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void inputArray(int *A,int n){

	int i=0;

        for(i=0;i<n;i++){
                scanf("%d",A+i);

        }


}



void printArray(int A[],int n){

	int i=0;

	for(i=0;i<n;i++){
		printf("%d ",A[i]);

	}
	printf("\n");

}
void reverse(int A[],int n){

	int i,j,temp;
	for(i=0,j=n-1;i<j;i++,j--)
		temp=A[i],A[i]=A[j],A[j]=temp;

}

int duplicates(int A[],int n,int B[]){

	int i,j;
	int indexB=0,count=0;
	
	for(i=0;i<n-1;i++){
		
		count=0;
		for(j=i+1;j<n;j++){
			
			if(A[i]==A[j]){
				count++;
			
			}
		
		}
		
		if(count==0){
			B[indexB++]=A[i];	
		}
	}
	

	B[indexB++]=A[n-1];
	
	return indexB;
}


int main(){

	int n,m,*A,*B;

	printf("Enter the length of array : ");
	scanf("%d",&n);

	A=(int *)malloc(n*sizeof(int));
	B=(int *)malloc(n*sizeof(int));
	inputArray(A,n);
	
	m=duplicates(A,n,B);
	
	B=(int *)realloc(B,m*sizeof(int));
	
	reverse(B,m);

	printf("No. of Duplicates : %d \n",n-m);	
	printf("Modified Array is : \n");
	printArray(B,m);


}
