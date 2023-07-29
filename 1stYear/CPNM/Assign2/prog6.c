#include <stdio.h>

int max(int a,int b,int c){

    a= a>b?a:b;
    a= a>c?a:c;

    return a;
}
int min(int a,int b,int c){

    a= a<b?a:b;
    a= a<c?a:c;

    return a;
}
int main(){

    int a,b,c;
    printf("Enter thre numbers : ");
    scanf("%d %d %d",&a,&b,&c);
    printf("Maximum = %d \n",max(a,b,c));
    printf("Minimum = %d \n",min(a,b,c));
    return 0;
}
