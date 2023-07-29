#include<stdio.h>

int power(int c){
    int i,p=1;
    for(i=1;i<=c;i++){
        p=p*10;
    }
    return p;
}
int main(){
    int X,Y,Z,c=0,Y1,p;
    printf("Enter two numbers ");
    scanf("%d %d",&X,&Y);
    Y1=Y;
    while(Y1!=0){
         c++;
         Y1=Y1/10;
    }
    p=power(c);
    Z=X*p+Y;
    printf("Appended Number = %d \n",Z);
    return 0;
}
