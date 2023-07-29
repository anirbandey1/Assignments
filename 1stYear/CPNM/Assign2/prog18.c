#include <stdio.h>


int isLeap(int n){

    if(n%400==0 ||(n%4==0 &&n%100!=0))
        return 1;
    else
        return 0;

}


int main(){

    int y;
    printf("Enter the year : ");
    scanf("%d",&y);

    if(isLeap(y)){
        printf("Leap Year \n");
    }
    else{
        printf("Non-Leap Year \n");
    }

    return 0;
}
