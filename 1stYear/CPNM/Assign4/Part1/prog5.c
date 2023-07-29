#include <stdio.h>

int len(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}

int main(){

    char s[100];
    printf("Enter the STRING : ");
    scanf("%s",s);

    printf("LENGTH OF STRING : %d \n",len(s));

    return 0;
}
