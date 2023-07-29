#include <stdio.h>

void Capitalize(char s[]){

    int i=0;
    for(i=0;s[i]!='\0';i++){

        if(s[i]>='a'&&s[i]<='z')
            s[i]-=32;
    }
}
int main(){

    char s[100];
    printf("Enter the STRING : ");
    scanf("%[^\n]s",s);

    Capitalize(s);
    printf("Capiitalized String : ");   
    puts(s);
    printf("\n");
    return 0;
}
