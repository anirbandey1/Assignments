#include <stdio.h>
#include <math.h>

int main(){

    float h,k,r,x,y,dist;
    printf("The X and Y coordinates of circle are : ");
    scanf("%f %f",&h,&k);
    printf("The RADIUS of circle is : ");
    scanf("%f",&r);

    printf("The X and Y coordinates of POINT are : ");
    scanf("%f %f",&x,&y);

    dist=sqrt(pow(x-h,2)+pow(y-k,2));
    
    if(dist==r)
        printf("Point lies ON the cirlce \n");
    else if(dist<r)
        printf("Point lies INSIDE the cirlce \n");
    else
        printf("Point lies OUTSIDE the cirlce \n");
    
    return 0;
}
