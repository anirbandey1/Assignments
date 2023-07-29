#include <stdio.h>

int isPrime(int n){

    int c=0,i=2;
    for(i=2;i<n;i++){

        if(n%i==0){
            c++;
        }
    }

    if(c==0)
        return 1;
    else 
        return 0;

}

int main(){

    int i=1;
    for(i=2;i<=100;i++){
        if(isPrime(i)){
            printf("%d ",i);
        }
    }
	
    printf("\n");

    return 0;
}
