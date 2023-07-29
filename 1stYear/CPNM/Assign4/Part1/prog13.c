#include <stdio.h>

int len(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}

int palindrome(char s[],int n){
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--){
        if(s[i]!=s[j])
            return 0;
    }

    return 1;
}

int main(){

    char s[100];
    int l,fl;
    printf("Enter the STRING : ");
    scanf("%s",s);

    l=len(s);
    fl=palindrome(s,l);

    if(fl)
        printf("Yes, it is a Palindrome \n"); 
    else
        printf("No, it is not a Palindrome \n");
          
    return 0;
}
