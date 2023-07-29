#include <stdio.h>

int main(){

    int a[3]={0};
    float avg;

    printf("Enter three numbers : ");
    
    scanf("%d %d %d",a,a+1,a+2);

    avg = ((float) a[0]+a[1]+a[2])/3;
    printf("The average is : %f \n",avg);

    int i=0;
    for(i=0;i<3;i++){
        float num=(float)a[i];
        if(num==avg){
            printf("%d is EQUAL to average \n",a[i]);
        }
        else if(num>=avg){
            printf("%d is ABOVE average \n",a[i]);
        }
        else{
            printf("%d is BELOW average \n",a[i]);
        }
    }

    return 0;
}
