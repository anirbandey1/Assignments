#include <stdio.h>

void itoa(int n,char s[]){
    int i,sign;

    if((sign=n)<0) n= -n;

    i=0;
    do{
        s[i++]=n%10+'0';
    }while((n/=10)>0);

    if(sign<0) s[i++]='-';
    s[i]='\0';

    int j,temp;
    for(j=i-1,i=0;i<j;i++,j--){
        temp=s[i],s[i]=s[j],s[j]=temp;
    }
}
int main(){

    int n;
    char s[100];
    printf("Enter the NUMBER : ");
    scanf("%d",&n);
    itoa(n,s);
    printf("The NUMBER in STRING : %s \n",s);

    return 0;
}
