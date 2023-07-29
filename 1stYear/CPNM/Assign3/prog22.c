#include <stdio.h>
#define w 10
int main(){

    int i=0;
    printf("ASCII values and their Equivalent Characters :\n");
    while(i<=255){
        
        printf("%d -> %c ; ",i,i);
        i++;
        
        if(i%w==0)
            printf("\n");
    }
    printf("\n");
    return 0;
}
