#include <stdio.h>

void squeeze(char s[],int c){
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++){
        if(s[i]!=c) s[j++]=s[i];
    }
    s[j]='\0';
}
int main(){

    char s[100],ch;

    printf("Enter the STRING : ");
    scanf("%s",s);
    scanf("%c",&ch);
    printf("Enter the CHARACTER : ");
    scanf("%c",&ch);

    squeeze(s,ch);
    printf("SQUEEZED STRING : %s \n",s);

    return 0;
}
