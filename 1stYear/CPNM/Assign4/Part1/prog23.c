#include <stdio.h>
#include <stdlib.h>

int main(){

    int n,*A;
    printf("Enter the LENGTH of the array : ");
    scanf("%d",&n);
    A=(int *)malloc(n*sizeof(int));
    printf("Enter %d elements : ",n);

    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",A+i);
    }
    printf("The ARRAY is : ");
    int sum=0;
    for(i=0;i<n;i++){
        sum+=*(A+i);
        printf("%d ",*(A+i));
    }
    printf("\n");
    printf("SUM = %d \n",sum);

}
