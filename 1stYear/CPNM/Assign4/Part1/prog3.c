#include <stdio.h>

int sumOfDigit(int n){

    if(n==0)
        return 0;
    else
        return n%10 + sumOfDigit(n/10);
}

int main(){

    int a;
    printf("Enter the Number : ");
    scanf("%d",&a);

    printf("SUM OF DIGITS : %d \n",sumOfDigit(a));
    return 0;
}
