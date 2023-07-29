#include <stdio.h>

void pattern1(int n){

	int i,j;

	for(i=1;i<=n;i++){

		for(j=1;j<=n-i;j++){
			printf(" ");
		}

		for(j=i;j>=1;j--){
			printf("%d",j);
		}

		printf("\n");

	}


}
void pattern2(int n){

    int i,j,k;
    if(n%2==0)
    n=n/2 + 1;
    else
    n=(n+1)/2;
    for(i=0;i<n;i++){
        for(j=1;j<n-i;j++){
            printf(" ");
        }
        for(k=1;k<=2*i+1;k++){
            if(k==1 || k==2*i+1){
                printf("+");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(i=n-1;i>0;i--){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(k=1;k<=2*i+1;k++){
            if(k==1 || k==2*i-1){
                printf("+");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}




int main(){

	int n;

	printf("Enter the value of n : ");
	scanf("%d",&n);

	pattern1(n);
	pattern2(n);
}
