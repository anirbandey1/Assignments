#include <stdio.h>

int main(){

    float F,C;

    printf("Enter Temperature in Farenheit : ");
    scanf("%f",&F);
    C=5*(F-32)/9;
    printf("Temperature in Celsius : %0.2f \n",C);
    return 0;
}
