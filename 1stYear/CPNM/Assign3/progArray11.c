#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

        int n, *A;

        printf("Enter the LENGTH of array = ");
        scanf("%d",&n);

        A= (int *)calloc(n,sizeof(int));

        printf("Enter the %d elements : ",n);
        int i;
        for(i=0;i<n;i++)
        {
                scanf("%d",A+i);
        }

        float s=0.0,m=0.0;
        for(i=0;i<n;i++)
        {
                m+=A[i];
        }
        m/=n;

        for(i=0;i<n;i++)
        {
                s+=(A[i]-m)*(A[i]-m);
        }
        s/=n;
        s=sqrt(s);

        printf("STANDARD DEVIATION = %0.3f \n",s);

        return 0;
}
