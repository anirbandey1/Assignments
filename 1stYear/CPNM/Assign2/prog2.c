#include <stdio.h>
#define PI 3.1415
int main(){

    float l,b,r;
    printf("Length of Rectangle = ");
    scanf("%f",&l);
    printf("Breadth of Rectangle = ");
    scanf("%f",&b);
    printf("Radius of Circle = ");
    scanf("%f",&r);

    float ar,pr,ac,cc;
    ar=l*b, pr=2*(l+b);
    ac=PI*r*r, cc=2*PI*r;

    printf("Area of Rectangle = %0.2f \n",ar);
    printf("Perimeter of Rectangle = %0.2f \n",pr);
    printf("Area of Circle = %0.2f \n",ac);
    printf("Circumference of Circle = %0.2f \n",cc);
    
    return 0;
}
