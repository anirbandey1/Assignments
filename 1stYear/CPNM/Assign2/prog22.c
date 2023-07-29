#include <stdio.h>

int main(){

    char ch;
    printf("Enter the Character : ");
    scanf("%c",&ch);

    if(ch>='0' && ch<='9')
        printf("%c is a DIGIT \n",ch);
    else if(ch>='a' && ch<='z')
        printf("%c is a SMALL LETTER \n",ch);
    else if(ch>='A' && ch<='Z')
        printf("%c is a CAPITAL LETTER \n",ch);
    else
        printf("%c is a SPECIAL SYMBOL \n",ch);

    return 0;
}
