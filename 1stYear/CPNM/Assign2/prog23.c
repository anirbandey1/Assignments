#include <stdio.h>

int main(){

    int seci,h,m,s;

    printf("Enter time in SECONDS : ");
    scanf("%d",&seci);

    h=seci/3600;
    m=(seci-h*3600)/60;
    s=seci%60;

    printf("%d SECONDS is equivalent to : \n",seci);
    printf("%d HOURS %d MINUTES %d SECONDS \n",h,m,s);

    return 0;
}
