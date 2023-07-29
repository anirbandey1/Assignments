#include<stdio.h>
#include<stdlib.h>

float forward_diff(float **matrix,int n,float x){
    float diff = matrix[1][0]-matrix[0][0];     
    for (int i = 1; i < n-1; i++)
    {
        if (matrix[i+1][0]-matrix[i][0]!=diff)
        {
            printf("\n-----------------------------------------------------------------------\n");
            printf("\t\tIntervals of x are not equal\n");
            printf("This problem can't be solved using Newton's Forward Difference Method\n");
            printf("------------------------------------------------------------------------\n");
            exit(0);
        }
    }

    for (int j = 2; j < n+1 ; j++)
    {
        for (int i = 0; i < n-j+1; i++)
        {
            matrix[i][j] = matrix [i+1][j-1]-matrix[i][j-1];
        }
    }
    printf("\n\t Difference Table : \n");        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1-i; j++)
        {
            printf("%.2f   ",matrix[i][j]);
        }
        printf("\n");
    }
    

    float sum,a,h,u,ui;
    int fact=1;
    a = matrix[0][0];
    h = matrix[1][0] - matrix[0][0];
    u = ui = (x-a)/h;
    
    sum = matrix[0][1];
    for (int i = 2; i < n+1; i++)
    {
        sum += (ui*matrix[0][i])/fact;
        ui *= u-i+1;
        fact *= i;
    }
    return sum;
}

float backward_diff(float **matrix,int n,float x){
    float diff = matrix[1][0]-matrix[0][0];     
    for (int i = 1; i < n-1; i++)
    {
        if (matrix[i+1][0]-matrix[i][0]!=diff)
        {
            printf("\n-----------------------------------------------------------------------\n");
            printf("\t\tIntervals of x are not equal\n");
            printf("This problem can't be solved using Newton's Backward Difference Method\n");
            printf("------------------------------------------------------------------------\n");
            exit(0);
        }
    }

    for (int j = 2; j < n+1 ; j++)
    {
        for (int i = n-j; i >=0; i--)
        {
            matrix[i][j] = matrix [i+1][j-1]-matrix[i][j-1];
        }
    }
    printf("\n\t Difference Table : \n");        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1-i; j++)
        {
            printf("%.2f   ",matrix[i][j]);
        }
        printf("\n");
    }
    
   

    float sum,a,h,u,ui;
    int fact=1;
    a = matrix[n-1][0];
    h = matrix[1][0] - matrix[0][0];
    u = ui = (x-a)/h;
    
    sum = matrix[n-1][1];
    int i,j;
    for (i = n-2, j=2; i >=0; i--,j++)
    {
        sum += (ui*matrix[i][j])/fact;
        ui *= u+j-1;
        fact *= j;
    }

    return sum;
}

float lagrange_interpolation(float **matrix,int n,float x){
    float X[n],Y[n];
    for (int i = 0; i < n; i++)
    {
        X[i]=matrix[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        Y[i]=matrix[i][1];
    }
    
    float temp,sum=0;
    for (int i = 0; i < n; i++)
    {
        temp = 1;
        for (int j = 0; j < n; j++)
        {
            if (i!=j)
            {
                temp *= (x-X[j])/(X[i]-X[j]);
            }
        }
        sum += temp * Y[i];
    }
    return sum;
}

int main(){
    int n;  float x,y;
    printf("\n\t : Interpolation : \n\n");
    printf("Enter the no. of x : ");
    scanf("%d",&n);
    float **matrix = malloc(n*sizeof(float*));
    for (int i = 0; i < n+1; i++)
    {
        matrix[i] = malloc(n+1*sizeof(float));
    }
    
    printf("Enter the values of x : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&matrix[i][0]);
    }
    printf("Enter the values of y i.e. f(x) : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&matrix[i][1]);
    }
    printf("Enter the value of x for which you want to find y : ");
    scanf("%f",&x);
    printf("\nMethods of Interpolation :\n");
    printf("1)Newton's Forward Difference\n2)Newton's Backward Difference\n");
    printf("3)Lagrange's Interpolation\n");
    printf("\t\t\t\tChoose method no. : ");

    int ch;
    scanf("%d",&ch);

    switch(ch){
        case 1:
            y = forward_diff(matrix,n,x);
            break;

        case 2:
            y = backward_diff(matrix,n,x);
            break;
        case 3:
            y = lagrange_interpolation(matrix,n,x);
            break;
        default :
            break;    
    }

    printf("\n-------------------------------------------------\n");
    printf("\t Value of f(%.2f) is : %f \n",x,y);
    printf("-------------------------------------------------\n");
    
    return 0;
}

