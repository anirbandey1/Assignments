#include <stdio.h>

int main(){

    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);

    printf("Numbers divisible by %d are : \n",n);

    int i;
    for(i=n;i<=100;i+=n)
            printf("%d ",i);

    printf("\n");
            
    return 0;
}
