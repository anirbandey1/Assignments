#include <stdio.h>

int squareSum(int n){

	int s=0,d=0;

	while(n){
		d=n%10;
		s+=d*d;
		n/=10;
	}

	return s;

}

int happy(int n){

	int i=0;
	for(i=0;i<100;i++){
	
		if(n==1) {
			return 1;
		}
		else{
			n=squareSum(n);
		}
	}

	return 0;

}

int main(){
	
	int i=0,c=0;

	for(i=0,c=0;c<=10;i++){

		if(happy(i)){
			printf("%d \n",i);
			c++;
		}
	}
}



