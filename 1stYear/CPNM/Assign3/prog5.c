#include <stdio.h>

int main(){

    int n,sum=0;
    printf("Enter the Number of Terms of Series : ");
    scanf("%d",&n);

    int i=1;
    for(i=1;i<=n;i++){
        sum+=i*(i+1);
    }
    
    printf("The Sum Of Series is : %d \n",sum);   

    return 0;
}
