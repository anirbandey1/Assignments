#include <stdio.h>
#include <stdlib.h>

int main(){
	system("clear");
	int size,i,temp;
	printf("Enter size of array ");
	scanf("%d",&size);
	int *arr=(int*)malloc(size*sizeof(int));
	printf("Enter the elements of the array \n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<size/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[size-1-i];
		arr[size-1-i]=temp;
	}
	printf("The reversed array is : \n");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
