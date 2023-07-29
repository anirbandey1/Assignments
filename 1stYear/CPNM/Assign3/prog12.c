#include <stdio.h>

int main(){

    int n;
    printf("Enter the number : ");
    scanf("%d",&n);

    int i=1;
    for(i=1;i<=10;i++){
        printf(" %d x %d = %d \n",n,i,n*i);
    }

    return 0;
}
