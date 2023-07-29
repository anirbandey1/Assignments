#include <stdio.h>
#define n 100
int main(){

    int a[n]={0};

    printf("Enter  %d elements  : \n",n);
    
    int i=0;
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    printf("\n");

    int pos=0,neg=0,z=0;
    for(i=0;i<n;i++){
        if(a[i]==0)
            z++;
        else if(a[i]>0)
            pos++;
        else
            neg++;
    }

    printf("Positives : %d \n",pos);
    printf("Negatives : %d \n",neg);
    printf("Zeroes : %d \n",z);

    return 0;
}
