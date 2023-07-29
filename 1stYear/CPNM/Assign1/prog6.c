#include <stdio.h>
#include <string.h>

void revStr(char s[ ])
{

	int len=strlen(s);

	int i,j,temp;

	for(i=0,j=len-1;i<j;i++,j--)
		temp=s[i],s[i]=s[j],s[j]=temp;


}

int val(char c)
{

	if(c>='0' && c<='9')
		return (int)c-'0';
	else 
		return (int)c-'A'+10;
}

char unval(int n){
	
	if(n>=0 && n<=9)
		return n+'0';
	else
		return n-10+'A';

}

int toDec(char num[],int base){

	int len,power,res;
	len=strlen(num);
	power=1;
	res=0;

	int i=0;
	for(i=len-1;i>=0;i--)
	{
		if(val(num[i])>=base){
			printf("INVALID INPUT");
			return -1;

		}

		res+=val(num[i])*power;
		power*=base;

	}

	return res;

}

char * fromDec(char ans[],int base,int num){

	int i=0;
	
	while(num>0){
		ans[i++]=unval(num%base);
		num/=base;
	}

	ans[i]='\0';
	revStr(ans);
	
	return ans;

}

int main(){

	
	char from,to;
	int basefrom,baseto;
	int dec;
	from=to=dec=-1;
	basefrom=baseto=-1;
	char num[9],ans[9];

	printf("Enter the base of the number \n");
	printf("Press B for Binary \n");
        printf("Press O for Octal \n");
        printf("Press D for Decimal \n");
        printf("Press H for Hexadecimal \n");
        printf("Enter you choice : ");
	scanf("%c",&from);
	
	switch(from){
	
		case 'B': basefrom=2;
			   break;
		case 'O': basefrom=8;
			   break;
		case 'D': basefrom=10;
			   break;
		case 'H': basefrom=16;
			   break;
	
		default:  printf("INVALID INPUT \n");
			  return 0;
			   break;
	
	}
	
	if(!(from=='B'||from=='O'||from=='D'||from=='H')){
		printf("INVALID INPUT \n");
		return 0;	
	}

	printf("Enter the number : ");
	scanf("%s",num);

	dec=toDec(num,basefrom);
	if(dec==-1){
		return 0;
	}
	
	printf("To what base do you want to convert this number \n");
	printf("Press B for Binary \n");
	printf("Press O for Octal \n");
	printf("Press D for Decimal \n");
	printf("Press B for Hexadecimal \n");
	printf("Enter you choice : ");
	scanf("%c",&to);
	scanf("%c",&to);

	switch(to){
	
		case 'B': baseto=2;
			   break;
		case 'O': baseto=8;
			   break;
		case 'D': baseto=10;
			   break;
		case 'H': baseto=16;
			   break;
	
		default:  printf("INVALID INPUT \n");
			  return 0;
			   break;
	
	}
	if(!(to=='B'||to=='O'||to=='D'||to=='H')){
                printf("INVALID INPUT \n");
                return 0;       
        }

	printf("Converted number is : %s \n",fromDec(ans,baseto,dec));	
		

	return 0;
}
