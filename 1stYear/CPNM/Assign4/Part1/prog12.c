#include <stdio.h>

int atoi(char s[]){

    int i=0,n=0;
    for(i=0;s[i]>='0'&&s[i]<='9';i++){
        n=n*10+(s[i]-'0');
    }
    return n;
}
int main(){

    char s[100];
    int n=0;
    printf("Enter the NUMBER in STRING format : ");
    scanf("%s",s);
    n=atoi(s);
    printf("The NUMBER is : %d \n",n);

    return 0;
}
