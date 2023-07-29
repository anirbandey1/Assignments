#include<stdio.h>
#include<math.h>

#define esp 0.001
#define F(x) ((x)*(x)*(x)-(x)-1)

void bisec(){
     int i=0;
     float x0,x1,x2,f0,f1,f2;
     printf("Enter the end points of domain\n");
     scanf("%f%f",&x0,&x1);
     do{
        x2=(x0+x1)/2;
        f0=F(x0);
        f1=F(x1);
        f2=F(x2);
        printf("Root after %d th iteration =%f\n",i,x2);
        if (f0*f2<0)
            x1=x2;
        else
            x0=x2;
        i++;    
     }while(fabs(f2)>esp);
     printf("Final root=%f\n",x2);
}

void regula(){
     int i=0;
     float x0,x1,x2,f0,f1,f2;
     printf("Enter the end points of domain\n");
     scanf("%f%f",&x0,&x1);
     do{
        f0=F(x0);
        f1=F(x1);
        x2=x0-((f0*(x1-x0))/(f1-f0));
        f2=F(x2);
        printf("Root after %d th iteration=%f\n",i,x2);
        if (f0*f2<0)
            x1=x2;
        else
            x0=x2;
        i++;    
     }while(fabs(f2)>esp);
     printf("Final root=%f\n",x2);
}

void newton(){
     int i=0;
     float x1,x2=0,t,f,fd;
     printf("Enter the initial point\n");
     scanf("%f",&x1);
     do{
        f=F(x1);
        fd=3*x1*x1-x1;
        t=x2;
        x2=x1-f/fd;
        x1=x2;
        printf("Root after %d th iteration=%f\n",i,x2);
        i++;
     }while(fabs(t-x1)>=0.0001);
     printf("Final root=%f\n",x2);    
}

int main(){
    int op;
    printf("***Menu***\n");
    printf("1.Find roots using bisection method\n");
    printf("2.Find roots using Regula Falsi method\n");
    printf("3.Find roots using Newton-Raphson method\n");
    printf("Enter option ");
    scanf("%d",&op);
    switch(op){
              case 1:bisec();
                     break;
              case 2:regula();
                     break;
              case 3:newton();
                     break;
              default:printf("Invalid option!Enter again");                   
    }
    return 0;
}


