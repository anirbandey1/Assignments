#include <stdio.h>
#include <math.h>

int sumOfFactor(int n){

    int s=0;float l=sqrt(n);

    int i=1;
    for(i=1;i<=l;i++){
        if(n%i==0){
            if(n==i*i)
                s+= i;
            else
                s+= i+ n/i;
        }
    }

    return s;
}

int main(){

    int n;
    printf("Enter the value of N : ");
    scanf("%d",&n);

    int i=1,s=0;
    for(i=1;i<=n;i++)
         s+=sumOfFactor(i);

    printf("Sum of Series : %d \n",s);

    return 0;
}
