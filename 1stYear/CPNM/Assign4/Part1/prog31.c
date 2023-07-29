#include <stdio.h>

int atoi(char s[]){
    int i=0,n=0;
    for(i=0;s[i]>='0'&&s[i]<='9';i++){
        n= n*10 + (s[i]-'0');
    }
    return n;
}
int main(int argc ,char *argv[]){

    int i=0,sum=0;

    for(i=1;i<=argc;i++){
        sum+=atoi(argv[i]);
    }

    printf("The SUM of the %d numbers is %d \n",argc-1,sum);
    return 0;
}
