#include <stdio.h>

int len(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}

void reverse(char s[],int n){
    int i,j,temp;
    for(i=0,j=n-1;i<j;i++,j--){
        temp=s[i],s[i]=s[j],s[j]=temp;
    }
}

int main(){

    char s[100];
    int l;
    printf("Enter the STRING : ");
    scanf("%s",s);

    l=len(s);
    reverse(s,l);

    printf("REVERSE of the STRING : %s \n",s);   
    return 0;
}
