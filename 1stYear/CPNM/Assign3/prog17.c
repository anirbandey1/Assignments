#include <stdio.h>

int fib(int n){

    if(n<=1)
        return 0;
    else if(n==2)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}
int main(){

    int t;
    printf("Enter the Number of Terms : ");
    scanf("%d",&t);

    int i=1;
    for(i=1;i<=t;i++){
        printf("%d ",fib(i));
    }
    printf("\n\n");

    return 0;
}
