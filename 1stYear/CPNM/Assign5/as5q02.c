#include<stdio.h>
#include<math.h>

double func(float x,float c){
      double fx=x*tan(x)-c;
      return fx;
}

double dfunc(float x){
      double sec=1/cos(x);
      double dfx=tan(x)+x*sec*sec;
      return dfx;
}

float bisec(float x0,float x1,float c){
      double f0,f1,f2;
      float x2;
      do{
        x2=(x0+x1)/2;
        f0=func(x0,c);
        f1=func(x1,c);
        f2=func(x2,c);
        if (f0*f2<0)
            x1=x2;
        else
            x0=x2;   
     }while(fabs(f2)>0.001);
     return x2;
}

double newton(float x1,float c){
      double t,x2=0,f,df;
      do{
        f=func(x1,c);
        df=dfunc(x1);
        t=x2;
        x2=x1-f/df;
        x1=x2;
      }while(fabs(t-x1)>=0.0001);
      return x2;
}

int main(){
    float c,f1,f2,s1,s2,t1,t2,r1,r2,r3;
    printf("Enter the constant ");
    scanf("%f",&c);
    printf("Calculation of roots using bisection method\n");
    printf("Enter end points of domain for the first root ");
    scanf("%f%f",&f1,&f2);
    printf("Enter end points of domain for the second root ");
    scanf("%f%f",&s1,&s2);
    printf("Enter end points of domain for the third root ");
    scanf("%f%f",&t1,&t2);  
    printf("The roots are %f %f %f\n",bisec(f1,f2,c),bisec(s1,s2,c),bisec(t1,t2,c));
    printf("Calculation of roots using Newton-Raphson method\n");
    printf("Enter initial point for first root ");
    scanf("%f",&r1);
    printf("Enter initial point for second root ");
    scanf("%f",&r2);  
    printf("Enter initial point for third root ");
    scanf("%f",&r3);
    printf("The roots are %lf %lf %lf\n",newton(r1,c),newton(r2,c),newton(r3,c)); 
    return 0;
}


