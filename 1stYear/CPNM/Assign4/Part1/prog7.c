#include <stdio.h>

void initials(char init[],char name[]){

    int i=1,j=1;
    init[0]=name[0];
    
    for(i=1;name[i]!='\0';i++){
        if(name[i-1]==' '){
            init[j++]=name[i];
        }    
    }
    init[j]='\0';
}

int main(){

    char name[100],init[100];
    printf("Enter the STRING : ");
    scanf("%[^\n]",name);

    initials(init,name);
    printf("INITIALS : %s \n",init);   
    return 0;
}
